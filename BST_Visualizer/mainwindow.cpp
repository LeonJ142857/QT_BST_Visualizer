#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <binarytreegraphic.h>
#include <user.h>
#include <vector>
#include <QTimer>

using namespace std;

std::vector<int> MainWindow::items_traversal;
std::vector<int> MainWindow::items_insert;
std::vector<int> MainWindow::items_search;
std::vector<int> MainWindow::items_delete;
std::vector<int> MainWindow::delete_holder;
bool MainWindow::rootNode;
bool MainWindow::searchFound;
int MainWindow::succValue = -1;
int MainWindow::searchSig = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->addPixmap(User::resetTree());
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTree()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer(){
    ui->deleteButton->setDisabled(true);
    ui->insertButton->setDisabled(true);
    ui->searchButton->setDisabled(true);
    ui->bt_refresh->setDisabled(true);
    ui->bt_reset->setDisabled(true);
    ui->BFTButton_2->setDisabled(true);
    ui->BFTButton->setDisabled(true);
    ui->PreOrderButton->setDisabled(true);
    ui->InOrderButton->setDisabled(true);
    ui->PostOrderButton->setDisabled(true);
    timer->start(1000);
}

void MainWindow::updateTree(){
    vector<int> referenceVec;
    this->scene->clear();

    // traversal
    if (this->doSignal == 1){
        if (count == 0) // fixing the issue with the +1 size below
            items_traversal.pop_back();
        this->scene->addPixmap(User::searchNode(items_traversal[count]));
        referenceVec = items_traversal;
    }
    // insert
    else if (this->doSignal == 2){
        if (count == 0)
            items_insert = items_search;
        if (isRootNode()){
            this->scene->addPixmap(User::refreshTree(this->opValue));
            referenceVec.clear();
        } else {
            if (items_insert[count] == opValue)
                referenceVec.clear();
            else {
                this->scene->addPixmap(User::searchNode(items_insert[count]));
                referenceVec = items_insert;
            }
        }
    }
    // delete
    else if (this->doSignal == 3){
        if (count == 0)
            items_delete = items_search;
        if (getSuccValue() != -1){
            // do searchNode of successor value after iterator reached delVal.
            // set refVec to the size of items_delete.
            // after it has reached the successor value search, terminate the program.
            if (items_search[count-1] == getSuccValue()){
                this->scene->addPixmap(User::searchNode(items_search[count], delete_holder[0]));
                referenceVec = items_delete;
                if (count2 == 1) // added a new var 'count2' to ease the termination process.
                    referenceVec.clear();
                count2++;
            }
            else{
                this->scene->addPixmap(User::searchNode(items_search[count]));
                referenceVec = items_delete;
            }
        }
        // this statement is checking if the current node being searched is the last element being searched.
        // if the statement is not declared, the program will go indefinitely since items_search will
        // continously be added with nodes. items_insert contains the successor value of current node (if any).
        else if (items_search[count] == items_search[items_search.size()-1] && !items_insert.empty()){

            // check if the count is 0, because the program will show a bug, that is if the node to be deleted
            // is the root node and it has only one child, it will show the child first then the current node.
            // var bool 'switched' is declared to act as a checker whether the node to be deleted is the root node.
            if (count == 0){
                this->scene->addPixmap(User::searchNode(items_search[count]));
                this->switched = true;
            } else
                this->scene->addPixmap(User::searchNode(items_search[items_search.size()-1], items_insert[count2]));
            referenceVec = items_delete;
        }
        else {

            // check if the previous count is 0. this is the continuation of the previous 'if' inside the 'else if' statement that contains the bug.
            // when 'switched' is true, it means that the node being deleted is the root node that contains one child. Thus the program will go into
            // the 'if' statement below.
            if (count-1 == 0 && this->switched)
                this->scene->addPixmap(User::searchNode(items_search[items_search.size()-1], items_insert[count2]));
            else
                this->scene->addPixmap(User::searchNode(items_search[count]));
            referenceVec = items_delete;
        }
    }
    // search
    else if (doSignal == 4){
        if (count == 0){
            items_insert = items_search;
        }
        this->scene->addPixmap(User::searchNode(items_insert[count]));
        referenceVec = items_insert;
        if (items_insert[count] == opValue || !isSearchFound())
            referenceVec.clear();
    }

    count++;
    if (count >= referenceVec.size()+1){ // +1 to let the program go to the phase of showing the child node (for delete).
        timer->stop();
        ui->deleteButton->setDisabled(false);
        ui->insertButton->setDisabled(false);
        ui->searchButton->setDisabled(false);
        ui->bt_refresh->setDisabled(false);
        ui->bt_reset->setDisabled(false);
        ui->BFTButton_2->setDisabled(false);
        ui->BFTButton->setDisabled(false);
        ui->PreOrderButton->setDisabled(false);
        ui->InOrderButton->setDisabled(false);
        ui->PostOrderButton->setDisabled(false);
        if (this->doSignal == 3){
            this->scene->clear();
            this->scene->addPixmap(User::deleteNode(this->opValue));
        }
        else if (this->doSignal == 2){
            if (isRootNode()){
                this->scene->clear();
                this->scene->addPixmap(User::searchNode(this->opValue));
            }
            else {
                vector<int> userData = User::readFile();

                // the 'if' statement below is only used for the second element being inserted.
                if (std::find(userData.begin(), userData.end(), this->opValue) == userData.end()){
                    this->scene->addPixmap(User::refreshTree(this->opValue));
                }
                this->scene->clear();
                this->scene->addPixmap(User::searchNode(this->opValue));
            }
        }
    }
}

