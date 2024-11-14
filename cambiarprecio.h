#ifndef CAMBIARPRECIO_H
#define CAMBIARPRECIO_H

#include <QDialog>

namespace Ui {
class cambiarPrecio;
}

class cambiarPrecio : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarPrecio(QWidget *parent = 0);
    ~cambiarPrecio();
    QString precio() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::cambiarPrecio *ui;
};

#endif // CAMBIARPRECIO_H
