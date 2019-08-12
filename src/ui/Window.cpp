//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include <QGridLayout>
#include <QTimer>
#include <QMouseEvent>
#include "Window.h"
#include "Widget.h"
#include "../Vector2d.h"

Window::Window(std::vector<Vector2d<float>>& vecs): vecs{vecs}, widget{&helper, vecs} {
    setWindowTitle(("Graphics 2D test"));

    auto *layout = new QGridLayout;
    layout->setMargin(0);
    layout->setSpacing(0);
    layout->addWidget(&widget, 0, 0);
    setLayout(layout);
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    clear = new QPushButton("Clear", this);
    clear->setMaximumSize(200, 60);
    QString qss = QString("background-color: %1").arg(QColor(Qt::darkCyan).name());
    clear->setStyleSheet(qss);
    clear->show();
    connect(clear, SIGNAL(released()), this, SLOT(handleButton()));

    setMinimumSize(width * scale, width * scale);
    setMaximumSize(width * scale, width * scale);

    auto *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, &widget, &Widget::animate);
    timer->start(50);
}

void Window::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        auto point = event->pos();
        auto *f = new Vector2d<float>{(float)point.x() - (width / (scale/2)), (float)point.y() - (width / (scale/2))};
        vecs.push_back(*f);
    }
    widget.animate();
}

void Window::handleButton() {
    vecs.clear();
    widget.animate();
}

