#ifndef CHECK_H
#define CHECK_H

#include <QDialog>
#include<sterzhen.h>
namespace Ui {
class Check;
}

class Check : public QDialog
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = 0);
    ~Check();
    void Set(sterzhen bar)
    {
        this->bar.push_back(bar);
    }
    sterzhen Get()
    {
        return bar.front();
    }
    void Pop()
    {
        bar.pop_front();
    }

    bool Empty()
    {
        if(bar.empty())
            return true;
        else return false;
    }

private slots:
    void on_pushButton_clicked();

private:
    Ui::Check *ui;
    std::list<sterzhen> bar;
};

#endif // CHECK_H
