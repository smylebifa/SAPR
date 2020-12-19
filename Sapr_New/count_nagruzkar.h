#ifndef COUNT_NAGRUZKAR_H
#define COUNT_NAGRUZKAR_H

#include <QDialog>
#include<nagruz_r.h>
namespace Ui {
class Count_nagruzkaR;
}

class Count_nagruzkaR : public QDialog
{
    Q_OBJECT    

public:
    explicit Count_nagruzkaR(QWidget *parent = 0);
    ~Count_nagruzkaR();
     int Get()
     {
         return count;
     }
     void Set(int x)
     {
         count=x;
     }


private slots:
     void on_pushButton_clicked();

private:
    Ui::Count_nagruzkaR *ui;
    int count;

};

#endif // COUNT_NAGRUZKAR_H
