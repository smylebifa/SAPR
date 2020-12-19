#ifndef BAR_H
#define BAR_H

#include <QDialog>
#include<sterzhen.h>

namespace Ui {
class Bar;
}

class Bar : public QDialog
{
    Q_OBJECT

public:
    explicit Bar(QWidget *parent = 0);
    ~Bar();
    sterzhen Get()
    {
        return bar;
    }
    void Set(int l,int a,int e,int u)
    {
        this->bar.a=a;
        this->bar.l=l;
        this->bar.e=e;
        this->bar.u=u;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bar *ui;
    sterzhen bar;
};

#endif // BAR_H
