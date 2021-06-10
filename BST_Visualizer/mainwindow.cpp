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

    if (this->doSignal == 1){
        if (count == 0)
            items_traversal.pop_back();
        this->scene->addPixmap(User::searchNode(items_traversal[count]));
        referenceVec = items_traversal;
    }
    else if (this->doSignal == 2){
        // do something that is related to insert animation;
        if (count == 0)
            items_insert = items_search;
        this->scene->addPixmap(User::searchNode(items_insert[count]));
        referenceVec = items_insert;
    }
    else if (this->doSignal == 3){
        if (count == 0)
            items_delete = items_search;
        if (getSuccValue() != -1){
            // do searchNode of successor value after iterator reached delVal.
            // set refVec to the size of the successor search vector.
            if (items_search[count-1] == getSuccValue()){
                this->scene->addPixmap(User::searchNode(items_search[count], delete_holder[0]));
                cout << getSuccValue();
                referenceVec = items_delete;
                if (count2 == 1)
                    referenceVec.clear();
                count2++;
            }
            else{
                this->scene->addPixmap(User::searchNode(items_search[count]));
                referenceVec = items_delete;
            }
        }
        else if (items_search[count] == items_search[items_search.size()-1] && !items_insert.empty()){
            if (count == 0){
                this->scene->addPixmap(User::searchNode(items_search[count]));
                this->switched = true;
            } else
                this->scene->addPixmap(User::searchNode(items_search[items_search.size()-1], items_insert[count2]));
            referenceVec = items_delete;
        }
        else {
            if (count-1 == 0 && this->switched)
                this->scene->addPixmap(User::searchNode(items_search[items_search.size()-1], items_insert[count2]));
            else
                this->scene->addPixmap(User::searchNode(items_search[count]));
            referenceVec = items_delete;
        }
    }

    count++;
    if (count >= referenceVec.size()+1){ // count == referenceVec.size()
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
    this->count = 0;
    this->doSignal = 2;
    QString input = ui->lineEdit_insert->text();
    if(input.isEmpty())
        return;
    int val = input.toInt();
    this->scene->clear();
    this->scene->addPixmap(User::refreshTree(val));
}

void MainWindow::on_deleteButton_clicked(){
    this->items_insert.clear();
    this->items_search.clear();
    this->delete_holder.clear();
    vector<int> all/*, temp*/;
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

    this->delPixmap = User::deleteNode(delVal);
    User::writeToFile(all);
    startTimer();
}

void MainWindow::on_searchButton_clicked(){
    QString input_search = ui->lineEdit_search->text();
    if(input_search.isEmpty())
        return;
    int inpSearch = input_search.toInt();
    this->scene->clear();
    this->scene->addPixmap(User::searchNode(inpSearch));
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
