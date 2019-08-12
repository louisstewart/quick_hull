//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_POINT_H
#define QUICKHULL_POINT_H

#include <string>

template<class T>
class Vector2d {
private:
    T x;
    T y;

public:
    using value_type = T;

    Vector2d(T a, T b) : x(a), y(b) {}

    ~Vector2d() = default;

    Vector2d(const Vector2d &vec); // Copy constructor
    Vector2d<T> &operator=(const Vector2d<T> &vec) = default; // Copy assign
    Vector2d<T> operator+(const Vector2d<T> &vec); // Add
    Vector2d<T> &operator+=(const Vector2d<T> &vec); // Add assign
    Vector2d<T> operator-(const Vector2d<T> &vec); // Add
    Vector2d<T> &operator-=(const Vector2d<T> &vec); // Add assign
    Vector2d<T> operator*(T val); // Add
    Vector2d<T> &operator*=(T val); // Add assign
    Vector2d<T> operator/(T val); // Add
    Vector2d<T> &operator/=(T val); // Add assign
    bool operator==(const Vector2d<T> &vec);

    T dot(const Vector2d<T> &vec); // dot product
    T operator*(const Vector2d<T> &vec); // dot product
    T mag();

    Vector2d<T> &norm();

    T square();

    T dist(const Vector2d &o);

    T getX() const;

    T getY() const;

    void print(); // Show it
    std::string toString();
};

#include "Vector2d.inl"

#endif //QUICKHULL_POINT_H
