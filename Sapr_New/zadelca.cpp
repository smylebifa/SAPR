#include "zadelca.h"
#include "ui_zadelca.h"

Zadelca::Zadelca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zadelca)
{
    ui->setupUi(this);
    this->zadelka.l_zdel=false;
    this->zadelka.r_zadel=false;
}

Zadelca::~Zadelca()
{
    delete ui;
}

void Zadelca::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        this->zadelka.l_zdel=true;
        Zadelca::close();

    }

    if(ui->checkBox_2->isChecked())
    {
        this->zadelka.r_zadel=true;
        Zadelca::close();

    }


}
