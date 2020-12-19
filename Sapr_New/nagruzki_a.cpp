#include "nagruzki_a.h"
#include "ui_nagruzki_a.h"

Nagruzki_A::Nagruzki_A(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nagruzki_A)
{
    ui->setupUi(this);
}

Nagruzki_A::~Nagruzki_A()
{
    delete ui;
}
