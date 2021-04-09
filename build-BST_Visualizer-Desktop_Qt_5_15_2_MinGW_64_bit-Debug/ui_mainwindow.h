/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Window;
    QAction *actionUndo;
    QAction *actionRedo;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QLineEdit *lineEdit_insert;
    QPushButton *deleteButton;
    QLineEdit *lineEdit_delete;
    QPushButton *searchButton;
    QLineEdit *lineEdit_search;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *TraversalLabel;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *BFTButton;
    QPushButton *PreOrderButton;
    QPushButton *InOrderButton;
    QPushButton *PostOrderButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(700, 500);
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_3 = new QVBoxLayout(centralwidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(insertButton);

        lineEdit_insert = new QLineEdit(centralwidget);
        lineEdit_insert->setObjectName(QString::fromUtf8("lineEdit_insert"));

        horizontalLayout->addWidget(lineEdit_insert);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(deleteButton);

        lineEdit_delete = new QLineEdit(centralwidget);
        lineEdit_delete->setObjectName(QString::fromUtf8("lineEdit_delete"));

        horizontalLayout->addWidget(lineEdit_delete);

        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(searchButton);

        lineEdit_search = new QLineEdit(centralwidget);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));

        horizontalLayout->addWidget(lineEdit_search);


        verticalLayout_3->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_3->addWidget(graphicsView);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer_5);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        TraversalLabel = new QLabel(centralwidget);
        TraversalLabel->setObjectName(QString::fromUtf8("TraversalLabel"));
        TraversalLabel->setEnabled(false);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        TraversalLabel->setFont(font);
        TraversalLabel->setMouseTracking(false);
        TraversalLabel->setTabletTracking(false);
        TraversalLabel->setAcceptDrops(false);
        TraversalLabel->setFrameShape(QFrame::WinPanel);
        TraversalLabel->setAlignment(Qt::AlignCenter);
        TraversalLabel->setIndent(-1);

        verticalLayout_2->addWidget(TraversalLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        BFTButton = new QPushButton(centralwidget);
        BFTButton->setObjectName(QString::fromUtf8("BFTButton"));
        QFont font1;
        font1.setPointSize(9);
        BFTButton->setFont(font1);
        BFTButton->setCursor(QCursor(Qt::OpenHandCursor));
        BFTButton->setCheckable(true);
        BFTButton->setChecked(false);
        BFTButton->setFlat(false);

        horizontalLayout_2->addWidget(BFTButton);

        PreOrderButton = new QPushButton(centralwidget);
        PreOrderButton->setObjectName(QString::fromUtf8("PreOrderButton"));
        PreOrderButton->setFont(font1);
        PreOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        PreOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(PreOrderButton);

        InOrderButton = new QPushButton(centralwidget);
        InOrderButton->setObjectName(QString::fromUtf8("InOrderButton"));
        InOrderButton->setFont(font1);
        InOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        InOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(InOrderButton);

        PostOrderButton = new QPushButton(centralwidget);
        PostOrderButton->setObjectName(QString::fromUtf8("PostOrderButton"));
        PostOrderButton->setFont(font1);
        PostOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        PostOrderButton->setAutoFillBackground(false);
        PostOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(PostOrderButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 700, 20));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionNew_Window);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);

        retranslateUi(MainWindow);

        BFTButton->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("MainWindow", "New Window", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        TraversalLabel->setText(QCoreApplication::translate("MainWindow", "Traversal", nullptr));
        BFTButton->setText(QCoreApplication::translate("MainWindow", "Breadth First Traversal", nullptr));
        PreOrderButton->setText(QCoreApplication::translate("MainWindow", "Pre Order Traversal", nullptr));
        InOrderButton->setText(QCoreApplication::translate("MainWindow", "In Order Traversal", nullptr));
        PostOrderButton->setText(QCoreApplication::translate("MainWindow", "Post Order Traversal", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
