#ifndef MODGRAPHICSCENE_H
#define MODGRAPHICSCENE_H

#include <QGraphicsScene>

class PlayerUnit;
class ModGraphicScene: public QGraphicsScene{
    PlayerUnit *pu;
public:
    ModGraphicScene(QObject *parent = 0);
    void setPlayer(PlayerUnit *pu);
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MODGRAPHICSCENE_H
