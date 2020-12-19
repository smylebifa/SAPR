#ifndef GRAPHIC_H
#define GRAPHIC_H
#include<nagruz.h>
#include<nagruz_r.h>
#include <QDialog>
#include<QPainter>
#include<QWidget>
#include<sterzhen.h>
#include<zadel.h>
namespace Ui {
class Graphic;
}

class Graphic : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic(QWidget *parent = 0);
    ~Graphic();

    sterzhen Get()
    {
        return bar.front();
    }
    sterzhen Get_Back()
    {
        return bar.back();
    }

    bool Empty()
    {
        if(bar.empty())
            return true;
        else return false;
    }
    void Set_Zadelka(zadel zadela)
    {
        zadelka=zadela;
    }
    void SetNagruz()
    {
        nagruz=true;
    }
    void SetBar(sterzhen ster)
    {
        bar.push_back(ster);
    }
    void Set_Sosred(nagruzka sosredot)
    {
        this->sosred.push_back(sosredot);
    }
    void Set_Raspr(nagruz_r raspred)
    {
        this->raspred.push_back(raspred);
    }


    void paintEvent(QPaintEvent* event)
    {
        Q_UNUSED(event);
        QPainter painter;
        sterzhen ster;
        std::list<QRect> rect;
        int i=50;
        std::list<sterzhen> sters;
        sters=bar;
        while(!sters.empty())
        {
        ster=sters.front();
        sters.pop_front();
        QRect rect1(i,100,ster.l*20,ster.a*(-20));
        QRect rect2(i,100,ster.l*20,ster.a*(20));
        rect.push_back(rect1);
        rect.push_back(rect2);
        i=i+ster.l*20;
        }
        painter.begin(this);
        painter.setPen(Qt::black);
        while(!rect.empty())
        {
       // painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
        painter.drawRect(rect.front());
        rect.pop_front();

        }


        int count=0;
        if(zadelka.l_zdel)
        {
            ster=Get();
            int x=ster.a*(20);
            int j=100;
            while(count<x)
            {
            painter.drawLine(50,j,40,j-5);

            j=j-5;
            count=count+5;
            }
            count=0;
            j=100;
            while(count<x)
            {
            painter.drawLine(50,j,40,j-5);
            j=j+5;
            count=count+5;
            }
        }

        count=0;
        if(zadelka.r_zadel)
        {
            ster=Get_Back();
            int x=ster.a*(20);
            int j=100;
            while(count<x)
            {
            painter.drawLine(i,j,i+10,j-5);
            j=j-5;
            count=count+5;
            }
            j=100;
            count=0;
            while(count<x)
            {
            painter.drawLine(i,j,i+10,j-5);
            j=j+5;
            count=count+5;
            }

        }

        if(nagruz)
        {
        std::list<nagruzka> sosredot;
        sosredot=sosred;
        nagruzka sosredotoch;
        int node=0;        
        std::list<sterzhen> ster;
        sterzhen sterzh;

        while(!sosredot.empty())
        {
            sosredotoch=sosredot.front();
            sosredot.pop_front();
            ster=bar;

            if(sosredotoch.prod>0)
            {
                sterzh=ster.front();
                int length=0;
                node=sosredotoch.node;

                painter.setBrush(Qt::red);
                painter.setPen(Qt::red);

                if(node==1)
                {
                  painter.drawLine(20,100,50,100);
                  painter.drawLine(50,100,45,95);
                  painter.drawLine(50,100,45,105);
                }
                else if(node>1)
                {

                for(int i=1;i<node;i++)
                {
                    sterzh=ster.front();
                    ster.pop_front();
                    length=length+sterzh.l*20;
                }

                painter.drawLine(20+length,100,50+length,100);
                painter.drawLine(50+length,100,45+length,95);
                painter.drawLine(50+length,100,45+length,105);
                }

            }

            ster=bar;
            if(sosredotoch.prod<0)
            {
                sterzh=ster.front();
                int length=0;
                ster.pop_front();
                node=sosredotoch.node;
                length=length+sterzh.l*20;
                painter.setPen(Qt::blue);
                painter.setBrush(Qt::blue);

                  if(node==1)
                  {
                  painter.drawLine(50,100,70,100);
                  painter.drawLine(50,100,55,95);
                  painter.drawLine(50,100,55,105);
                  }

                  else if(node==2)
                  {
                   painter.drawLine(50+length,100,70+length,100);
                   painter.drawLine(50+length,100,55+length,95);
                   painter.drawLine(50+length,100,55+length,105);
                  }

                  else if(node>2)
                  {

                  for(int i=2;i<node;i++)
                  {
                    sterzh=ster.front();
                    ster.pop_front();
                    length=length+sterzh.l*20;
                  }

                  painter.drawLine(50+length,100,70+length,100);
                  painter.drawLine(50+length,100,55+length,95);
                  painter.drawLine(50+length,100,55+length,105);

                 }
            }


        }

        ster=bar;
        nagruz_r raspr;
        std::list<nagruz_r> raspredel;
        raspredel=raspred;
        while(!raspredel.empty())
        {
            raspr=raspredel.front();
            raspredel.pop_front();            

            if(raspr.f>0)
            {
                ster=bar;
                sterzh=ster.front();
                ster.pop_front();
                int length=0,length1,length2,length3;
                node=raspr.sterzhen;
                length=length+sterzh.l*20;
                painter.setPen(Qt::red);
                painter.setBrush(Qt::red);

                  if(node==1)
                  {
                      if(length%6==0)
                      {
                        length1=length/3;
                        length2=2*length/3;
                        length3=length;

                        painter.drawLine(50,100,50+length1,100);
                        painter.drawLine(50+length1,100,45+length1,95);
                        painter.drawLine(50+length1,100,45+length1,105);

                        painter.drawLine(50+length2,100,50+length3,100);
                        painter.drawLine(50+length3,100,45+length3,95);
                        painter.drawLine(50+length3,100,45+length3,105);

                      }
                      else
                      {

                          length1=2*length/5;
                          length2=length/5+length1;
                          length3=length;

                          painter.drawLine(50,100,50+length1,100);
                          painter.drawLine(50+length1,100,45+length1,95);
                          painter.drawLine(50+length1,100,45+length1,105);

                          painter.drawLine(50+length2,100,50+length3,100);
                          painter.drawLine(50+length3,100,45+length3,95);
                          painter.drawLine(50+length3,100,45+length3,105);

                      }
                  }

                  else if(raspr.sterzhen>1)
                  {

                  sterzh=ster.front();
                  int length_e,length1,length2,length3;

                  length=length+sterzh.l*20;
                  length_e=length;

                  for(int i=2;i<node;i++)
                  {
                    sterzh=ster.front();
                    ster.pop_front();
                    length_e=length_e+sterzh.l*20;
                    length=length+sterzh.l*20;
                  }

                  length_e=length_e-sterzh.l*20;


                  if((length-length_e)%6==0)
                  {
                    length1=length_e+(length-length_e)/3;
                    length2=length_e+2*(length-length_e)/3;
                    length3=length;

                    painter.drawLine(50+length_e,100,50+length1,100);
                    painter.drawLine(50+length1,100,45+length1,95);
                    painter.drawLine(50+length1,100,45+length1,105);

                    painter.drawLine(50+length2,100,50+length3,100);
                    painter.drawLine(50+length3,100,45+length3,95);
                    painter.drawLine(50+length3,100,45+length3,105);

                  }
                  else
                  {

                      length1=length_e+2*(length-length_e)/5;
                      length2=length1+(length-length_e)/5;
                      length3=length;

                      painter.drawLine(50+length_e,100,50+length1,100);
                      painter.drawLine(50+length1,100,45+length1,95);
                      painter.drawLine(50+length1,100,45+length1,105);

                      painter.drawLine(50+length2,100,50+length3,100);
                      painter.drawLine(50+length3,100,45+length3,95);
                      painter.drawLine(50+length3,100,45+length3,105);

                  }
                }



            }//f>0

            if(raspr.f<0)
            {
                ster=bar;
                sterzh=ster.front();
                ster.pop_front();
                int length=0,length1,length2,length3;
                node=raspr.sterzhen;
                length=length+sterzh.l*20;
                painter.setPen(Qt::blue);
                painter.setBrush(Qt::blue);

                  if(node==1)
                  {
                      if(length%6==0)
                      {
                        length1=length/3;
                        length2=2*length/3;
                        length3=length;

                        painter.drawLine(50,100,50+length1,100);
                        painter.drawLine(50,100,55,95);
                        painter.drawLine(50,100,55,105);

                        painter.drawLine(50+length2,100,50+length3,100);
                        painter.drawLine(50+length2,100,55+length2,95);
                        painter.drawLine(50+length2,100,55+length2,105);

                      }
                      else
                      {

                          length1=2*length/5;
                          length2=length/5+length1;
                          length3=length;

                          painter.drawLine(50,100,50+length1,100);
                          painter.drawLine(50+length1,100,55+length1,95);
                          painter.drawLine(50+length1,100,55+length1,105);

                          painter.drawLine(50+length2,100,50+length3,100);
                          painter.drawLine(50+length2,100,55+length2,95);
                          painter.drawLine(50+length2,100,55+length2,105);

                      }
                  }

                  else if(node>1)
                  {

                  sterzh=ster.front();
                  ster.pop_front();
                  int length_e,length1,length2,length3;

                  length=length+sterzh.l*20;
                  length_e=length;

                  for(int i=2;i<node;i++)
                  {
                    sterzh=ster.front();
                    ster.pop_front();
                    length_e=length_e+sterzh.l*20;
                    length=length+sterzh.l*20;
                  }

                  length_e=length_e-sterzh.l*20;


                  if((length-length_e)%6==0)
                  {
                    length1=length_e+(length-length_e)/3;
                    length2=length_e+2*(length-length_e)/3;
                    length3=length;

                    painter.drawLine(50+length_e,100,50+length1,100);
                    painter.drawLine(50+length_e,100,55+length_e,95);
                    painter.drawLine(50+length_e,100,55+length_e,105);

                    painter.drawLine(50+length2,100,50+length3,100);
                    painter.drawLine(50+length2,100,55+length2,95);
                    painter.drawLine(50+length2,100,55+length2,105);

                  }
                  else
                  {

                      length1=length_e+2*(length-length_e)/5;
                      length2=length1+(length-length_e)/5;
                      length3=length;

                      painter.drawLine(50+length_e,100,50+length1,100);
                      painter.drawLine(50+length_e,100,55+length_e,95);
                      painter.drawLine(50+length_e,100,55+length_e,105);

                      painter.drawLine(50+length2,100,50+length3,100);
                      painter.drawLine(50+length2,100,55+length2,95);
                      painter.drawLine(50+length2,100,55+length2,105);

                  }
                }

            }
            //f<0

         }//raspred

        }//nagruz

        painter.end();

    }


    std::list<sterzhen>GetBar()
    {
        return bar;
    }
    zadel GetZadelka()
    {
        return zadelka;
    }
    std::list<nagruzka> GetSosred()
    {
        return sosred;
    }
    std::list<nagruz_r> GetRaspred()
    {
        return raspred;
    }



private slots:

    void on_pushButton_clicked();

private:
    Ui::Graphic *ui;
    std::list<sterzhen> bar;
    zadel zadelka;
    bool nagruz;
    std::list<nagruzka>sosred;
    std::list<nagruz_r>raspred;
};

#endif // GRAPHIC_H
