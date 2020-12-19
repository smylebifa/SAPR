#include "check.h"
#include "ui_check.h"

Check::Check(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Check)
{
    ui->setupUi(this);

}

Check::~Check()
{
    delete ui;
}

void Check::on_pushButton_clicked()
{
    if(Empty())
        Check::close();
    sterzhen ster;
        ster=Get();
        ui->lineEdit->setText(QString::number(ster.l));
        ui->lineEdit_2->setText(QString::number(ster.a));
        ui->lineEdit_3->setText(QString::number(ster.e));
        ui->lineEdit_4->setText(QString::number(ster.u));
    Check::Pop();
}
