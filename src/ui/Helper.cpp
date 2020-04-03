//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "Helper.h"
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <src/quickhull.h>

Helper::Helper() {
    circleBrush = QBrush(QColor(250, 20, 5));
    background = QBrush(QColor(255, 255, 255));
}

void Helper::paint(QPainter *painter, QPaintEvent *event, const std::vector<Vector2d<float>>& vecs) {
    painter->fillRect(event->rect(), background);
    painter->translate(400,400);

    painter->save();
    // Do paint loop for all vector2d
    painter->setBrush(circleBrush);
    for(const auto& vec: vecs) {
        painter->drawEllipse(QPointF(vec.getX(), vec.getY()), 5, 5);
    }

    if(vecs.size() > 2) {
        painter->setPen(QPen(Qt::darkGreen, 4));
        auto hull = quick_hull(vecs);
        if (!hull.empty()) {
            for (int i = 0; i < hull.size(); ++i) {
                auto &a = hull[i];
                auto &b = hull[(i + 1) % hull.size()];
                painter->drawLine(QPointF(a.getX(), a.getY()), QPointF(b.getX(), b.getY()));
            }
        }
    }

    painter->setBrush(background);
    painter->restore();
}