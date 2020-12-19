#ifndef NAGRIZKI_SOSRED_H
#define NAGRIZKI_SOSRED_H

#include <QDialog>

namespace Ui {
class Nagrizki_sosred;
}

class Nagrizki_sosred : public QDialog
{
    Q_OBJECT

public:
    explicit Nagrizki_sosred(QWidget *parent = 0);
    ~Nagrizki_sosred();

private:
    Ui::Nagrizki_sosred *ui;
};

#endif // NAGRIZKI_SOSRED_H
