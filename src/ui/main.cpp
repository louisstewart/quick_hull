//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//
#include <QApplication>
#include <QSurfaceFormat>
#include "Window.h"
#include "../Vector2d.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Vector2d<float> a{50, 0};
    Vector2d<float> b{-50, 0};
    Vector2d<float> c{0, 50};
    Vector2d<float> d{0, -50};

    std::vector<Vector2d<float>> vecs = {a, b, c, d};

    Window window{vecs};
    window.show();
    return app.exec();
}