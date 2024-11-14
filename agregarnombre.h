#ifndef AGREGARNOMBRE_H
#define AGREGARNOMBRE_H

#include <QDialog>

namespace Ui {
class agregarNombre;
}

class agregarNombre : public QDialog
{
    Q_OBJECT

public:
    explicit agregarNombre(QWidget *parent = 0);
    ~agregarNombre();

public slots:
    QString nombre() const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::agregarNombre *ui;
};

#endif // AGREGARNOMBRE_H
