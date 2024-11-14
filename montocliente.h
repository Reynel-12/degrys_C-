#ifndef MONTOCLIENTE_H
#define MONTOCLIENTE_H

#include <QDialog>

namespace Ui {
class montoCliente;
}

class montoCliente : public QDialog
{
    Q_OBJECT

public:
    explicit montoCliente(QWidget *parent = 0);
    ~montoCliente();

    void setDatosCompartidos(const QString &datos);

public slots:
    QString monto() const;

    void restarNumeros();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::montoCliente *ui;
};

#endif // MONTOCLIENTE_H
