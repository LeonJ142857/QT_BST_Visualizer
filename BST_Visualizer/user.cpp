#include "user.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <binarytreegraphic.h>
#include <QApplication>
#include <QMessageBox>
#include <mainwindow.h>

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

    if (arr.empty()){
        return;
    } else {
        if (!userData.fail()){
            for(unsigned long long i = 0; i < arr.size(); i++){
                if (i == arr.size()-1)
                    userData << arr[i];
                else
                    userData << arr[i] << endl;
            }
        }
    }
    userData.close();
}

QPixmap User::createTree(vector<int> arr, int signal, int opVal){ // operationValue
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    view.setRenderHints(QPainter::SmoothPixmapTransform);

    BinaryTreeGraphic* tree = new BinaryTreeGraphic();
    tree->init(&scene, &view);

    if(!arr.empty()){
        for(int i : arr)
            tree->insert(i);
    }

//    cout << "Number of nodes which have only left child: " << tree->countLeftNodes() << endl;
//    cout << "Tree height: " << tree->countLevels() << endl;
//    cout << "Number of nodes: " << tree->countNodes() << endl;
//    cout << "Find element: " << tree->findElem(19) << endl;

//    tree->preorderWalk();
//    tree->inorderWalk();
//    tree->postorderWalk();

    if (signal == 3){ // delete
        QString delValStr = QString::number(opVal);
        int delNode = tree->deleteNode(opVal);
        if (delNode == -1)
            QMessageBox::information(NULL, "Information", "Node \"" + delValStr + "\" was not found. Delete operation has been aborted.");
        else {
            std::vector<int>::iterator position = std::find(arr.begin(), arr.end(), opVal);
            if (position != arr.end()) // == myVector.end() means the element was not found
                arr.erase(position);
            writeToFile(arr);
            createTree(arr);
        }
    }
    else if (signal == 5){ // search
        QString searchNodeStr = QString::number(opVal);
        if (tree->findElem(opVal) == NULL)
            QMessageBox::information(NULL, "Information", "Node \"" + searchNodeStr + "\" was not found.");
    }
    else if (signal == 8){
        tree->preorderWalk();
    }
    else if (signal == 9){
        tree->inorderWalk();
    }
    else if (signal == 10){
        tree->postorderWalk();
    }

    if (!arr.empty())
        writeToFile(arr);
    else
        remove("userData.txt");
    return tree->show();
}

QPixmap User::createTree(){
    vector<int> currentTree = readFile();
    return createTree(currentTree);
}

QPixmap User::deleteNode(int val){
    vector<int> currentTree = readFile();
    return createTree(currentTree, 3, val);
}

QPixmap User::refreshTree(){
    vector<int> tree_nodes = readFile();
    return createTree(tree_nodes);
}

QPixmap User::refreshTree(int val){
    vector<int> tree_nodes = readFile();
    QString valStr = QString::number(val);
    if (std::find(tree_nodes.begin(), tree_nodes.end(), val) != tree_nodes.end())
        QMessageBox::information(NULL, "Information", "Element \"" + valStr + "\" is already present in the tree. BST does not allow duplicate elements");
    else
        tree_nodes.push_back(val);
    return createTree(tree_nodes);
}

QPixmap User::resetTree(){
    vector<int> reset;
    return createTree(reset);
}

QPixmap User::searchNode(int val){
    vector<int> search_node = readFile();
    return createTree(search_node, 5, val);
}

QPixmap User::preOrder(){
    vector<int> userTree = readFile();
    return createTree(userTree, 8);
}
