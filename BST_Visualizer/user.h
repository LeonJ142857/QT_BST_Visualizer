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
        QPixmap static createTree(vector<int> arr);
};

#endif // USER_H
