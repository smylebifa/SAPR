#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QDialog>
#include<sterzhen.h>
#include<nagruz.h>
#include<nagruz_r.h>
#include<zadel.h>

namespace Ui {
class Processor;
}

class Processor : public QDialog
{
    Q_OBJECT

public:
    explicit Processor(QWidget *parent = 0);
    ~Processor();

    std::list<float> GetUx()
    {
        return Ux;
    }

    std::list<float> GetUp()
    {
        return Up;
    }

    void SetUx(float x)
    {
        Ux.push_back(x);
    }

    void SetUp(float x)
    {
        Up.push_back(x);
    }

    void Set(std::list<sterzhen> ster, zadel zadela,std::list<nagruzka> sosred,std::list<nagruz_r> raspr)
    {
        this->bar=ster;
        this->zadelka=zadela;
        this->raspredelenaya=raspr;
        this->sosredotochenaya=sosred;
    }
    void SetBar(sterzhen ster)
    {
        this->bar.push_back(ster);
    }
    void SetZadel(zadel zadela)
    {
        this->zadelka=zadela;
    }
    void SetNagruzkaS(std::list<nagruzka> sosred)
    {
        this->sosredotochenaya=sosred;
        this->sosredotochenaya2=sosred;
    }
    void SetNagruzkaR(std::list<nagruz_r> raspr)
    {
        this->raspredelenaya=raspr;
    }

    std::list<float> GetB()
    {
        return bx;
    }

    void SetA(float x)
    {
        A.push_back(x);
    }

    std::list<float> GetA()
    {
        return A;
    }


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Processor *ui;
    std::list<float> Ux;
    std::list<float> Up;
    std::list<sterzhen> bar;
    zadel zadelka;
    std::list<float> bx;
    std::list<float> A;
    std::list<nagruzka> sosredotochenaya2;
    std::list<nagruzka> sosredotochenaya;
    std::list<nagruz_r> raspredelenaya;

};

#endif // PROCESSOR_H
