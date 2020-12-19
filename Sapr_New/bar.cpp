#include "bar.h"
#include "ui_bar.h"

Bar::Bar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bar)
{
    ui->setupUi(this);
}

Bar::~Bar()
{
    delete ui;
}

void Bar::on_pushButton_clicked()
{
    QString l=ui->lineEdit->text();
    QString a=ui->lineEdit_2->text();
    QString e=ui->lineEdit_3->text();
    QString u=ui->lineEdit_4->text();
    int nl=l.toInt();
    int na=a.toInt();
    int ne=e.toInt();
    int nu=u.toInt();

    Set(nl,na,ne,nu);
    close();
}
