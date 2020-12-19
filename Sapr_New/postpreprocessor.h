#ifndef POSTPREPROCESSOR_H
#define POSTPREPROCESSOR_H

#include <QDialog>
#include<qstandarditemmodel.h>
#include<QStandardItem>

namespace Ui {
class PostPreprocessor;
}

class PostPreprocessor : public QDialog
{
    Q_OBJECT

public:
    explicit PostPreprocessor(QWidget *parent = 0);
    ~PostPreprocessor();

    SetUx(std::list<float> Up)
    {
        this->Ux=Up;
    }
    SetB(std::list<float>b)
    {
        this->B=b;
    }


private slots:
    void on_pushButton_clicked();

private:
    Ui::PostPreprocessor *ui;
    std::list<float> Ux;
    std::list<float> B;
    int trigger;
};

#endif // POSTPREPROCESSOR_H
