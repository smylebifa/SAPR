#include "nagruzki.h"
#include "ui_nagruzki.h"

Nagruzki::Nagruzki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nagruzki)
{
    ui->setupUi(this);
}

Nagruzki::~Nagruzki()
{
    delete ui;
}

void Nagruzki::on_pushButton_clicked()
{
    QString node=this->ui->lineEdit->text();
    QString prod=this->ui->lineEdit_2->text();
    int nnode=node.toInt();
    int nprod=prod.toInt();
    nagruzka nagruzk;
    nagruzk.node=nnode;
    nagruzk.prod=nprod;
    Set(nagruzk);
    Nagruzki::close();
}