void MainWindow::setItems(int val){
    items_traversal.push_back(val);
}

void MainWindow::setInsertItems(int val){
    items_insert.push_back(val);
}

void MainWindow::setDeleteHolder(int val){
    delete_holder.push_back(val);
}

void MainWindow::setSearchItems(int val){
    items_search.push_back(val);
}

void MainWindow::setSuccValue(int val){
    succValue = val;
}

void MainWindow::setSearchSig(int val)
{
    searchSig = val;
}

void MainWindow::setRootNode(bool check)
{
    rootNode = check;
}

void MainWindow::setSearchFound(bool check)
{
    searchFound = check;
}

vector<int> MainWindow::getInsertItems(){
    return items_insert;
}

vector<int> MainWindow::getSearchItems(){
    return items_search;
}

vector<int> MainWindow::getDeleteHolder(){
    return delete_holder;
}

int MainWindow::getSuccValue(){
    return succValue;
}

int MainWindow::getSearchSig()
{
    return searchSig;
}

bool MainWindow::isRootNode()
{
    return rootNode;
}

bool MainWindow::isSearchFound()
{
    return searchFound;
}

void MainWindow::on_BFTButton_2_clicked(){
    QString input = ui->tree_size->text();

    if(input.isEmpty())
        return;

    int nodes = input.toInt();
    if(nodes > 32){
        QMessageBox::information(NULL, "Information", "Graphviz cannot handle more than 32 nodes. Please decrease the amount.");
        return;
    }

    vector<int> tree = BinaryTreeGraphic::generateTree(nodes);
    this->scene->clear();
    this->scene->addPixmap(User::createTree(tree));
}

void MainWindow::on_insertButton_clicked(){
    this->items_insert.clear();
    this->items_search.clear();
    this->rootNode = false;
    vector<int> all;
    this->count = 0;
    this->doSignal = 2;

    all = User::readFile();

    QString input = ui->lineEdit_insert->text();
    if(input.isEmpty())
        return;
    int val = input.toInt();

    this->opValue = val;

    User::refreshTree(val);
    if (!all.empty()){
        User::searchNode(val);
        User::writeToFile(all);
    }
    else
        User::deleteNode(val);
    startTimer();
}

void MainWindow::on_deleteButton_clicked(){
    this->items_insert.clear();
    this->items_search.clear();
    this->delete_holder.clear();
    vector<int> all;
    this->count = 0;
    this->count2 = 0;
    this->switched = false;
    this->setSuccValue(-1);
    this->setSearchSig(0);

    all = User::readFile();
    QString input_delete = ui->lineEdit_delete->text();
    if(input_delete.isEmpty() || User::readFile().empty())
        return;
    int delVal = input_delete.toInt();

    this->doSignal = 3;
    this->opValue = delVal;

    this->opPixmap = User::deleteNode(delVal);
    User::writeToFile(all);
    startTimer();
}

void MainWindow::on_searchButton_clicked(){
    this->items_insert.clear();
    this->items_search.clear();
    this->count = 0;
    this->doSignal = 4;

    QString input_search = ui->lineEdit_search->text();
    if(input_search.isEmpty())
        return;
    int inpSearch = input_search.toInt();

    this->opValue = inpSearch;
    setSearchFound(true);

    User::searchNode(inpSearch);
    startTimer();
}

