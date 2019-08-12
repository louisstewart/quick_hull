//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#include "Vector2d.h"
#include <cmath>
#include <iostream>
#include <sstream>


template <class T>
inline Vector2d<T>::Vector2d(const Vector2d<T> &vec) {
    x=vec.x;
    y=vec.y;
}

template <class T>
inline bool Vector2d<T>::operator==(const Vector2d<T> &vec) {
    return (x == vec.x && y == vec.y);
}

template <class T>
inline Vector2d<T> Vector2d<T>::operator+(const Vector2d<T> &vec) {
    return Vector2d(x+vec.x, y+vec.y);;
}

template <class T>
inline Vector2d<T>& Vector2d<T>::operator+=(const Vector2d<T> &vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

template <class T>
inline Vector2d<T> Vector2d<T>::operator-(const Vector2d<T> &vec) {
    return Vector2d(x-vec.x, y-vec.y);;
}

template <class T>
inline Vector2d<T>& Vector2d<T>::operator-=(const Vector2d<T> &vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

template <class T>
inline Vector2d<T> Vector2d<T>::operator*(T val) {
    return Vector2d(x*val, y*val);;
}

template <class T>
inline Vector2d<T>& Vector2d<T>::operator*=(T val) {
    x *= val;
    y *= val;
    return *this;
}

template <class T>
inline Vector2d<T> Vector2d<T>::operator/(T val) {
    if (val == 0.0)
        throw std::exception();
    return Vector2d(x/val, y/val);
}

template <class T>
inline Vector2d<T>& Vector2d<T>::operator/=(T val) {
    if (val == 0.0)
        throw std::exception();
    x /= val;
    y /= val;
    return *this;
}

template <class T>
inline T Vector2d<T>::dot(const Vector2d<T> &vec) {
    return x * vec.x + y * vec.y;
}

template <class T>
inline T Vector2d<T>::operator*(const Vector2d<T> &vec) {
    return dot(vec);
}

template <class T>
inline T Vector2d<T>::mag() {
    return std::sqrt(square());
}

template <class T>
inline Vector2d<T>& Vector2d<T>::norm() {
    if (mag() == 0.0)
        throw std::exception();
    *this/=mag();
    return *this;
}

template <class T>
inline T Vector2d<T>::square() {
    return x * x + y * y;
}

template <class T>
inline T Vector2d<T>::dist(const Vector2d<T> &o) {
    Vector2d d = *this-o;
    return d.mag();
}

template <class T>
inline T Vector2d<T>::getX() const {
    return x;
}

template <class T>
inline T Vector2d<T>::getY() const {
    return y;
}

template <class T>
inline void Vector2d<T>::print() {
    std::cout << "Vector2d[" << x << "," << y << "]";
}

template <class T>
inline std::string Vector2d<T>::toString() {
    std::ostringstream stream;
    stream << "[" << x << "," << y << "]";
    return stream.str();
}




