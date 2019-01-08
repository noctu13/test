#include "genunit.h"
#include <QBrush>
#include <QGraphicsScene>

GenUnit::GenUnit(QGraphicsScene* scene):QGraphicsEllipseItem(){
    sceneX = static_cast<int>(scene->sceneRect().width());
    sceneY = static_cast<int>(scene->sceneRect().height());
    QColor color = QColor(rand()%255,rand()%255,rand()%255);
    setBrush(QBrush(color));
    setRect(-unit_size/2, -unit_size/2, unit_size, unit_size);
    setPos(rand()%sceneX, rand()%sceneY);
}

void GenUnit::advance(int phase){
    if(phase){
        moveBy(rand()%speed-1,rand()%speed-1);
        if(pos().x()<0||pos().x()>sceneX||
           pos().y()<0||pos().y()>sceneY)
            delete this;
        if(data(0).toBool())
            delete this;
    }
}

int GenUnit::type() const{
    return Type;
}
