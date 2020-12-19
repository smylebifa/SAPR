#include "chose.h"
#include "ui_chose.h"

Chose::Chose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chose)
{
    ui->setupUi(this);
    trigger=true;
}

Chose::~Chose()
{
    delete ui;
}

void Chose::on_pushButton_clicked()
{
    trigger=true;
    Chose::close();
}

void Chose::on_pushButton_2_clicked()
{
    trigger=false;
    Chose::close();
}
