#ifndef SELECCIONARCLIENTE_H
#define SELECCIONARCLIENTE_H

#include <QDialog>

namespace Ui {
class SeleccionarCliente;
}

class QSqlQueryModel;

class SeleccionarCliente : public QDialog
{
    Q_OBJECT

public:
    explicit SeleccionarCliente(QWidget *parent = 0);
    ~SeleccionarCliente();

    void abrirClientes();

public slots:
    QString codigoCliente() const;
    QString nombreCliente() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::SeleccionarCliente *ui;

    QSqlQueryModel *mModel;
};

#endif // SELECCIONARCLIENTE_H
