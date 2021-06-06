#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <binarytreegraphic.h>
#include <user.h>
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    scene->addPixmap(User::resetTree());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BFTButton_2_clicked()
{
    QString input = ui->tree_size->text();

    if(input.isEmpty())
        return;

    int nodes = input.toInt();

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
    this->scene->clear();
    this->scene->addPixmap(User::refreshTree());
}

void MainWindow::on_bt_refresh_clicked(){

}

void MainWindow::on_bt_reset_clicked(){

}
