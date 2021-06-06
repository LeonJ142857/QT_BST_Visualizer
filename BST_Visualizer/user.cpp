#include "user.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <binarytreegraphic.h>
#include <QApplication>
#include <QMessageBox>

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

//    User::

    cout << "Number of nodes which have only left child: " << tree->countLeftNodes() << endl;
    cout << "Tree height: " << tree->countLevels() << endl;
    cout << "Number of nodes: " << tree->countNodes() << endl;
    cout << "Find element: " << tree->findElem(19) << endl;

    tree->preorderWalk();
    tree->inorderWalk();
    tree->postorderWalk();

//    cout << "Delete node: ";
//    if (tree->deleteNode(7) == -1)
//        cout << "Could not find element [user_input], delete process has been terminated" << endl;
//    a->show();

    writeToFile(arr);
    return tree->show();
}

QPixmap User::deleteNode(int val){
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BinaryTreeGraphic* tree = new BinaryTreeGraphic();
    tree->init(&scene, &view);

    vector<int> currentTree = readFile();
    for(int i : currentTree)
        tree->insert(i);
    int delNode = tree->deleteNode(val);
    if(delNode == -1){
        return tree->show();
    } else {
        QMessageBox::information(NULL, "Information", "Element was not found. Delete operation has been aborted.");
        writeToFile(currentTree);
        return tree->show();
    }
}

QPixmap User::refreshTree(){
    vector<int> tree_nodes = readFile();
    if (tree_nodes.empty()){
        tree_nodes.push_back(0);
        return createTree(tree_nodes);
    } else {
        return createTree(tree_nodes);
    }
}

QPixmap User::refreshTree(int val){
    vector<int> tree_nodes = readFile();
    if (std::find(tree_nodes.begin(), tree_nodes.end(), val) != tree_nodes.end())
        QMessageBox::information(NULL, "Information", "Element is already present in the tree. BST does not allow duplicate elements");
    else
        tree_nodes.push_back(val);
    return createTree(tree_nodes);
}

QPixmap User::resetTree(){
    vector<int> reset;
    return createTree(reset);
    // create new instance of binarytreegraphic then return it with empty tree;
    // apparently empty vector results in 0 being added into the tree;
}
