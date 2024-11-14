#ifndef DESCUENTO_H
#define DESCUENTO_H

#include <QDialog>

namespace Ui {
class descuento;
}

class descuento : public QDialog
{
    Q_OBJECT

public:
    explicit descuento(QWidget *parent = 0);
    ~descuento();

    void setDatosCompartidos(const QString &datos);

public slots:
    void restarNumeros();
    int Descuento() const;
    int TotalDesc() const;
    int Total() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::descuento *ui;
};

#endif // DESCUENTO_H
