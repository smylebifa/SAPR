#ifndef CHOSE_H
#define CHOSE_H

#include <QDialog>

namespace Ui {
class Chose;
}

class Chose : public QDialog
{
    Q_OBJECT

public:
    explicit Chose(QWidget *parent = 0);
    ~Chose();
    bool Get()
    {
        return trigger;
    }

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Chose *ui;
    bool trigger;
};

#endif // CHOSE_H
