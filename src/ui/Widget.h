//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_WIDGET_H
#define QUICKHULL_WIDGET_H

#include <QWidget>
#include <src/Vector2d.h>

class Helper;

class Widget : public QWidget {
Q_OBJECT

public:
    Widget(Helper *helper, std::vector<Vector2d<float>> &vecs);

public slots:

    void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Helper *helper;
    int elapsed;
    std::vector<Vector2d<float>> &vecs;
};

#endif //QUICKHULL_WIDGET_H
