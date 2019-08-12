//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_LINE2D_H
#define QUICKHULL_LINE2D_H


#include "Vector2d.h"

template<class T>
class Line2d {

private:
    T x1;
    T y1;
    T x2;
    T y2;

public:
    using value_type = T;

    Line2d(T a, T b, T c, T d) : x1{a}, y1{b}, x2{c}, y2{d} {}

    Line2d(const Vector2d<T> &a, const Vector2d<T> &b) : x1{a.getX()}, y1{a.getY()}, x2{b.getX()}, y2{b.getY()} {}

    ~Line2d() = default;

    T relativeCCW(const Vector2d<T> &point);

    T relativeCCW(T px, T py);

    T dist_sq(const Vector2d<T> &point);

    T dist_sq(T px, T py);

    T dist(const Vector2d<T> &point);

    T dist(T px, T py);

    Vector2d<T> operator~(); // Get orthogonal vector
    T getX1() { return x1; };

    T getY1() { return y1; };

    T getX2() { return x2; };

    T getY2() { return y2; };
};

#include "Line2d.inl"

#endif //QUICKHULL_LINE2D_H
