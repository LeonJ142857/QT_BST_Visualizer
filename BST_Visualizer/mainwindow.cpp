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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    scene->addPixmap(User::resetTree());
    this->timer = new QTimer(this);
//    connect(ui->PreOrderButton, SIGNAL(clicked()), this, SLOT(startTimer()));
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTree()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Node* MainWindow::getItems(int val){
//    return items[val];
//}

//vector<Node*> MainWindow::getItems(){
//    return items;
//}

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
    this->scene->clear();
    this->scene->addPixmap(User::searchNode(items_traversal[count]));
//    QString s = QString::number(items_traversal[count]);
//    QMessageBox::information(NULL, "info", s);
    count++;
    if (count == items_traversal.size()){
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
    }
}

void MainWindow::setItems(int val){
        items_traversal.push_back(val);
}

void MainWindow::on_BFTButton_2_clicked()
{
    QString input = ui->tree_size->text();

    if(input.isEmpty())
        return;

    int nodes = input.toInt();
    if(nodes > 32){
        QMessageBox::information(NULL, "Information", "Graphviz cannot handle more than 32 nodes. Please decrease the amount.");
        return;
    }

    cout << nodes;

    vector<int> tree = BinaryTreeGraphic::generateTree(nodes);
    this->scene->clear();
    this->scene->addPixmap(User::createTree(tree));
}



void MainWindow::on_insertButton_clicked(){
    QString input = ui->lineEdit_insert->text();
    if(input.isEmpty())
        return;
    int val = input.toInt();
    this->scene->clear();
    this->scene->addPixmap(User::refreshTree(val));
}

void MainWindow::on_deleteButton_clicked(){
    QString input_delete = ui->lineEdit_delete->text();
    if(input_delete.isEmpty())
        return;
    int delVal = input_delete.toInt();
    this->scene->clear();
    this->scene->addPixmap(User::deleteNode(delVal));
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

}

void MainWindow::on_PreOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 8);
    QString stringstring;
    for (int i : items_traversal){
        stringstring = stringstring + ", " + QString::number(i);
    }
    QMessageBox::information(NULL, "Pre-Order Traversal" , "Pre-Order traversal sequence = " + stringstring);
    startTimer();
}

void MainWindow::on_InOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 9);
    QString stringstring;
    for (int i : items_traversal){
        stringstring = stringstring + ", " + QString::number(i);
    }
    QMessageBox::information(NULL, "In-Order Traversal" , "In-Order traversal sequence = " + stringstring);
    startTimer();
}

void MainWindow::on_PostOrderButton_clicked(){
    items_traversal.clear();
    count = 0;
    vector<int> userTree = User::readFile();
    User::createTree(userTree, 10);
    QString stringstring;
    for (int i : items_traversal){
        stringstring = stringstring + ", " + QString::number(i);
    }
    QMessageBox::information(NULL, "Post-Order Traversal" , "Post-Order traversal sequence = " + stringstring);
    startTimer();
}
