#ifndef PLAYERUNIT_H
#define PLAYERUNIT_H

#include <QGraphicsEllipseItem>

class PlayerUnit: public QGraphicsEllipseItem{
    int unit_size = 50;
public:
    double speed = 0, angle = 0, t = 1;
    PlayerUnit(QGraphicsScene* scene);
public:
    virtual void advance(int phase);
};

#endif // PLAYERUNIT_H
