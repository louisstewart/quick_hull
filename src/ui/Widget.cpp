//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#include "Widget.h"
#include "Helper.h"

#include <QPainter>
#include <QTimer>

Widget::Widget(Helper *helper, QWidget *parent)
        : QWidget(parent), helper(helper)
{
    elapsed = 0;
    setFixedSize(200, 200);
}

void Widget::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    update();
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    helper->paint(&painter, event, elapsed);
    painter.end();
}
