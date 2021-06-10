#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <QDialog>

namespace Ui {
class traversal;
}

class traversal : public QDialog
{
    Q_OBJECT

public:
    explicit traversal(QWidget *parent = nullptr);
    ~traversal();
    void traversalSeq(QString travSequence);
    void traversalName(QString travName);
    void traversalInfo(QString travInfo);

private:
    Ui::traversal *ui;
};

#endif // TRAVERSAL_H
