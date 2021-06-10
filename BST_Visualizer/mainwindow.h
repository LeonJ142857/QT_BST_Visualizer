#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarytreegraphic.h"
#include <QLinearGradient>
#include <vector>
#include <traversal.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static void setItems(int val);
    static void setInsertItems(int val);
    static void setSearchItems(int val);
    static void setDeleteHolder(int val);
    static void setSuccValue(int val);
    static void setSearchSig(int val);
    static std::vector<int> getInsertItems();
    static std::vector<int> getSearchItems();
    static std::vector<int> getDeleteHolder();
    static int getSuccValue();
    static int getSearchSig();
    std::vector<int> findSuccessor(int val);
//    static Node* getItems(int val);
//    static std::vector<Node*> getItems();
//    void updateTree();
//    void startTimer();


private slots:
    void on_BFTButton_2_clicked();
    void on_insertButton_clicked();
    void on_deleteButton_clicked();
    void on_searchButton_clicked();
    void on_bt_refresh_clicked();
    void on_bt_reset_clicked();

    void on_BFTButton_clicked();

    void on_PreOrderButton_clicked();

    void on_InOrderButton_clicked();

    void on_PostOrderButton_clicked();
    void updateTree();
    void startTimer();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BinaryTreeGraphic *root;
    BinaryTreeGraphic *root2;
    QTimer *timer;
    QPixmap delPixmap;
    traversal *travers;
    static std::vector<int> items_traversal;
    static std::vector<int> items_insert;
    static std::vector<int> items_search;
    static std::vector<int> items_delete;
    static std::vector<int> delete_holder;
    static int succValue, searchSig;
    int count = 0;
    int count2 = 0;
    int doSignal, opValue, tempCount;
    bool switched = false;
};
#endif // MAINWINDOW_H
