//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//
#include <vector>
#include <cassert>
#include "Vector2d.h"
#include "quickhull.h"

using namespace std;

int main() {

    Vector2d x{0, 1};
    Vector2d x1{1, 1};
    Vector2d x2{1, 0};
    Vector2d x3{0, 0};

    vector<Vector2d<int>> vs = {x, x1, x2, x3};

    auto hull = quick_hull(vs);

    assert(hull.size() == 4);
    return 0;
}
