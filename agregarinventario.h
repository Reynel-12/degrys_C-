#ifndef AGREGARINVENTARIO_H
#define AGREGARINVENTARIO_H

#include <QDialog>

namespace Ui {
class agregarInventario;
}

class agregarInventario : public QDialog
{
    Q_OBJECT

public:
    explicit agregarInventario(QWidget *parent = 0);
    ~agregarInventario();
    QString codigo() const;

private slots:
    void on_btnConfiCancel_accepted();

    void on_btnConfiCancel_rejected();

private:
    Ui::agregarInventario *ui;
};

#endif // AGREGARINVENTARIO_H
