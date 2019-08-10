//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#include <cmath>
#include "Line2d.h"

inline Vector2d Line2d::operator~() {
    return Vector2d{y1 - y2, x2 - x1};
}

inline float Line2d::dist_sq(const Vector2d &point) {
    return dist_sq(point.getX(), point.getY());
}

inline float Line2d::dist_sq(float px, float py) {
    Vector2d AB{px - x1, py - y1}; // point to end of line vector
    Vector2d EF{y1 - y2, x2 - x1}; // orthogonal vector to line

    float dot = AB * EF;
    float len_sq = EF.square();
    return dot * dot / len_sq;
}

inline float Line2d::dist(const Vector2d &point) {
    return std::sqrt(dist_sq(point));
}

inline float Line2d::dist(float px, float py) {
    return std::sqrt(dist_sq(px, py));
}

inline float Line2d::relativeCCW(const Vector2d &point) {
    return relativeCCW(point.getX(), point.getY());
}

inline float Line2d::relativeCCW(float px, float py) {
    if ((x1 == x2 && y1 == y2) || (x1 == px && y1 == py) || (x2 == px && y2 == py))
        return 0; // Coincident points.
    // Translate to the origin.
    auto x = x2 - x1;
    auto y = y2 - y1;
    px -= x1;
    py -= y1;
    double slope2 = y / x;
    double slopep = py / px;
    if (slope2 == slopep || (x == 0 && px == 0))
        return y > 0 // Colinear.
               ? (py < 0 ? -1 : py > y ? 1 : 0)
               : (py > 0 ? -1 : py < y ? 1 : 0);
    if (x >= 0 && slope2 >= 0)
        return px >= 0 // Quadrant 1.
               ? (slope2 > slopep ? 1 : -1)
               : (slope2 < slopep ? 1 : -1);
    if (y > 0)
        return px < 0 // Quadrant 2.
               ? (slope2 > slopep ? 1 : -1)
               : (slope2 < slopep ? 1 : -1);
    if (slope2 >= 0.0)
        return px >= 0 // Quadrant 3.
               ? (slope2 < slopep ? 1 : -1)
               : (slope2 > slopep ? 1 : -1);
    return px < 0 // Quadrant 4.
           ? (slope2 < slopep ? 1 : -1)
           : (slope2 > slopep ? 1 : -1);
}