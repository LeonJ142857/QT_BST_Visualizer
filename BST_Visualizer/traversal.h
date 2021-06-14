#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <QDialog>

namespace Ui {
class Traversal;
}

class Traversal : public QDialog
{
    Q_OBJECT

public:
    explicit Traversal(QWidget *parent = nullptr);
    ~Traversal();
    void traversalSeq(QString travSequence);
    void traversalName(QString travName);
    void traversalInfo(QString travInfo);

private:
    Ui::Traversal *ui;
};

#endif // TRAVERSAL_H
