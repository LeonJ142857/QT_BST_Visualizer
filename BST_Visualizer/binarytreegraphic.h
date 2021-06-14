#ifndef BINARYTREEGRAPHIC_H
#define BINARYTREEGRAPHIC_H

#include <iostream>
#include <qgraphicsview.h>
#include <qtextstream.h>
#include <qprocess.h>
#include <vector>
#include <QPixmap>

struct Node{
    Node *p;
    int key;
    int searched;
    Node *left;
    Node *right;
};

class BinaryTreeGraphic
{
    public:
        void init(QGraphicsScene* scene, QGraphicsView* view);
        void insert(int a);

        void preorderWalk();
        void postorderWalk();
        void inorderWalk();
        void breadthfirstWalk();

        int deleteNode(int val);
        int deleteNode(Node* p);
        QPixmap show();

        Node* findElem(int val);
        std::vector<int> static generateTree(int nodes);

    protected:
    private:
        void preorderWalk(Node* p);
        void postorderWalk(Node* p);
        void inorderWalk(Node* p);
        void breadthfirstWalk(Node* p);

        Node* findSuccessor(int val);

        QByteArray _prepareGraph();
        void _graphWalk(Node* p,  QTextStream* stream);
        Node* findElem(int val, Node* p);

        Node* _root;
        QGraphicsScene* _scene;
        QGraphicsView* _view;

        int searchSig;
};

#endif // BINARYTREEGRAPHIC_H
