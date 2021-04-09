#include "graphic.h"

Graphic::Graphic(int value)
{
    Pressed = false;
    setFlag(ItemIsMovable);
    this->value = value;
    this->setPos(mapToParent(-900, -900));
}

QRectF Graphic::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

void Graphic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();

    QBrush brush(Qt::blue);
    if(Pressed){
        brush.setColor(Qt::red);
    }
    else{
        brush.setColor(Qt::green);
    }
    painter->setBrush(brush);
    painter->drawEllipse(rec);
    painter->drawText(rec, Qt::AlignCenter, QString("%1").arg(value));

}

void Graphic::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Graphic::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}
