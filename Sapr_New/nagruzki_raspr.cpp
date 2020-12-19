#include "nagruzki_raspr.h"
#include "ui_nagruzki_raspr.h"

nagruzki_raspr::nagruzki_raspr(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nagruzki_raspr)
{
    ui->setupUi(this);
}

nagruzki_raspr::~nagruzki_raspr()
{
    delete ui;
}

void nagruzki_raspr::on_pushButton_clicked()
{
    nagruz_r nagruza;
    QString ster=this->ui->label->text();
    QString f=this->ui->label_2->text();
    int nster=ster.toInt();
    int nf=f.toInt();
    nagruza.f=nf;
    nagruza.sterzhen=nster;
    Set(nagruza);
    nagruzki_raspr::close();
}
