//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//
#include "../src/Vector2d.h"
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE QuickHull
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(TEST_SUITE_Vector2d)

    BOOST_AUTO_TEST_CASE(test_create) {
        Vector2d<float> v{1, 1};

        BOOST_CHECK_EQUAL(v.getX(), 1);
        BOOST_CHECK_EQUAL(v.getY(), 1);
    }

    BOOST_AUTO_TEST_CASE(test_create_float) {
            Vector2d<float> v{1.5, 1.1};

            BOOST_CHECK_CLOSE(v.getX(), 1.5, 0.0001);
            BOOST_CHECK_CLOSE(v.getY(), 1.1, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_copy_constructor) {
        Vector2d<float> v{1.5, 1.1};
        Vector2d<float> v2{v};

        BOOST_CHECK_CLOSE(v2.getX(), 1.5, 0.0001);
        BOOST_CHECK_CLOSE(v2.getY(), 1.1, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_copy_assign) {
            Vector2d<float> v{1.5, 1.1};
            Vector2d<float> v2 = v;

            BOOST_CHECK_CLOSE(v2.getX(), 1.5, 0.0001);
            BOOST_CHECK_CLOSE(v2.getY(), 1.1, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_add) {
        Vector2d<float> v{1.5, 1.1};
        Vector2d<float> v2 = v;

        Vector2d<float> v3 = v + v2;

        BOOST_CHECK_CLOSE(v3.getX(), 3.0, 0.0001);
        BOOST_CHECK_CLOSE(v3.getY(), 2.2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_add_eq) {
        Vector2d<float> v{1.5, 1.1};
        Vector2d<float> v2 = v;

        v2 += v;

        BOOST_CHECK_CLOSE(v2.getX(), 3.0, 0.0001);
        BOOST_CHECK_CLOSE(v2.getY(), 2.2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_sub) {
        Vector2d<float> v{1.5, 1.1};
        Vector2d<float> v2 = v;

        Vector2d<float> v3 = v2 - v;

        BOOST_CHECK_CLOSE(v3.getX(), 0.0, 0.0001);
        BOOST_CHECK_CLOSE(v3.getY(), 0.0, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_sub_eq) {
        Vector2d<float> v{1.5, 1.1};
        Vector2d<float> v2 = v;

        v2 -= v;

        BOOST_CHECK_CLOSE(v2.getX(), 0.0, 0.0001);
        BOOST_CHECK_CLOSE(v2.getY(), 0.0, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_mult) {
        Vector2d<float> v{1.5, 1.1};

        v = v * 2;

        BOOST_CHECK_CLOSE(v.getX(), 3.0, 0.0001);
        BOOST_CHECK_CLOSE(v.getY(), 2.2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_mult_eq) {
        Vector2d<float> v{1.5, 1.1};

        v *= 2;

        BOOST_CHECK_CLOSE(v.getX(), 3.0, 0.0001);
        BOOST_CHECK_CLOSE(v.getY(), 2.2, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_div) {
        Vector2d<float> v{1.5, 1.1};

        v = v / 2;

        BOOST_CHECK_CLOSE(v.getX(), 0.75, 0.0001);
        BOOST_CHECK_CLOSE(v.getY(), 0.55, 0.0001);

        BOOST_CHECK_THROW(v / 0, std::exception);
    }

    BOOST_AUTO_TEST_CASE(test_div_eq) {
        Vector2d<float> v{1.5, 1.1};

        v = v / 2;

        BOOST_CHECK_CLOSE(v.getX(), 0.75, 0.0001);
        BOOST_CHECK_CLOSE(v.getY(), 0.55, 0.0001);

        BOOST_CHECK_THROW(v /= 0, std::exception);
    }

    BOOST_AUTO_TEST_CASE(test_dot_product) {
        /*
         *  x . y = x1y1 + x2y2
         *
         *  = 2*1.5 + 4*1.1 = 7.4
         */
        Vector2d<float> x{2, 4};
        Vector2d<float> v{1.5, 1.1};

        float dot = x * v;
        float dot2 = x.dot(v);

        BOOST_CHECK_CLOSE(dot, 7.4, 0.0001);
        BOOST_CHECK_CLOSE(dot2, 7.4, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_magnitude) {
        /*
         *  mag = root(x^2 + y^2)
         */
        Vector2d<float> x{3, 4};

        float mag = x.mag();

        BOOST_CHECK_CLOSE(mag, 5, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_norm) {
        /*
         *  mag = root(x^2 + y^2)
         *  norm = x/mag
         */
        Vector2d<float> x{3, 4};

        x = x.norm();

        BOOST_CHECK_CLOSE(x.getX(), 3./5., 0.0001);
        BOOST_CHECK_CLOSE(x.getY(), 4./5., 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_square) {
        /*
         *  square = x^2 + y^2
         */
        Vector2d<float> x{3.0, 4.0};

        float mag = x.square();

        BOOST_CHECK_CLOSE(mag, 25, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_dist) {
        /*
         *  distance = root((x1-x2)^2 + (y1-y2)^2)
         */
        Vector2d<float> x{2, 4};
        Vector2d<float> y{5, 8};

        float mag = x.dist(y);

        BOOST_CHECK_CLOSE(mag, 5, 0.0001);
    }

    BOOST_AUTO_TEST_CASE(test_to_string) {
        Vector2d<float> x{3, 4};

        std::string res = x.toString();
        std::string expected = "[3,4]";
        BOOST_CHECK_EQUAL(res, expected);
    }


BOOST_AUTO_TEST_SUITE_END()