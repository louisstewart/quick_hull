//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_HELPER_H
#define QUICKHULL_HELPER_H


#include <QBrush>
#include <QWidget>
#include "../Vector2d.h"

class Helper {
public:
    Helper();

    void paint(QPainter *painter, QPaintEvent *event, const std::vector<Vector2d<float>>& vecs);

private:
    QBrush circleBrush;
    QBrush background;
};


#endif //QUICKHULL_HELPER_H
