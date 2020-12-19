#ifndef ZADELKA_H
#define ZADELKA_H

#include <QDialog>

namespace Ui {
class Zadelka;
}

class Zadelka : public QDialog
{
    Q_OBJECT

public:
    explicit Zadelka(QWidget *parent = 0);
    ~Zadelka();

private:
    Ui::Zadelka *ui;
};

#endif // ZADELKA_H
