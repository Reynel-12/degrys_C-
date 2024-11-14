#ifndef NUMEROFACTURA_H
#define NUMEROFACTURA_H

#include <QDialog>

namespace Ui {
class numeroFactura;
}

class numeroFactura : public QDialog
{
    Q_OBJECT

public:
    explicit numeroFactura(QWidget *parent = 0);
    ~numeroFactura();
    int numFactura() const;
    void cargarFact();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::numeroFactura *ui;
};

#endif // NUMEROFACTURA_H
