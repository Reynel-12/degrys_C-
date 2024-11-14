#ifndef INVENOPTIMO_H
#define INVENOPTIMO_H

#include "qstandarditemmodel.h"
#include <QDialog>

namespace Ui {
class invenOptimo;
}

class invenOptimo : public QDialog
{
    Q_OBJECT

public:
    explicit invenOptimo(QWidget *parent = nullptr);
    ~invenOptimo();
    void Abrir();
    void configurarEncabezados(QStandardItemModel *model);

private:
    Ui::invenOptimo *ui;
};

#endif // INVENOPTIMO_H
