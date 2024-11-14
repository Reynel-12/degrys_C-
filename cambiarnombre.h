#ifndef CAMBIARNOMBRE_H
#define CAMBIARNOMBRE_H

#include <QDialog>

namespace Ui {
class cambiarNombre;
}

class cambiarNombre : public QDialog
{
    Q_OBJECT

public:
    explicit cambiarNombre(QWidget *parent = 0);
    ~cambiarNombre();
    QString nombre() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::cambiarNombre *ui;
};

#endif // CAMBIARNOMBRE_H
