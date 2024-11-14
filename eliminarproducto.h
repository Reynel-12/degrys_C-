#ifndef ELIMINARPRODUCTO_H
#define ELIMINARPRODUCTO_H

#include <QDialog>

namespace Ui {
class eliminarProducto;
}

class eliminarProducto : public QDialog
{
    Q_OBJECT

public:
    explicit eliminarProducto(QWidget *parent = 0);
    ~eliminarProducto();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::eliminarProducto *ui;
};

#endif // ELIMINARPRODUCTO_H
