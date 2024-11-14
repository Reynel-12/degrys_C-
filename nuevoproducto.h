#ifndef NUEVOPRODUCTO_H
#define NUEVOPRODUCTO_H

#include <QDialog>

namespace Ui {
class nuevoProducto;
}

class nuevoProducto : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoProducto(QWidget *parent = 0);
    ~nuevoProducto();

    QString codigo() const;
    QString nombre() const;
    QString unidad() const;
    QString inventario() const;
    QString precio() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::nuevoProducto *ui;
};

#endif // NUEVOPRODUCTO_H
