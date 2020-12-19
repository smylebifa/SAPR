#include "postpreprocessor.h"
#include "ui_postpreprocessor.h"
#include<processor.h>
PostPreprocessor::PostPreprocessor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PostPreprocessor)
{
    ui->setupUi(this);
    this->trigger=0;
}

PostPreprocessor::~PostPreprocessor()
{
    delete ui;
}

void PostPreprocessor::on_pushButton_clicked()
{
    trigger++;

    if(trigger==3)
    {
        PostPreprocessor::close();
    }

    if(trigger==2)
    {
        QStandardItemModel *model = new QStandardItemModel;
            QStandardItem *item;

            //Заголовки столбцов
            QStringList horizontalHeader;
            QString si;

            for(int i=1;i<=B.size();i++)
            {
            si=QString::number(i);
            horizontalHeader.append("b"+si);
            }
            //Заголовки строк
            QStringList verticalHeader;
            verticalHeader.append("Значения");

            model->setHorizontalHeaderLabels(horizontalHeader);
            model->setVerticalHeaderLabels(verticalHeader);

            std::list<float> b;
            b=B;
            //Первый ряд
            for(int i=0;i<B.size();i++)
            {
            item = new QStandardItem(QString::number(b.front()));
            model->setItem(0, i, item);
            b.pop_front();
            }

            ui->tableView->setModel(model);

            ui->tableView->resizeRowsToContents();
            ui->tableView->resizeColumnsToContents();
    }

    if(trigger==1)
    {
        QStandardItemModel *model = new QStandardItemModel;
            QStandardItem *item;

            //Заголовки столбцов
            QStringList horizontalHeader;
            QString si;
            for(int i=1;i<=Ux.size();i++)
            {
            si=QString::number(i);
            horizontalHeader.append("U"+si);
            }
            //Заголовки строк
            QStringList verticalHeader;
            verticalHeader.append("Значения");

            model->setHorizontalHeaderLabels(horizontalHeader);
            model->setVerticalHeaderLabels(verticalHeader);

            std::list<float> U;
            U=Ux;
            //Первый ряд
            for(int i=0;i<Ux.size();i++)
            {
            item = new QStandardItem(QString::number(U.front()));
            model->setItem(0, i, item);
            U.pop_front();
            }

            ui->tableView->setModel(model);

            ui->tableView->resizeRowsToContents();
            ui->tableView->resizeColumnsToContents();
    }
}
