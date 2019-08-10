# QuickHull + Qt

C++ implementation [QuickHull](https://en.wikipedia.org/wiki/Quickhull) 
algorithm for finding the convex hull around a set of points in the 2d 
plane. There are Boost.Test tests available for the project 
(requires Boost) and a simple Qt GUI for creating a set of points 
and finding the hull.

## Build

### Requirements
- A CMakeLists.txt file defines the projects to 
build, so `cmake` is required in order to build the project. 
- Qt5 is required for the UI - can be installed easily on 
MacOS with `brew install qt` or through package manager on *Nix
- Boost is required for the Boost.Test unittests, again easily 
installed with `brew install boost` or through *Nix package manager

### Building

```bash
cmake . # Run from root folder of project to build in the root
# or 
mkdir bin && cd bin && cmake ..  # to build in bin folder
``` 


## Features

This implementation contains a Header Only 2d vector and line linear 
algebra library included in the `src` folder. This library has the 
following classes

```cpp

class Vector2d {
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
    T dot(const Vector2d&vec); // dot product
    T operator*(const Vector2d& vec); // dot product
    T mag();
    Vector2d& norm();
    float square();
    T dist(const Vector2d &o);
    T getX() const;
    T getY() const;
    void print(); // Show it
    std::string toString();
};
``` 
Vector2d class is implemented as an inlined header, so there is no 
overhead from the function calls, and the library is lightweight for 
installation.

Similarly, there is
```cpp
class Line2d {
    T relativeCCW(const Vector2d &point);  // Get points which are anti-clockwise
    T relativeCCW(T px, T py);
    T dist_sq(const Vector2d &point); // Square of distance to point
    T dist_sq(T px, T py);
    T dist(const Vector2d &point); // L2 distance to point
    T dist(T px, T py);
    Vector2d operator~(); // Get orthogonal vector
    T getX1() {return x1;};
    T getY1() {return y1;};
    T getX2() {return x2;};
    T getY2() {return y2;};
};
```

Which allows defining a Line in 2d space based on 2 points. 