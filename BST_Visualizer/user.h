#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <iostream>
#include <qgraphicsview.h>
#include <qtextstream.h>
#include <qprocess.h>
#include <QPixmap>

using namespace std;

class User{
    public:
        vector<int> static readFile();
        void static writeToFile(vector<int> arr);
        QPixmap static createTree(vector<int> arr, int signal = -1, int opVal = -1, int opVal2 = -1);
        QPixmap static createTree();
        QPixmap static deleteNode(int val);
        QPixmap static searchNode(int val);
        QPixmap static searchNode(int val, int val2);
        QPixmap static refreshTree(int val);
        QPixmap static refreshTree();
        QPixmap static resetTree();
        QPixmap static preOrder();
        vector<int> static findSuccessor(int val);
    protected:
    private:
};

#endif // USER_H
