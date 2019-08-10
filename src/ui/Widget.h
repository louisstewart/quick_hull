//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_WIDGET_H
#define QUICKHULL_WIDGET_H

#include <QWidget>

class Helper;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Helper *helper, QWidget *parent);

public slots:
            void animate();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Helper *helper;
    int elapsed;
};

#endif //QUICKHULL_WIDGET_H
