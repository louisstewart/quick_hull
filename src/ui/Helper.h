//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_HELPER_H
#define QUICKHULL_HELPER_H


#include <QBrush>
#include <QWidget>

class Helper {
public:
    Helper();

    void paint(QPainter *painter, QPaintEvent *event, int elapsed);

private:
    QBrush circleBrush;
    QBrush background;
};


#endif //QUICKHULL_HELPER_H
