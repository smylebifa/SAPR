#include "count.h"
#include "ui_count.h"

Count::Count(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Count)
{
    ui->setupUi(this);
}

Count::~Count()
{
    delete ui;
}

void Count::on_pushButton_clicked()
{
    QString count=ui->lineEdit->text();
    this->count=count.toInt();
    Count::close();
}
