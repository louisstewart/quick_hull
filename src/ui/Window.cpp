//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "Window.h"
#include "Widget.h"
#include <QGridLayout>
#include <QTimer>

Window::Window() {
    setWindowTitle(("Graphics 2D test"));

    auto *wid = new Widget(&helper, this);

    auto *layout = new QGridLayout;
    layout->addWidget(wid, 0, 0);
    setLayout(layout);

    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, wid, &Widget::animate);
    timer->start(50);
}

