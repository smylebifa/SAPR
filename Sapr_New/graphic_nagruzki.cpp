#include "graphic_nagruzki.h"
#include "ui_graphic_nagruzki.h"

Graphic_nagruzki::Graphic_nagruzki(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Graphic_nagruzki)
{
    ui->setupUi(this);
}

Graphic_nagruzki::~Graphic_nagruzki()
{
    delete ui;
}

void Graphic_nagruzki::on_pushButton_clicked()
{
    Graphic_nagruzki::close();
}
