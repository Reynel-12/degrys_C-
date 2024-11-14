#ifndef MODIFI_H
#define MODIFI_H

#include <QDialog>

namespace Ui {
class modifi;
}

class modifi : public QDialog
{
    Q_OBJECT

public:
    explicit modifi(QWidget *parent = 0);
    ~modifi();

    QString CodModi() const;

private slots:
    void on_btnConfiCancel_accepted();

    void on_btnConfiCancel_rejected();

private:
    Ui::modifi *ui;
};

#endif // MODIFI_H
