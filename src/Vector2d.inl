//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#include "Vector2d.h"
#include <cmath>
#include <iostream>
#include <sstream>


inline Vector2d::Vector2d(const Vector2d &vec) {
    x=vec.x;
    y=vec.y;
}

inline bool Vector2d::operator==(const Vector2d &vec) {
    return (x == vec.x && y == vec.y);
}

inline Vector2d Vector2d::operator+(const Vector2d &vec) {
    return Vector2d(x+vec.x, y+vec.y);;
}

inline Vector2d& Vector2d::operator+=(const Vector2d &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

inline Vector2d Vector2d::operator-(const Vector2d &vec) {
    return Vector2d(x-vec.x, y-vec.y);;
}

inline Vector2d& Vector2d::operator-=(const Vector2d &vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

inline Vector2d Vector2d::operator*(float val) {
    return Vector2d(x*val, y*val);;
}

inline Vector2d& Vector2d::operator*=(float val) {
    x *= val;
    y *= val;
    return *this;
}

inline Vector2d Vector2d::operator/(float val) {
    if (val == 0.0)
        throw std::exception();
    return Vector2d(x/val, y/val);
}

inline Vector2d& Vector2d::operator/=(float val) {
    if (val == 0.0)
        throw std::exception();
    x /= val;
    y /= val;
    return *this;
}

inline float Vector2d::dot(const Vector2d &vec) {
    return x * vec.x + y * vec.y;
}

inline float Vector2d::operator*(const Vector2d &vec) {
    return dot(vec);
}

inline float Vector2d::mag() {
    return std::sqrt(square());
}

inline Vector2d& Vector2d::norm() {
    if (mag() == 0.0)
        throw std::exception();
    *this/=mag();
    return *this;
}

inline float Vector2d::square() {
    return x * x + y * y;
}

inline float Vector2d::dist(const Vector2d &o) {
    Vector2d d = *this-o;
    return d.mag();
}

inline float Vector2d::getX() const {
    return x;
}

inline float Vector2d::getY() const {
    return y;
}

inline void Vector2d::print() {
    std::cout << "Vector2d[" << x << "," << y << "]";
}

inline std::string Vector2d::toString() {
    std::ostringstream stream;
    stream << "[" << x << "," << y << "]";
    return stream.str();
}




