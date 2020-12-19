#ifndef COUNT_NAGRUZKAS_H
#define COUNT_NAGRUZKAS_H

#include <QDialog>

namespace Ui {
class Count_NagruzkaS;
}

class Count_NagruzkaS : public QDialog
{
    Q_OBJECT

public:
    explicit Count_NagruzkaS(QWidget *parent = 0);
    ~Count_NagruzkaS();
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
    Ui::Count_NagruzkaS *ui;
    int count;
};

#endif // COUNT_NAGRUZKAS_H
