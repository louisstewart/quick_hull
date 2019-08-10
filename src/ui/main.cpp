//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//
#include <QApplication>
#include <QSurfaceFormat>
#include "Window.h"

int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QSurfaceFormat fmt;
    fmt.setSamples(4);
    QSurfaceFormat::setDefaultFormat(fmt);

    Window window;
    window.show();
    return app.exec();
}