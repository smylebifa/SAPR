#ifndef COUNT_H
#define COUNT_H

#include <QDialog>

namespace Ui {
class Count;
}

class Count : public QDialog
{
    Q_OBJECT

public:
    explicit Count(QWidget *parent = 0);
    ~Count();
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
    Ui::Count *ui;
    int count;
};

#endif // COUNT_H
