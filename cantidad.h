#ifndef CANTIDAD_H
#define CANTIDAD_H

#include <QDialog>

namespace Ui {
class Cantidad;
}

class Cantidad : public QDialog
{
    Q_OBJECT

public:
    explicit Cantidad(QWidget *parent = 0);
    ~Cantidad();

    int cantidad() const;
private slots:
    void on_bxAceptar_accepted();

    void on_bxAceptar_rejected();

private:
    Ui::Cantidad *ui;
};

#endif // CANTIDAD_H
