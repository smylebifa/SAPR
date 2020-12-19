#include "count_nagruzkar.h"
#include "ui_count_nagruzkar.h"

Count_nagruzkaR::Count_nagruzkaR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Count_nagruzkaR)
{
    ui->setupUi(this);
}

Count_nagruzkaR::~Count_nagruzkaR()
{
    delete ui;
}

void Count_nagruzkaR::on_pushButton_clicked()
{
    QString x=this->ui->lineEdit->text();
    int xn=x.toInt();
    Set(xn);
    Count_nagruzkaR::close();
}
