//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_POINT_H
#define QUICKHULL_POINT_H

#include <string>

class Vector2d {
private:
    float x;
    float y;

public:
    Vector2d(float a, float b): x(a), y(b) {}
    ~Vector2d() = default;

    Vector2d(const Vector2d &vec); // Copy constructor
    Vector2d&operator=(const Vector2d&vec) = default; // Copy assign
    Vector2d operator+(const Vector2d&vec); // Add
    Vector2d& operator+=(const Vector2d&vec); // Add assign
    Vector2d operator-(const Vector2d&vec); // Add
    Vector2d& operator-=(const Vector2d&vec); // Add assign
    Vector2d operator*(float val); // Add
    Vector2d& operator*=(float val); // Add assign
    Vector2d operator/(float val); // Add
    Vector2d& operator/=(float val); // Add assign
    bool operator==(const Vector2d &vec);
    float dot(const Vector2d&vec); // dot product
    float operator*(const Vector2d& vec); // dot product
    float mag();
    Vector2d& norm();
    float square();
    float dist(const Vector2d &o);
    float getX() const;
    float getY() const;
    void print(); // Show it
    std::string toString();
};

#include "Vector2d.inl"

#endif //QUICKHULL_POINT_H
