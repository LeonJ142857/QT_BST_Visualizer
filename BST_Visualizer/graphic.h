#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class Graphic:public QGraphicsItem
{
public:
    Graphic(int value);
    QRectF boundingRect() const override;
    void paint(QPainter* painter,
               const QStyleOptionGraphicsItem * option
               , QWidget *widget) override;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    bool Pressed;
    int value;
};

#endif // GRAPHIC_H
