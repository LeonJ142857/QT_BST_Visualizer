#include "traversal.h"
#include "ui_traversal.h"

Traversal::Traversal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Traversal)
{
    ui->setupUi(this);
}

Traversal::~Traversal()
{
    delete ui;
}

void Traversal::traversalSeq(QString travSequence){
    ui->label_graphtraversal->setText(travSequence);
}

void Traversal::traversalName(QString travName){
    ui->label_traversalname->setText(travName);
}

void Traversal::traversalInfo(QString travInfo){
    ui->label_traversalquickinfo->setText(travInfo);
}
