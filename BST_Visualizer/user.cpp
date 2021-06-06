#include "user.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <binarytreegraphic.h>
#include <QApplication>

using namespace std;

vector<int> User::readFile(){
    vector<int> userGeneratedBST;
    ifstream userGenerated;
    userGenerated.open("userData.txt");

    if (!userGenerated.fail()){
        while (!userGenerated.eof()){
            int currData;
            userGenerated >> currData;
            userGeneratedBST.push_back(currData);
        }
    }
    userGenerated.close();
    return userGeneratedBST;
}

void User::writeToFile(vector<int> arr){
    ofstream userData;
    userData.open("userData.txt");

    if (!userData.fail()){
        for(unsigned long long i = 0; i < arr.size(); i++){
            if (i == arr.size()-1)
                userData << arr[i];
            else
                userData << arr[i] << endl;
        }
    }
    userData.close();
}

QPixmap User::createTree(vector<int> arr){
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BinaryTreeGraphic* tree = new BinaryTreeGraphic();
    tree->init(&scene, &view);

    if(!arr.empty()){
        for(int i : arr)
            tree->insert(i);
    } else {
        tree->insert(0);
    }
//    vector<int> data;
//    data.push_back(9);
//    data.push_back(5);
//    data.push_back(3);
//    data.push_back(14);

//    vector<int> userData = readFile();
//    if (userData.empty()){
//        a->insert(7);
//        a->insert(6);
//        a->insert(10);
//        a->insert(3);
//        a->insert(4);
//        a->insert(5);
//        a->insert(8);
//        a->insert(12);
//        a->insert(9);
//    } else {
//        for (int i : userData){
//            tree->insert(i);
//        }
//    }

//    User::writeToFile(data);

    cout << "Number of nodes which have only left child: " << tree->countLeftNodes() << endl;
    cout << "Tree height: " << tree->countLevels() << endl;
    cout << "Number of nodes: " << tree->countNodes() << endl;
    cout << "Find element: " << tree->findElem(19) << endl;

    tree->preorderWalk();
    tree->inorderWalk();
    tree->postorderWalk();

    cout << "Delete node: ";
    if (tree->deleteNode(7) == -1)
        cout << "Could not find element [user_input], delete process has been terminated" << endl;
//    a->show();

    return tree->show();
}
