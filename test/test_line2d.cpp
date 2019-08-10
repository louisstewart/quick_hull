//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "../src/Line2d.h"
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TEST_SUITE_LINE2D)

    BOOST_AUTO_TEST_CASE(test_create) {
        Line2d l{0,0, 2,2};

        BOOST_CHECK_EQUAL(l.getX1(), 0);
        BOOST_CHECK_EQUAL(l.getY1(), 0);
        BOOST_CHECK_EQUAL(l.getX2(), 2);
        BOOST_CHECK_EQUAL(l.getY2(), 2);
    }

    BOOST_AUTO_TEST_CASE(test_ortho_vector) {
        Line2d l{0,0, 2,2};

        Vector2d ortho = ~l;
        BOOST_CHECK_EQUAL(ortho.getX(), -2);
        BOOST_CHECK_EQUAL(ortho.getY(), 2);
    }

    BOOST_AUTO_TEST_CASE(test_dist_square) {
        Line2d l{0,0, 5,0}; // Flat, straight line
        Vector2d p{2, 2}; // Right above middle of line

        float dist = l.dist_sq(p);
        float d2 = l.dist_sq(2, 2);

        BOOST_CHECK_CLOSE(dist, 4, 0.0001);
        BOOST_CHECK_CLOSE(dist, d2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_dist) {
        Line2d l{0,0, 5,0}; // Flat, straight line
        Vector2d p{2, 2}; // Right above middle of line

        float dist = l.dist(p);
        float d2 = l.dist(2, 2);

        BOOST_CHECK_CLOSE(dist, 2, 0.0001);
        BOOST_CHECK_CLOSE(dist, d2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_relative_ccw) {
        Line2d l{0,0, 3,0};
        Line2d lb{3,0, 0,0};
        Vector2d p{2, 2}; // p is counter clockwise of l but not lb

        float left = l.relativeCCW(p);
        float l2 = l.relativeCCW(2, 2);
        float right = lb.relativeCCW(p);
        float r2 = lb.relativeCCW(2, 2);

        BOOST_CHECK_EQUAL(left, -1);
        BOOST_CHECK_EQUAL(left, l2);
        BOOST_CHECK_EQUAL(right, 1);
        BOOST_CHECK_EQUAL(right, r2);
    }

BOOST_AUTO_TEST_SUITE_END()
