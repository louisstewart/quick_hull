//
// Created by Louis William Henry Renton Stewart on 2019-08-05.
//

#ifndef QUICKHULL_QUICKHULL_H
#define QUICKHULL_QUICKHULL_H

#include "Vector2d.h"
#include <vector>

/**
 * Calculate the convex hull around a set of points, using the QuickHull algorithm.
 * This algo runs in an average case O(Nlog(N)) time for a set of N points.
 *
 * @param vecs vector of Vector2d points in 2D space
 * @return vector of points defining the convex hull around the input points
 */
std::vector<Vector2d> quick_hull(std::vector<Vector2d> vecs);

#endif //QUICKHULL_QUICKHULL_H
