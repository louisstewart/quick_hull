//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_QUICKHULL_H
#define QUICKHULL_QUICKHULL_H

#include "Vector2d.h"
#include "Line2d.h"
#include <vector>

namespace details {
/* *************************************************************************
 * Private Function Definitions
 * *************************************************************************/

    template<typename T>
    inline Vector2d<T> &get_most_extreme(std::vector<Vector2d<T>> &vector, bool (*pFunction)(Vector2d<T>, Vector2d<T>)) {
        Vector2d<T> *a = &vector[0];
        for (int i = 1; i < vector.size(); ++i) {
            // Swap if comparison fails, e.g. if a.x < b.x and we want rightmost, then set a = b.
            if (pFunction(*a, vector[i])) a = &vector[i];
        }
        return *a;
    }

    template<typename T>
    inline Vector2d<T> &get_rightmost_point(std::vector<Vector2d<T>> &vector) {
        if(vector.empty())
            throw std::exception();
        return details::get_most_extreme(vector, [](Vector2d<T> l, Vector2d<T> r) { return l.getX() < r.getX(); });
    }

    template<typename T>
    inline Vector2d<T> &get_leftmost_point(std::vector<Vector2d<T>> &vector) {
        if(vector.empty())
            throw std::exception();
        return details::get_most_extreme(vector, [](Vector2d<T> l, Vector2d<T> r) { return l.getX() > r.getX(); });
    }

    template<typename T>
    inline Vector2d<T>& find_farthest(Vector2d<T> &left, Vector2d<T> &right, std::vector<Vector2d<T>> &vectors) {
        double max_d = 0.0;
        Line2d<T> l(left, right);
        Vector2d<T> *farthest = &vectors[0];
        for (Vector2d<T> &point: vectors) {
            double dist = l.dist(point);
            if (dist >= max_d) {
                farthest = &point;
                max_d = dist;
            }
        }
        return *farthest;
    }

    template<typename T>
    inline std::vector<Vector2d<T>> get_points_ccw(Vector2d<T> &left, Vector2d<T> &right, std::vector<Vector2d<T>> &vectors) {
        std::vector<Vector2d<T>> ccw; // Set of points counter clockwise to line between left-right.
        Line2d<T> line{left, right};
        for (Vector2d<T> &vec: vectors) {
            if (line.relativeCCW(vec) > 0) ccw.push_back(vec);
        }
        return ccw;
    }

    template<typename T>
    inline void findHull(std::vector<Vector2d<T>> &subset, Vector2d<T> &left, Vector2d<T> &right, std::vector<Vector2d<T>> &hull) {
        if (subset.empty()) return;

        Vector2d<T> &C = details::find_farthest(left, right, subset);

        auto it = std::find(hull.begin(), hull.end(), left);
        hull.insert(it + 1, C);

        auto s1 = details::get_points_ccw(left, C, subset);
        auto s2 = details::get_points_ccw(C, right, subset);

        details::findHull(s1, left, C, hull);
        details::findHull(s2, C, right, hull);
    }

}
/**
 * Calculate the convex hull around a set of points, using the QuickHull algorithm.
 * This algo runs in an average case O(Nlog(N)) time for a set of N points.
 *
 * @param vecs vector of Vector2d points in 2D space
 * @return vector of points defining the convex hull around the input points
 */
template<typename T>
inline std::vector<Vector2d<T>> quick_hull(std::vector<Vector2d<T>> vecs) {
    std::vector<Vector2d<T>> hull;

    auto left = details::get_leftmost_point(vecs);
    auto right = details::get_rightmost_point(vecs);

    auto s1 = details::get_points_ccw(left, right, vecs);
    auto s2 = details::get_points_ccw(right, left, vecs);

    hull.push_back(left);
    details::findHull(s1, left, right, hull);
    hull.push_back(right);
    details::findHull(s2, right, left, hull);

    return hull;
}

#endif //QUICKHULL_QUICKHULL_H
