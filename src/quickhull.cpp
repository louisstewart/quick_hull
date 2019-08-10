//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#include "quickhull.h"
#include "Vector2d.h"
#include "Line2d.h"


/* *************************************************************************
 * Private Function Definitions
 * *************************************************************************/
Vector2d& get_leftmost_point(std::vector<Vector2d>& vector);

Vector2d& get_rightmost_point(std::vector<Vector2d>& vector);

Vector2d& get_most_extreme(std::vector<Vector2d> &vector, bool (*pFunction)(Vector2d, Vector2d));

std::vector<Vector2d> get_points_ccw(Vector2d& vector2d, Vector2d& right, std::vector<Vector2d> vector);

void findHull(std::vector<Vector2d> &subset, Vector2d &left, Vector2d &right, std::vector<Vector2d> &hull);

Vector2d &find_farthest(Vector2d &left, Vector2d &right, std::vector<Vector2d> &vector);

/* *************************************************************************
 *  Begin Algorithm Implementation
 * *************************************************************************/

std::vector<Vector2d> quick_hull(std::vector<Vector2d> vecs) {
    std::vector<Vector2d> hull;

    auto left = get_leftmost_point(vecs);
    auto right = get_rightmost_point(vecs);

    auto s1 = get_points_ccw(left, right, vecs);
    auto s2 = get_points_ccw(right, left, vecs);

    hull.push_back(left);
    findHull(s1, left, right, hull);
    hull.push_back(right);
    findHull(s2, right, left, hull);

    return hull;
}

void findHull(std::vector<Vector2d> &subset, Vector2d &left, Vector2d &right, std::vector<Vector2d> &hull) {
    if (subset.empty()) return;

    Vector2d& C = find_farthest(left, right, subset);

    auto it = std::find(hull.begin(), hull.end(), left);
    hull.insert(it + 1, C);

    auto s1 = get_points_ccw(left, C, subset);
    auto s2 = get_points_ccw(C, right, subset);

    findHull(s1, left, C, hull);
    findHull(s2, C, right, hull);
}

Vector2d& find_farthest(Vector2d &left, Vector2d &right, std::vector<Vector2d> &vectors) {
    float max_d = 0.0;
    Line2d l(left, right);
    Vector2d* farthest = &vectors[0];
    for(Vector2d &point: vectors) {
        float dist = l.dist(point);
        if(dist >= max_d) {
            farthest = &point;
            max_d = dist;
        }
    }
    return *farthest;
}

std::vector<Vector2d> get_points_ccw(Vector2d& left, Vector2d& right, std::vector<Vector2d> vectors) {
    std::vector<Vector2d> ccw; // Set of points counter clockwise to line between left-right.
    Line2d line{left, right};
    for(Vector2d& vec: vectors) {
        if(line.relativeCCW(vec) > 0) ccw.push_back(vec);
    }
    return ccw;
}

Vector2d& get_rightmost_point(std::vector<Vector2d>& vector) {
    assert(!vector.empty());
    return get_most_extreme(vector, [](Vector2d l, Vector2d r){return l.getX() < r.getX();});
}

Vector2d& get_leftmost_point(std::vector<Vector2d>& vector) {
    assert(!vector.empty());
    return get_most_extreme(vector, [](Vector2d l, Vector2d r){return l.getX() > r.getX();});
}

Vector2d& get_most_extreme(std::vector<Vector2d> &vector, bool (*pFunction)(Vector2d, Vector2d)) {
    Vector2d* a = &vector[0];
    for(int i = 1; i < vector.size(); ++i) {
        // Swap if comparison fails, e.g. if a.x < b.x and we want rightmost, then set a = b.
        if(pFunction(*a, vector[i])) a = &vector[i];
    }
    return *a;
}