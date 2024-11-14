#ifndef CAMBIARUNIDAD_H
#define CAMBIARUNIDAD_H

#include <QDialog>

namespace Ui {
class cambiarUnidad;
}

class cambiarUnidad : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarUnidad(QWidget *parent = 0);
    ~cambiarUnidad();
    QString unidad() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::cambiarUnidad *ui;
};

#endif // CAMBIARUNIDAD_H
