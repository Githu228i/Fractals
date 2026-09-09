#ifndef DRAWER_H
#define DRAWER_H

#include "mainwindow.h"

class Drawer
{
public:
    Drawer(MainWindow *window);

    void DrawFractals();

private:
    MainWindow *main;
};

#endif // DRAWER_H
