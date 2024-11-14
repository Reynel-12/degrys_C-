#ifndef NUEVOCOD_H
#define NUEVOCOD_H

#include <QDialog>

namespace Ui {
class nuevoCod;
}

class nuevoCod : public QDialog
{
    Q_OBJECT

public:
    explicit nuevoCod(QWidget *parent = 0);
    ~nuevoCod();

    QString CodNew() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::nuevoCod *ui;
};

#endif // NUEVOCOD_H
