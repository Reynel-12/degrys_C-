#ifndef CONTRA_H
#define CONTRA_H

#include <QDialog>

namespace Ui {
class contra;
}

class contra : public QDialog
{
    Q_OBJECT

public:
    explicit contra(QWidget *parent = 0);
    ~contra();
    QString Contrasena() const;

private slots:
    void on_btnConfiCancel_accepted();

    void on_btnConfiCancel_rejected();

private:
    Ui::contra *ui;
};

#endif // CONTRA_H
