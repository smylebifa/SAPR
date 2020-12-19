#include "zadelka.h"
#include "ui_zadelka.h"

Zadelka::Zadelka(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Zadelka)
{
    ui->setupUi(this);
}

Zadelka::~Zadelka()
{
    delete ui;
}
