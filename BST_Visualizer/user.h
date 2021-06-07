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
        QPixmap static createTree(vector<int> arr, int signal = -1, int delVal = -1);
        QPixmap static createTree();
        QPixmap static deleteNode(int val);
        QPixmap static searchNode(int val);
        QPixmap static refreshTree(int val);
        QPixmap static refreshTree();
        QPixmap static resetTree();
        QPixmap static preOrder();
    protected:
    private:
};

#endif // USER_H
