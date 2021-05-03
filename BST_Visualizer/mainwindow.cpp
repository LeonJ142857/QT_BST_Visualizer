#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene->setSceneRect(-1000, -1000, 2000, 2000);

    const QPointF SCENE_TOP_LEFT = QPointF(scene->sceneRect().topLeft());
    const qreal WIDTH = scene->sceneRect().width();
    const qreal HEIGHT = scene->sceneRect().height();

    QRectF Rec(SCENE_TOP_LEFT.x(), SCENE_TOP_LEFT.y(), WIDTH, HEIGHT);
    QPen redpen = QPen(Qt::red, 7);
    QLinearGradient grad(0, 0, 2000, 2000);

    grad.setColorAt(0.0, Qt::white);
    grad.setColorAt(1.0, Qt::lightGray);
    QBrush brush(grad);
    scene->addRect(Rec, redpen, brush);

<<<<<<< HEAD
    root = new BinaryTreeGraphic(this, 454);
    connect(ui->insertButton, SIGNAL(clicked()), root,
            SLOT(insert_node( (qreal) (ui->lineEdit_insert.text()) ))
            );
    connect(ui->deleteButton, SIGNAL(clicked()), root,
            SLOT(delete_node( (qreal) (ui->lineEdit_delete.text()) ))
            );
    connect(ui->insertButton, SIGNAL(clicked()), root,
            SLOT(search_node( (qreal) (ui->lineEdit_search.text()) ))
            );
=======
    root = new BinaryTreeGraphic(this, 5);
>>>>>>> 16fdaf6423cd57889cecbfa198a4118de69668cb

    connect(ui->insertButton, SIGNAL(clicked()), root, SLOT(insert_node((qreal)(ui->lineEdit_insert.text()))));
    connect(ui->deleteButton, SIGNAL(clicked()), root, SLOT(delete_node((qreal)(ui->lineEdit_delete.text()))));
    connect(ui->searchButton, SIGNAL(clicked()), root, SLOT(search_node((qreal)(ui->lineEdit_search.text()))));
    connect(ui->PreOrderButton, SIGNAL(clicked()), root, SLOT(DFTPreOrder()));
    connect(ui->BFTButton, SIGNAL(clicked()), root, SLOT(BFT()));
    connect(ui->InOrderButton, SIGNAL(clicked()), root, SLOT(DFTInOrder()));
    connect(ui->PostOrderButton, SIGNAL(clicked()), root, SLOT(DFTPostOrder()));

    root->get_graphic()->setPos(mapToParent(QPoint(0,0)));
    scene->addItem(root->get_graphic());

}

MainWindow::~MainWindow()
{
    delete ui;
}

