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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_BFTButton_2_clicked()
{
    QString input = ui->tree_size->text();
    int nodes = input.toInt();

    cout << nodes;

    vector<int> tree = BinaryTreeGraphic::generateTree(nodes);
    QPixmap pixmap = User::createTree(tree);
    this->scene->clear();
    this->scene->addPixmap(pixmap);
}


