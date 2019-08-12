//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "Widget.h"
#include "Helper.h"

#include <QPainter>
#include <QTimer>

Widget::Widget(Helper *helper, std::vector<Vector2d<float>>& vecs)
        : helper(helper), vecs(vecs)
{
    elapsed = 0;
    setFixedSize(800, 800);
}

void Widget::animate()
{
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, vecs);
    painter.end();
}
