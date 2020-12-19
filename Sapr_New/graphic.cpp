#include "graphic.h"
#include "ui_graphic.h"

Graphic::Graphic(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic)
{
    ui->setupUi(this);
    nagruz=false;
    zadelka.l_zdel=false;
    zadelka.r_zadel=false;
}

Graphic::~Graphic()
{
    delete ui;
}

void Graphic::on_pushButton_clicked()
{
    Graphic::close();
}
