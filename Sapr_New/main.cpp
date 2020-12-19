#include "mainwindow.h"
#include <QApplication>
#include <count.h>
#include<bar.h>
#include<check.h>
#include<graphic.h>
#include<zadelca.h>
#include<nagruzki.h>
#include<count_nagruzkas.h>
#include<nagruzki_raspr.h>
#include<count_nagruzkar.h>
#include<nagruzki_a.h>
#include<fstream>
#include<chose.h>
#include<QFileDialog>
#include<QTextStream>
#include<string>
#include<processor.h>
#include<postpreprocessor.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Chose chose;
    chose.setModal(true);
    chose.exec();
    Processor processor;
    if(chose.Get())
    {
    std::ofstream out("savee.txt");
    Count count;
    bool trigger=false;
    while(!trigger)
    {
    Count count2;
    count2.show();
    count2.setModal(true);
    count2.exec();    
    if(count2.Get()>0)
    {
        count.Set(count2.Get());
        trigger=true;
    }
    }

    out<<count.Get()<<"e";

    Bar bar;
    Graphic graphic;
    for(int i=0;i<count.Get();i++)
    {
    bar.show();
    bar.setModal(true);
    bar.exec();    
    graphic.SetBar(bar.Get());
    out<<bar.Get().l<<"n"<<bar.Get().a<<"n"<<bar.Get().e<<"n"<<bar.Get().u<<"n"<<"t";
    }
    out<<"e";

    trigger=false;
    Zadelca zadelka;
    while(!trigger)
    {
    Zadelca zadelka2;
    zadelka2.show();
    zadelka2.setModal(true);
    zadelka2.exec();
    if(zadelka2.Get().l_zdel==true || zadelka2.Get().r_zadel==true)
    {
        trigger=true;
        zadelka.zadelka=zadelka2.zadelka;
    }
    }
    graphic.Set_Zadelka(zadelka.Get());
    graphic.paintEngine();
    graphic.setModal(true);
    graphic.exec();
    if(zadelka.zadelka.l_zdel==true)
        out<<"l";
    if(zadelka.zadelka.r_zadel==true)
        out<<"r";
    out<<"e";

    Nagruzki_A nagruzki;
    Count_NagruzkaS countS;
    countS.show();
    countS.setModal(true);
    countS.exec();
    graphic.SetNagruz();

    out<<countS.Get()<<"e";

    for(int i=0;i<countS.Get();i++)
    {
    Nagruzki nagruzka_sosred;
    nagruzka_sosred.setModal(true);
    nagruzka_sosred.exec();
    nagruzki.Set_Sosred(nagruzka_sosred.Get());
    graphic.Set_Sosred(nagruzka_sosred.Get());
    out<<nagruzka_sosred.Get().node<<"n"<<nagruzka_sosred.Get().prod<<"t";
    }

    Count_nagruzkaR countR;
    countR.show();
    countR.setModal(true);
    countR.exec();

    out<<countR.Get()<<"e";

    for(int i=0;i<countR.Get();i++)
    {
        nagruzki_raspr nagruzki_raspred;
        nagruzki_raspred.setModal(true);
        nagruzki_raspred.exec();
        nagruzki.Set_Raspr(nagruzki_raspred.Get());
        graphic.Set_Raspr(nagruzki_raspred.Get());
        out<<nagruzki_raspred.Get().sterzhen<<"n"<<nagruzki_raspred.Get().f<<"t";
    }

    graphic.paintEngine();
    graphic.setModal(true);
    graphic.exec();

    processor.setModal(true);
    processor.exec();

    out<<"z";
    out.close();

    std::ifstream in("savee.txt");
    std::string str;
    in>>str;
    QString tmpstr=QString::fromLocal8Bit(str.c_str());
  /*      std::ofstream out3("savef.txt");
    out3<<str;
    out3.close();
 */
    QString fileName=QFileDialog::getSaveFileName(0,("Save file"), "",
                                                  ("Files txt(*.txt)"));
    QFile file(fileName);
    file.open(QIODevice::ReadWrite|QIODevice::Text);
    QTextStream write(&file);
    write<<tmpstr;
    //out2(&file);
    //out2<<str;
    file.close();

    }


    if(!chose.Get())
    {
        QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
        QFile file(str);
        file.open(QIODevice::ReadWrite);

        QTextStream stream(& file);
        QString tmpstr;
        tmpstr=stream.readLine();

        Graphic graphic;
        graphic.SetNagruz();
        std::ofstream out("savee.txt");
        out<<tmpstr.toStdString();
        out.close();
        file.close();
        std::ifstream in("savee.txt");
        int count;
        in>>count;
        char z,s;
        in>>s;
        int l,e,u,a;
        for(int i=0;i<count;i++)
        {
        Bar ster;
        in>>l;
        in>>s;
        //if(s=='n')
        in>>a;
        in>>s;
        //if(s=='n')
        in>>e;
        in>>s;
        //if(s=='n')
        in>>u;
        in>>s;
        //if(s=='n')
        in>>s;
        //if(s=='t')
       // in>>s;
        ster.Set(l,a,e,u);
        graphic.SetBar(ster.Get());
        }

        in>>s;
        in>>s;

        zadel zadela;
        zadela.l_zdel=false;
        zadela.r_zadel=false;

        if(s=='l')
        {
        zadela.l_zdel=true;
        in>>s;
        if(s=='r')
        {
        zadela.r_zadel=true;
        in>>s;
        }
        }

        else if(s=='r')
        {
        zadela.r_zadel=true;
        in>>s;
        if(s=='l')
        {
        zadela.l_zdel=true;
        in>>s;
        }
        }

        graphic.Set_Zadelka(zadela);

        int x;
        in>>count;
        in>>s;
        for(int i=0;i<count;i++)
        {
            nagruzka sosred;
            in>>sosred.node;
            in>>s;
            in>>x;
            sosred.prod=x;
            in>>s;
            graphic.Set_Sosred(sosred);
            //in>>s;
        }
        if(count>0)
        in>>s;
        in>>count;     

        in>>s;
        for(int i=0;i<count;i++)
        {
            nagruz_r raspr;
            in>>raspr.sterzhen;
            in>>s;
            in>>x;
            raspr.f=x;
            in>>s;
            graphic.Set_Raspr(raspr);
        }
        in>>s;

        processor.SetNagruzkaR(graphic.GetRaspred());
        processor.SetNagruzkaS(graphic.GetSosred());
        processor.SetZadel(graphic.GetZadelka());

        std::list<sterzhen> bar;
        bar=graphic.GetBar();

        graphic.paintEngine();
        graphic.setModal(true);
        graphic.exec();

        while(!bar.empty())
        {
        sterzhen ster=bar.front();
        processor.SetBar(ster);
        bar.pop_front();
        }

        processor.setModal(true);
        processor.exec();

        PostPreprocessor postprocessor;

        postprocessor.SetUx(processor.GetUx());
        postprocessor.SetB(processor.GetB());

        postprocessor.setModal(true);
        postprocessor.exec();
    }

    return a.exec();
}

