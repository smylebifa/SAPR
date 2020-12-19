#ifndef NAGRUZKI_RASPR_H
#define NAGRUZKI_RASPR_H

#include <QDialog>
#include<nagruz_r.h>
namespace Ui {
class nagruzki_raspr;
}

class nagruzki_raspr : public QDialog
{
    Q_OBJECT

public:
    explicit nagruzki_raspr(QWidget *parent = 0);
    ~nagruzki_raspr();
    nagruz_r Get()
    {
        return nagruz;
    }
    void Set(nagruz_r nagruzka)
    {
        nagruz=nagruzka;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::nagruzki_raspr *ui;
    nagruz_r nagruz;
};

#endif // NAGRUZKI_RASPR_H
