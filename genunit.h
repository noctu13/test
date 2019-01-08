#ifndef GENUNIT_H
#define GENUNIT_H

#include <QGraphicsEllipseItem>

class GenUnit: public QGraphicsEllipseItem{
    int speed = 3, unit_size = 10,
        sceneX, sceneY;
public:
    enum {Type = UserType + 1};
    GenUnit(QGraphicsScene* scene);
    virtual void advance(int phase);
    virtual int type() const;
};

#endif // GENUNIT_H
