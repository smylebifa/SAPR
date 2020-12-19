#include "nagrizki_sosred.h"
#include "ui_nagrizki_sosred.h"

Nagrizki_sosred::Nagrizki_sosred(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nagrizki_sosred)
{
    ui->setupUi(this);
}

Nagrizki_sosred::~Nagrizki_sosred()
{
    delete ui;
}
