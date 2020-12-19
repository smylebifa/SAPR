#ifndef NAGRUZKI_H
#define NAGRUZKI_H

#include <QDialog>
#include<nagruz.h>
namespace Ui {
class Nagruzki;
}

class Nagruzki : public QDialog
{
    Q_OBJECT

public:
    explicit Nagruzki(QWidget *parent = 0);
    ~Nagruzki();
    nagruzka Get()
    {
        return nagruza;
    }
    void Set(nagruzka nagr)
    {
        nagruza=nagr;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Nagruzki *ui;
    nagruzka nagruza;

};

#endif // NAGRUZKI_H
