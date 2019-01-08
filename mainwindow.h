#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QTimer>
#include "modgraphicscene.h"

class MainWindow : public QMainWindow{
    Q_OBJECT

    QStackedWidget *wgt_stk;
    QWidget *window, *game, *load, *settings;
    QTimer *animationTimer;
    QTimer *genTimer;
    ModGraphicScene *graphScene;
    PlayerUnit *playerUnit;
public:

    MainWindow(QWidget *parent = 0);
};

#endif // MAINWINDOW_H
