#include "count_nagruzkas.h"
#include "ui_count_nagruzkas.h"

Count_NagruzkaS::Count_NagruzkaS(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Count_NagruzkaS)
{
    ui->setupUi(this);
}

Count_NagruzkaS::~Count_NagruzkaS()
{
    delete ui;
}

void Count_NagruzkaS::on_pushButton_clicked()
{
    QString x=this->ui->lineEdit->text();
    int nx=x.toInt();
    Set(nx);
    Count_NagruzkaS::close();
}