void MainWindow::on_bt_refresh_clicked(){
    this->scene->clear();
    this->scene->addPixmap(User::refreshTree());
}

void MainWindow::on_bt_reset_clicked(){
    this->scene->clear();
    this->scene->addPixmap(User::resetTree());
}

void MainWindow::on_BFTButton_clicked(){
    items_traversal.clear();
    count = 0;
    doSignal = 1;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 7);
    QString stringstring;
    for (int i : items_traversal){
        if (i == items_traversal[0])
            stringstring = stringstring + QString::number(i);
        else
            stringstring = stringstring + " > " + QString::number(i);
    }
    travers = new traversal(this);
    travers->traversalName("Breadth-First Traversal");
    travers->traversalInfo("How breadth-first traversal works: \n"
                           "It first enqueues the root of the tree. While "
                           "the queue is not empty, pop the topmost/fronstmost "
                           "element of the queue and insert it to a new variable. "
                           "It will then visit the node stored in the variable, then "
                           "finally enqueues the left child and the right child (if any).");
    travers->traversalSeq(stringstring);
    travers->setAttribute(Qt::WA_DeleteOnClose);
    int x = QApplication::activeWindow()->width() - ui->graphicsView->width() / 2;
    int y = QApplication::activeWindow()->height() - ui->graphicsView->height() / 2;
    travers->move(x, y);
    travers->show();
    startTimer();
}

void MainWindow::on_PreOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    doSignal = 1;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 8);
    QString stringstring;
    for (int i : items_traversal){
        if (i == items_traversal[0])
            stringstring = stringstring + QString::number(i);
        else
            stringstring = stringstring + " > " + QString::number(i);
    }
    travers = new traversal(this);
    travers->traversalName("Pre-Order Traversal");
    travers->traversalInfo("How pre-order traversal works: \n"
                           "It first recursively visits the left subtree by calling the pre-order function "
                           "and passing the left subtree as the parameter. Then it recursively visits the right "
                           "subtree by calling the function and passing the right subtree as the parameter. "
                           "Lastly, it visits the current node.");
    travers->traversalSeq(stringstring);
    travers->setAttribute(Qt::WA_DeleteOnClose);
    int x = QApplication::activeWindow()->width() - ui->graphicsView->width() / 2;
    int y = QApplication::activeWindow()->height() - ui->graphicsView->height() / 2;
    travers->move(x, y);
    travers->show();

    startTimer();
}

void MainWindow::on_InOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    doSignal = 1;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 9);
    QString stringstring;
    for (int i : items_traversal){
        if (i == items_traversal[0])
            stringstring = stringstring + QString::number(i);
        else
            stringstring = stringstring + " > " + QString::number(i);
    }
    travers = new traversal(this);
    travers->traversalName("In-Order Traversal");
    travers->traversalInfo("How in-order traversal works: \n"
                           "It first recursively visits the left subtree by calling the in-order function "
                           "and passing the left subtree as the parameter. Then it visits the current node. "
                           "Lastly, it recursively visits the right "
                           "subtree by calling the function and passing the right subtree as the parameter.");
    travers->traversalSeq(stringstring);
    travers->setAttribute(Qt::WA_DeleteOnClose);
    int x = QApplication::activeWindow()->width() - ui->graphicsView->width() / 2;
    int y = QApplication::activeWindow()->height() - ui->graphicsView->height() / 2;
    travers->move(x, y);
    travers->show();
    startTimer();
}

void MainWindow::on_PostOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    doSignal = 1;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 10);
    QString stringstring;
    for (int i : items_traversal){
        if (i == items_traversal[0])
            stringstring = stringstring + QString::number(i);
        else
            stringstring = stringstring + " > " + QString::number(i);
    }
    travers = new traversal(this);
    travers->traversalName("Post-Order Traversal");
    travers->traversalInfo("How post-order traversal works: \nIt first visits the current node, then "
                           "recursively visits the left subtree by calling the pre-order function "
                           "and passing the left subtree as the parameter. Lastly, it recursively visits the right "
                           "subtree by calling the function and passing the right subtree as the parameter.");
    travers->traversalSeq(stringstring);
    travers->setAttribute(Qt::WA_DeleteOnClose);
    int x = QApplication::activeWindow()->width() - ui->graphicsView->width() / 2;
    int y = QApplication::activeWindow()->height() - ui->graphicsView->height() / 2;
    travers->move(x, y);
    travers->show();
    startTimer();
}
