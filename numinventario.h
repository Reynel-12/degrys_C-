#ifndef NUMINVENTARIO_H
#define NUMINVENTARIO_H

#include <QDialog>

namespace Ui {
class numInventario;
}

class numInventario : public QDialog
{
    Q_OBJECT

public:
    explicit numInventario(QWidget *parent = 0);
    ~numInventario();
    QString inventario() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::numInventario *ui;
};

#endif // NUMINVENTARIO_H
