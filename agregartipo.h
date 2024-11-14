#ifndef AGREGARTIPO_H
#define AGREGARTIPO_H

#include <QDialog>

namespace Ui {
class agregarTipo;
}

class agregarTipo : public QDialog
{
    Q_OBJECT

public:
    explicit agregarTipo(QWidget *parent = 0);
    ~agregarTipo();

public slots:
    QString unidad() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::agregarTipo *ui;
};

#endif // AGREGARTIPO_H
