/********************************************************************************
** Form generated from reading UI file 'traversal.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVERSAL_H
#define UI_TRAVERSAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Traversal
{
public:
    QVBoxLayout *verticalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_traversalname;
    QSpacerItem *horizontalSpacer_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_2;
    QFrame *line;
    QLabel *label_2;
    QFrame *line_2;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_graphtraversal;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_traversalquickinfo;

    void setupUi(QDialog *traversal)
    {
        if (traversal->objectName().isEmpty())
            traversal->setObjectName(QString::fromUtf8("traversal"));
        traversal->resize(459, 321);
        traversal->setMinimumSize(QSize(0, 321));
        verticalLayout_5 = new QVBoxLayout(traversal);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame = new QFrame(traversal);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setMinimumSize(QSize(0, 61));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(72, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_traversalname = new QLabel(frame_2);
        label_traversalname->setObjectName(QString::fromUtf8("label_traversalname"));
        label_traversalname->setEnabled(false);
        label_traversalname->setMinimumSize(QSize(240, 0));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setItalic(false);
        label_traversalname->setFont(font);
        label_traversalname->setMouseTracking(false);
        label_traversalname->setTabletTracking(false);
        label_traversalname->setAcceptDrops(false);
        label_traversalname->setFrameShape(QFrame::WinPanel);
        label_traversalname->setAlignment(Qt::AlignCenter);
        label_traversalname->setIndent(-1);

        horizontalLayout->addWidget(label_traversalname);

        horizontalSpacer_2 = new QSpacerItem(71, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addWidget(frame_2);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_5 = new QFrame(frame_4);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        line = new QFrame(frame_5);
        line->setObjectName(QString::fromUtf8("line"));
        line->setMinimumSize(QSize(118, 0));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        label_2 = new QLabel(frame_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        line_2 = new QFrame(frame_5);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setMinimumSize(QSize(118, 0));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_2);


        verticalLayout_2->addWidget(frame_5);

        frame_6 = new QFrame(frame_4);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_graphtraversal = new QLabel(frame_6);
        label_graphtraversal->setObjectName(QString::fromUtf8("label_graphtraversal"));
        label_graphtraversal->setAlignment(Qt::AlignCenter);
        label_graphtraversal->setWordWrap(true);

        verticalLayout->addWidget(label_graphtraversal);


        verticalLayout_2->addWidget(frame_6);


        verticalLayout_3->addWidget(frame_4);

        frame_3 = new QFrame(frame);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setMinimumSize(QSize(421, 0));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_traversalquickinfo = new QLabel(frame_3);
        label_traversalquickinfo->setObjectName(QString::fromUtf8("label_traversalquickinfo"));
        label_traversalquickinfo->setMinimumSize(QSize(401, 0));
        label_traversalquickinfo->setAlignment(Qt::AlignCenter);
        label_traversalquickinfo->setWordWrap(true);

        verticalLayout_4->addWidget(label_traversalquickinfo);


        verticalLayout_3->addWidget(frame_3);


        verticalLayout_5->addWidget(frame);


        retranslateUi(traversal);

        QMetaObject::connectSlotsByName(traversal);
    } // setupUi

    void retranslateUi(QDialog *traversal)
    {
        traversal->setWindowTitle(QCoreApplication::translate("traversal", "Dialog", nullptr));
        label_traversalname->setText(QCoreApplication::translate("traversal", "Placeholder Traversal", nullptr));
        label_2->setText(QCoreApplication::translate("traversal", "Sequence", nullptr));
        label_graphtraversal->setText(QCoreApplication::translate("traversal", "4 > 5 > 2 > 3 > 22 > 23 > 54 > 53 > 2 > 323 > 2322 > 2", nullptr));
        label_traversalquickinfo->setText(QCoreApplication::translate("traversal", "Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'), and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.", nullptr));
    } // retranslateUi

};

namespace Ui{
    class Traversal: public Ui_Traversal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVERSAL_H
