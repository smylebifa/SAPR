#ifndef ZADELCA_H
#define ZADELCA_H

#include <QDialog>
#include<zadel.h>
namespace Ui {
class Zadelca;
}

class Zadelca : public QDialog
{
    Q_OBJECT

public:
    explicit Zadelca(QWidget *parent = 0);
    ~Zadelca();
    zadel Get()
    {
        return zadelka;
    }
zadel zadelka;
private slots:
    void on_pushButton_clicked();

private:
    Ui::Zadelca *ui;

};

#endif // ZADELCA_H
