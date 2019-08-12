//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_WINDOW_H
#define QUICKHULL_WINDOW_H


#include <QWidget>
#include <QMouseEvent>
#include <src/Vector2d.h>
#include <QPushButton>
#include "Helper.h"
#include "Widget.h"

class Window : public QWidget {
    Q_OBJECT

public:
    const static int width = 400;
    const static int scale = 2;

    explicit Window(std::vector<Vector2d<float>>& vecs);
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void handleButton();
private:
    Helper helper;
    std::vector<Vector2d<float>>& vecs;
    Widget widget;
    QPushButton *clear;
};

#endif //QUICKHULL_WINDOW_H
