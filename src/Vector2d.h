//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_POINT_H
#define QUICKHULL_POINT_H

#include <string>

template<typename T>
class Vector2d {
    using value_type = T;
private:
    T x;
    T y;

public:
    Vector2d(T a, T b): x(a), y(b) {}
    ~Vector2d() = default;

    Vector2d(const Vector2d &vec); // Copy constructor
    Vector2d&operator=(const Vector2d&vec) = default; // Copy assign
    Vector2d operator+(const Vector2d&vec); // Add
    Vector2d& operator+=(const Vector2d&vec); // Add assign
    Vector2d operator-(const Vector2d&vec); // Add
    Vector2d& operator-=(const Vector2d&vec); // Add assign
    Vector2d operator*(T val); // Add
    Vector2d& operator*=(T val); // Add assign
    Vector2d operator/(T val); // Add
    Vector2d& operator/=(T val); // Add assign
    bool operator==(const Vector2d &vec);
    T dot(const Vector2d &vec); // dot product
    T operator*(const Vector2d &vec); // dot product
    T mag();
    Vector2d& norm();
    T square();
    T dist(const Vector2d &o);
    T getX() const;
    T getY() const;
    void print(); // Show it
    std::string toString();
};

#include "Vector2d.inl"

#endif //QUICKHULL_POINT_H
