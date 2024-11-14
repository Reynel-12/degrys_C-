#ifndef AGREGARPRECIO_H
#define AGREGARPRECIO_H

#include <QDialog>

namespace Ui {
class agregarPrecio;
}

class agregarPrecio : public QDialog
{
    Q_OBJECT

public:
    explicit agregarPrecio(QWidget *parent = 0);
    ~agregarPrecio();

public slots:
    QString precio() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::agregarPrecio *ui;
};

#endif // AGREGARPRECIO_H
