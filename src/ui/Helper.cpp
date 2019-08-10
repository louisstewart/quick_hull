//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "Helper.h"
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>

Helper::Helper() {
    circleBrush = QBrush(QColor(250, 20, 5));
    background = QBrush(QColor(255, 255, 255));
}

void Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed) {
    painter->fillRect(event->rect(), background);
    painter->translate(100,100);

    painter->save();
    // Do paint loop for all vector2d
    painter->restore();
}