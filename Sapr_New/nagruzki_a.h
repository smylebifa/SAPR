#ifndef NAGRUZKI_A_H
#define NAGRUZKI_A_H

#include <QDialog>
#include<nagruz.h>
#include<nagruzki.h>
#include<nagruzki_raspr.h>
namespace Ui {
class Nagruzki_A;
}

class Nagruzki_A : public QDialog
{
    Q_OBJECT

public:
    explicit Nagruzki_A(QWidget *parent = 0);
    ~Nagruzki_A();
    void Set_Sosred(nagruzka sosredot)
    {
        sosred.push_back(sosredot);
    }
    void Set_Raspr(nagruz_r raspred)
    {
        raspr.push_back(raspred);
    }

private:
    Ui::Nagruzki_A *ui;
    std::list<nagruzka> sosred;
    std::list<nagruz_r>raspr;
};

#endif // NAGRUZKI_A_H
