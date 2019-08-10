//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_LINE2D_H
#define QUICKHULL_LINE2D_H


#include "Vector2d.h"

class Line2d {
private:
    float x1;
    float y1;
    float x2;
    float y2;
public:
    Line2d(float a, float b, float c, float d): x1{a}, y1{b}, x2{c}, y2{d} {}
    Line2d(const Vector2d& a, const Vector2d& b): x1{a.getX()}, y1{a.getY()}, x2{b.getX()}, y2{b.getY()} {}
    ~Line2d() = default;

    float relativeCCW(const Vector2d &point);
    float relativeCCW(float px, float py);
    float dist_sq(const Vector2d &point);
    float dist_sq(float px, float py);
    float dist(const Vector2d &point);
    float dist(float px, float py);
    Vector2d operator~(); // Get orthogonal vector
    float getX1() {return x1;};
    float getY1() {return y1;};
    float getX2() {return x2;};
    float getY2() {return y2;};
};

#include "Line2d.inl"

#endif //QUICKHULL_LINE2D_H
