#include "binarytreegraphic.h"

BinaryTreeGraphic::BinaryTreeGraphic(QObject *parent, int value) : QObject(parent)
{
    graphic = new Graphic(value);
    left = right = nullptr;
}

Graphic *BinaryTreeGraphic::get_graphic()
{
    return graphic;
}

void BinaryTreeGraphic::insertNode(qreal value)
{

}

void BinaryTreeGraphic::deleteNode(qreal value)
{

}

void BinaryTreeGraphic::searchNode(qreal value)
{

}

void BinaryTreeGraphic::DFTPreOrder()
{

}

void BinaryTreeGraphic::DFTInOrder()
{

}

void BinaryTreeGraphic::DFTPostOrder()
{

}

void BinaryTreeGraphic::BFT()
{

}
