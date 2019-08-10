//
// Created by Louis William Henry Renton Stewart on 2019-08-09.
//

#ifndef QUICKHULL_WINDOW_H
#define QUICKHULL_WINDOW_H


#include <QWidget>
#include "Helper.h"

class Window : public QWidget {
    Q_OBJECT

public:
    Window();

private:
    Helper helper;
};

#endif //QUICKHULL_WINDOW_H
