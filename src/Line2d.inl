//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#include <cmath>
#include "Line2d.h"

template<typename T>
inline Vector2d<T> Line2d<T>::operator~() {
    return Vector2d<T>{y1 - y2, x2 - x1};
}

template<typename T>
inline T Line2d<T>::dist_sq(const Vector2d<T> &point) {
    return dist_sq(point.getX(), point.getY());
}

template<typename T>
inline T Line2d<T>::dist_sq(T px, T py) {
    Vector2d<T> AB{px - x1, py - y1}; // point to end of line vector
    Vector2d<T> EF{y1 - y2, x2 - x1}; // orthogonal vector to line

    T dot = AB * EF;
    T len_sq = EF.square();
    return dot * dot / len_sq;
}

template<typename T>
inline T Line2d<T>::dist(const Vector2d<T> &point) {
    return std::sqrt(dist_sq(point));
}

template<typename T>
inline T Line2d<T>::dist(T px, T py) {
    return std::sqrt(dist_sq(px, py));
}

template<typename T>
inline T Line2d<T>::relativeCCW(const Vector2d<T> &point) {
    return relativeCCW(point.getX(), point.getY());
}

template<typename T>
inline T Line2d<T>::relativeCCW(T px, T py) {
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