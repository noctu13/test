#include <QBrush>
#include <QGraphicsScene>
#include "playerunit.h"
#include "genunit.h"

//Юнит управляемый игроком
PlayerUnit::PlayerUnit(QGraphicsScene* scene):QGraphicsEllipseItem(){
    QColor color = QColor(rand()%255,rand()%255,rand()%255);
    setBrush(QBrush(color));
    setRect(-unit_size/2, -unit_size/2, unit_size, unit_size);
    setPos(scene->sceneRect().width()/2, scene->sceneRect().height()/2);
}

void PlayerUnit::advance(int phase){
    if(phase)
        foreach (QGraphicsItem* item, collidingItems()) {
            if(item->type() == GenUnit::Type)
                item->setData(0, true);
        }
        moveBy(t*speed*cos(angle), t*speed*sin(angle));
}
