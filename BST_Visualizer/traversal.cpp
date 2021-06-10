#include "traversal.h"
#include "ui_traversal.h"

traversal::traversal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::traversal)
{
    ui->setupUi(this);
}

traversal::~traversal()
{
    delete ui;
}

void traversal::traversalSeq(QString travSequence){
    ui->label_graphtraversal->setText(travSequence);
}

void traversal::traversalName(QString travName){
    ui->label_traversalname->setText(travName);
}

void traversal::traversalInfo(QString travInfo){
    ui->label_traversalquickinfo->setText(travInfo);
}
