#include "modgraphicscene.h"
#include "playerunit.h"
#include <QGraphicsSceneMouseEvent>

ModGraphicScene::ModGraphicScene(QObject *parent):QGraphicsScene(parent){
    setSceneRect(0,0,800,600);
}

void ModGraphicScene::setPlayer(PlayerUnit *_pu){
    pu = _pu;
}

void ModGraphicScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    double dx = event->scenePos().x()-pu->x(), dy = event->scenePos().y()-pu->y();
    if(event->button()==Qt::LeftButton){
        pu->t=1;
        if(dx==0){
            if(dy<0)pu->t=-1;
            pu->angle=M_PI_2;//mb minus
        }else{
            pu->angle=atan(dy/dx);
            if(dx<0)pu->t=-1;
        }
    }
    pu->speed = 1;
}

void ModGraphicScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(pu->speed>0){
        double dx = event->scenePos().x()-pu->x(), dy = event->scenePos().y()-pu->y();
        pu->t=1;
        if(dx==0){
            if(dy<0)pu->t=-1;
            pu->angle=M_PI_2;
        }else{
            pu->angle=atan(dy/dx);
            if(dx<0)pu->t=-1;
        }
    }
}

void ModGraphicScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    pu->speed = 0;
}
