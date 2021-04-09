#ifndef BINARYTREEGRAPHIC_H
#define BINARYTREEGRAPHIC_H

#include <QObject>
#include "graphic.h"
class BinaryTreeGraphic : public QObject
{
    Q_OBJECT
public:
    explicit BinaryTreeGraphic(QObject *parent = nullptr, int value = 0);
    Graphic* get_graphic();
signals:

public slots:
    void insertNode(qreal value);
    void deleteNode(qreal value);
    void searchNode(qreal value);
    void DFTPreOrder();
    void DFTInOrder();
    void DFTPostOrder();
    void BFT();
private:
    BinaryTreeGraphic *left;
    BinaryTreeGraphic *right;
    Graphic *graphic;
};

#endif // BINARYTREEGRAPHIC_H
