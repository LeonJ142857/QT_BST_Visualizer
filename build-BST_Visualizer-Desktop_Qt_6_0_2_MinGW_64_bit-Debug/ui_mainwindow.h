/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QHBoxLayout *horizontalLayout_9;
    QFrame *mainframe;
    QVBoxLayout *verticalLayout_3;
    QFrame *a_topframe;
    QHBoxLayout *horizontalLayout;
    QPushButton *insertButton;
    QLineEdit *lineEdit_insert;
    QPushButton *deleteButton;
    QLineEdit *lineEdit_delete;
    QPushButton *searchButton;
    QLineEdit *lineEdit_search;
    QFrame *b_middleframe;
    QHBoxLayout *horizontalLayout_7;
    QGraphicsView *graphicsView;
    QFrame *c_bottomframe;
    QHBoxLayout *horizontalLayout_8;
    QFrame *random_generate;
    QVBoxLayout *verticalLayout_2;
    QFrame *genlabel_frame;
    QHBoxLayout *horizontalLayout_5;
    QFrame *spacer1_rg;
    QLabel *TraversalLabel_2;
    QFrame *spacer2rg;
    QFrame *genline_frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *spacer1_rgl;
    QLineEdit *tree_size;
    QFrame *spacer2_rgl;
    QFrame *genbutton_frame;
    QHBoxLayout *horizontalLayout_6;
    QFrame *spacer1_rgb;
    QPushButton *BFTButton_2;
    QFrame *spacer2_rgb;
    QFrame *traversal_frame;
    QVBoxLayout *verticalLayout;
    QFrame *traversal_innerframe;
    QHBoxLayout *horizontalLayout_3;
    QFrame *spacer1_t;
    QLabel *TraversalLabel;
    QFrame *spacer2_t;
    QFrame *traversal_buttonframe;
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
        MainWindow->resize(659, 621);
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_9 = new QHBoxLayout(centralwidget);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        mainframe = new QFrame(centralwidget);
        mainframe->setObjectName(QString::fromUtf8("mainframe"));
        mainframe->setFrameShape(QFrame::StyledPanel);
        mainframe->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(mainframe);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        a_topframe = new QFrame(mainframe);
        a_topframe->setObjectName(QString::fromUtf8("a_topframe"));
        a_topframe->setMaximumSize(QSize(16777215, 50));
        a_topframe->setFrameShape(QFrame::StyledPanel);
        a_topframe->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(a_topframe);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        insertButton = new QPushButton(a_topframe);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));
        insertButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(insertButton);

        lineEdit_insert = new QLineEdit(a_topframe);
        lineEdit_insert->setObjectName(QString::fromUtf8("lineEdit_insert"));

        horizontalLayout->addWidget(lineEdit_insert);

        deleteButton = new QPushButton(a_topframe);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(deleteButton);

        lineEdit_delete = new QLineEdit(a_topframe);
        lineEdit_delete->setObjectName(QString::fromUtf8("lineEdit_delete"));

        horizontalLayout->addWidget(lineEdit_delete);

        searchButton = new QPushButton(a_topframe);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setCursor(QCursor(Qt::OpenHandCursor));

        horizontalLayout->addWidget(searchButton);

        lineEdit_search = new QLineEdit(a_topframe);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));

        horizontalLayout->addWidget(lineEdit_search);


        verticalLayout_3->addWidget(a_topframe);

        b_middleframe = new QFrame(mainframe);
        b_middleframe->setObjectName(QString::fromUtf8("b_middleframe"));
        b_middleframe->setMinimumSize(QSize(300, 400));
        b_middleframe->setFrameShape(QFrame::StyledPanel);
        b_middleframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(b_middleframe);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        graphicsView = new QGraphicsView(b_middleframe);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout_7->addWidget(graphicsView);


        verticalLayout_3->addWidget(b_middleframe);

        c_bottomframe = new QFrame(mainframe);
        c_bottomframe->setObjectName(QString::fromUtf8("c_bottomframe"));
        c_bottomframe->setFrameShape(QFrame::StyledPanel);
        c_bottomframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(c_bottomframe);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        random_generate = new QFrame(c_bottomframe);
        random_generate->setObjectName(QString::fromUtf8("random_generate"));
        random_generate->setMaximumSize(QSize(16777215, 115));
        random_generate->setFrameShape(QFrame::StyledPanel);
        random_generate->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(random_generate);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        genlabel_frame = new QFrame(random_generate);
        genlabel_frame->setObjectName(QString::fromUtf8("genlabel_frame"));
        genlabel_frame->setFrameShape(QFrame::StyledPanel);
        genlabel_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(genlabel_frame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        spacer1_rg = new QFrame(genlabel_frame);
        spacer1_rg->setObjectName(QString::fromUtf8("spacer1_rg"));
        spacer1_rg->setFrameShape(QFrame::StyledPanel);
        spacer1_rg->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(spacer1_rg);

        TraversalLabel_2 = new QLabel(genlabel_frame);
        TraversalLabel_2->setObjectName(QString::fromUtf8("TraversalLabel_2"));
        TraversalLabel_2->setEnabled(false);
        TraversalLabel_2->setMinimumSize(QSize(0, 0));
        TraversalLabel_2->setMaximumSize(QSize(160, 16777215));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        TraversalLabel_2->setFont(font);
        TraversalLabel_2->setMouseTracking(false);
        TraversalLabel_2->setTabletTracking(false);
        TraversalLabel_2->setAcceptDrops(false);
        TraversalLabel_2->setFrameShape(QFrame::WinPanel);
        TraversalLabel_2->setAlignment(Qt::AlignCenter);
        TraversalLabel_2->setIndent(-1);

        horizontalLayout_5->addWidget(TraversalLabel_2);

        spacer2rg = new QFrame(genlabel_frame);
        spacer2rg->setObjectName(QString::fromUtf8("spacer2rg"));
        spacer2rg->setFrameShape(QFrame::StyledPanel);
        spacer2rg->setFrameShadow(QFrame::Raised);

        horizontalLayout_5->addWidget(spacer2rg);


        verticalLayout_2->addWidget(genlabel_frame);

        genline_frame = new QFrame(random_generate);
        genline_frame->setObjectName(QString::fromUtf8("genline_frame"));
        genline_frame->setFrameShape(QFrame::StyledPanel);
        genline_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(genline_frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        spacer1_rgl = new QFrame(genline_frame);
        spacer1_rgl->setObjectName(QString::fromUtf8("spacer1_rgl"));
        spacer1_rgl->setFrameShape(QFrame::StyledPanel);
        spacer1_rgl->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(spacer1_rgl);

        tree_size = new QLineEdit(genline_frame);
        tree_size->setObjectName(QString::fromUtf8("tree_size"));
        tree_size->setMinimumSize(QSize(0, 20));
        tree_size->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_4->addWidget(tree_size);

        spacer2_rgl = new QFrame(genline_frame);
        spacer2_rgl->setObjectName(QString::fromUtf8("spacer2_rgl"));
        spacer2_rgl->setFrameShape(QFrame::StyledPanel);
        spacer2_rgl->setFrameShadow(QFrame::Raised);

        horizontalLayout_4->addWidget(spacer2_rgl);


        verticalLayout_2->addWidget(genline_frame);

        genbutton_frame = new QFrame(random_generate);
        genbutton_frame->setObjectName(QString::fromUtf8("genbutton_frame"));
        genbutton_frame->setFrameShape(QFrame::StyledPanel);
        genbutton_frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(genbutton_frame);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        spacer1_rgb = new QFrame(genbutton_frame);
        spacer1_rgb->setObjectName(QString::fromUtf8("spacer1_rgb"));
        spacer1_rgb->setFrameShape(QFrame::StyledPanel);
        spacer1_rgb->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(spacer1_rgb);

        BFTButton_2 = new QPushButton(genbutton_frame);
        BFTButton_2->setObjectName(QString::fromUtf8("BFTButton_2"));
        BFTButton_2->setMinimumSize(QSize(0, 25));
        BFTButton_2->setMaximumSize(QSize(100, 16777215));
        QFont font1;
        font1.setPointSize(9);
        BFTButton_2->setFont(font1);
        BFTButton_2->setCursor(QCursor(Qt::OpenHandCursor));
        BFTButton_2->setCheckable(true);
        BFTButton_2->setChecked(false);
        BFTButton_2->setFlat(false);

        horizontalLayout_6->addWidget(BFTButton_2);

        spacer2_rgb = new QFrame(genbutton_frame);
        spacer2_rgb->setObjectName(QString::fromUtf8("spacer2_rgb"));
        spacer2_rgb->setFrameShape(QFrame::StyledPanel);
        spacer2_rgb->setFrameShadow(QFrame::Raised);

        horizontalLayout_6->addWidget(spacer2_rgb);


        verticalLayout_2->addWidget(genbutton_frame);


        horizontalLayout_8->addWidget(random_generate);

        traversal_frame = new QFrame(c_bottomframe);
        traversal_frame->setObjectName(QString::fromUtf8("traversal_frame"));
        traversal_frame->setMaximumSize(QSize(16777215, 115));
        traversal_frame->setFrameShape(QFrame::StyledPanel);
        traversal_frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(traversal_frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        traversal_innerframe = new QFrame(traversal_frame);
        traversal_innerframe->setObjectName(QString::fromUtf8("traversal_innerframe"));
        traversal_innerframe->setMaximumSize(QSize(16777215, 50));
        traversal_innerframe->setFrameShape(QFrame::StyledPanel);
        traversal_innerframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(traversal_innerframe);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spacer1_t = new QFrame(traversal_innerframe);
        spacer1_t->setObjectName(QString::fromUtf8("spacer1_t"));
        spacer1_t->setFrameShape(QFrame::StyledPanel);
        spacer1_t->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(spacer1_t);

        TraversalLabel = new QLabel(traversal_innerframe);
        TraversalLabel->setObjectName(QString::fromUtf8("TraversalLabel"));
        TraversalLabel->setEnabled(false);
        TraversalLabel->setMinimumSize(QSize(50, 0));
        TraversalLabel->setFont(font);
        TraversalLabel->setMouseTracking(false);
        TraversalLabel->setTabletTracking(false);
        TraversalLabel->setAcceptDrops(false);
        TraversalLabel->setFrameShape(QFrame::WinPanel);
        TraversalLabel->setAlignment(Qt::AlignCenter);
        TraversalLabel->setIndent(-1);

        horizontalLayout_3->addWidget(TraversalLabel);

        spacer2_t = new QFrame(traversal_innerframe);
        spacer2_t->setObjectName(QString::fromUtf8("spacer2_t"));
        spacer2_t->setFrameShape(QFrame::StyledPanel);
        spacer2_t->setFrameShadow(QFrame::Raised);

        horizontalLayout_3->addWidget(spacer2_t);


        verticalLayout->addWidget(traversal_innerframe);

        traversal_buttonframe = new QFrame(traversal_frame);
        traversal_buttonframe->setObjectName(QString::fromUtf8("traversal_buttonframe"));
        traversal_buttonframe->setFrameShape(QFrame::StyledPanel);
        traversal_buttonframe->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(traversal_buttonframe);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        BFTButton = new QPushButton(traversal_buttonframe);
        BFTButton->setObjectName(QString::fromUtf8("BFTButton"));
        BFTButton->setMinimumSize(QSize(100, 45));
        BFTButton->setFont(font1);
        BFTButton->setCursor(QCursor(Qt::OpenHandCursor));
        BFTButton->setCheckable(true);
        BFTButton->setChecked(false);
        BFTButton->setFlat(false);

        horizontalLayout_2->addWidget(BFTButton);

        PreOrderButton = new QPushButton(traversal_buttonframe);
        PreOrderButton->setObjectName(QString::fromUtf8("PreOrderButton"));
        PreOrderButton->setMinimumSize(QSize(100, 45));
        PreOrderButton->setFont(font1);
        PreOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        PreOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(PreOrderButton);

        InOrderButton = new QPushButton(traversal_buttonframe);
        InOrderButton->setObjectName(QString::fromUtf8("InOrderButton"));
        InOrderButton->setMinimumSize(QSize(100, 45));
        InOrderButton->setFont(font1);
        InOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        InOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(InOrderButton);

        PostOrderButton = new QPushButton(traversal_buttonframe);
        PostOrderButton->setObjectName(QString::fromUtf8("PostOrderButton"));
        PostOrderButton->setMinimumSize(QSize(100, 45));
        PostOrderButton->setFont(font1);
        PostOrderButton->setCursor(QCursor(Qt::OpenHandCursor));
        PostOrderButton->setAutoFillBackground(false);
        PostOrderButton->setCheckable(true);

        horizontalLayout_2->addWidget(PostOrderButton);


        verticalLayout->addWidget(traversal_buttonframe);


        horizontalLayout_8->addWidget(traversal_frame);


        verticalLayout_3->addWidget(c_bottomframe);


        horizontalLayout_9->addWidget(mainframe);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 659, 21));
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

        BFTButton_2->setDefault(false);
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
        TraversalLabel_2->setText(QCoreApplication::translate("MainWindow", "Random Generate", nullptr));
        tree_size->setPlaceholderText(QCoreApplication::translate("MainWindow", "Tree size (how many nodes)", nullptr));
        BFTButton_2->setText(QCoreApplication::translate("MainWindow", "Generate Tree", nullptr));
        TraversalLabel->setText(QCoreApplication::translate("MainWindow", "Traversal", nullptr));
        BFTButton->setText(QCoreApplication::translate("MainWindow", "Breadth First\n"
"Traversal", nullptr));
        PreOrderButton->setText(QCoreApplication::translate("MainWindow", "Pre Order \n"
"Traversal", nullptr));
        InOrderButton->setText(QCoreApplication::translate("MainWindow", "In Order \n"
"Traversal", nullptr));
        PostOrderButton->setText(QCoreApplication::translate("MainWindow", "Post Order\n"
"Traversal", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
