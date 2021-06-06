#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarytreegraphic.h"
#include <QLinearGradient>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_BFTButton_2_clicked();
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void on_bt_refresh_clicked();
    void on_bt_reset_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BinaryTreeGraphic *root;
    BinaryTreeGraphic *root2;
    QTimer *timer;


};
#endif // MAINWINDOW_H
