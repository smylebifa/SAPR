#include "processor.h"
#include "ui_processor.h"
#include <qmessagebox.h>
#include <cmath>

using namespace std;

float * gauss(float **a, float *y, int n)
{
  float *x, max;
  int k, index;
  const float eps = 0.001;  // точность
  x = new float[n];
  k = 0;
  while (k < n)
  {
    // Поиск строки с максимальным a[i][k]
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++)
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // Перестановка строк
   // if (max < eps)
   // {
   //   return 0;
   // }
    for (int j = 0; j < n; j++)
    {
      float temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    float temp = y[k];
    y[k] = y[index];
    y[index] = temp;
    // Нормализация уравнений
    for (int i = k; i < n; i++)
    {
      float temp = a[i][k];
      if (abs(temp) < eps) continue; // для нулевого коэффициента пропустить
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
      if (i == k)  continue; // уравнение не вычитать само из себя
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  // обратная подстановка
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return x;
}

Processor::Processor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Processor)
{
    ui->setupUi(this);
}

Processor::~Processor()
{
    delete ui;
}

void Processor::on_pushButton_clicked()
{
    Processor::close();
}

void Processor::on_pushButton_2_clicked()
{
    int count=0;
    std::list<sterzhen> ster;
    ster=bar;
    std::list<sterzhen> ster2;
    ster2=bar;
    sterzhen sterzen,sterzen2,sterzen3;
    std::list<nagruz_r>raspr=raspredelenaya;
    std::list<nagruz_r>raspr2=raspredelenaya;
    nagruz_r nagr_r;
    std::list<nagruzka> sosred=sosredotochenaya;
    nagruzka nagr_s;

    for(int i=0;i<ster.size();i++)
    {
        count++;
    }

    float **a,**f, *b, *t, *x, *Q, *delta;
    int n=count+1;
    a = new float*[n];
    b = new float[n];
    f = new float*[n];
    t = new float[n];
    Q = new float[n];
    delta=new float[n];


    for (int i = 0; i < n; i++)
      {
        a[i] = new float[n];
      }

    for (int i = 0; i < n; i++)
    {
        f[i] = new float[n];
    }

    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            f[i][j] = 0;
        }

    }

    for(int i=0;i<n;i++)
        Q[i]=0;


    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] = 0;
        }

    }

    sterzen2 =ster.front();
    sterzen3=ster2.front();

    a[0][0]=sterzen2.e*sterzen2.a/sterzen2.l;

    a[1][0]=-a[0][0];
    a[0][1]=a[1][0];

    if(zadelka.l_zdel)
    {
        a[1][0]=0;
        a[0][1]=0;
    }

    ster.pop_front();    

    for(int i=1;i<n-1;i++)
    {
        sterzen2=ster.front();
        sterzen3=ster2.front();
        a[i][i]=sterzen3.e*sterzen3.a/sterzen3.l+sterzen2.e*sterzen2.a/sterzen2.l;
        a[i+1][i]=(-1)*sterzen2.e*sterzen2.a/sterzen2.l;
        a[i][i+1]=a[i+1][i];
        ster2.pop_front();
        ster.pop_front();
    }

    ster=bar;
    sterzen2=ster.back();

    a[n-2][n-1]=-1*sterzen2.e*sterzen2.a/sterzen2.l;
    a[n-1][n-2]=a[n-2][n-1];

    if(zadelka.r_zadel)
    {
        a[n-2][n-1]=0;
        a[n-1][n-2]=0;
    }

    a[n-1][n-1]=sterzen2.e*sterzen2.a/sterzen2.l;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            SetA(a[i][j]);
        }
    }


    for(int i=0;i<n;i++)
        b[i]=0;

    while(!sosred.empty())
    {
        int node=0;
        nagr_s=sosred.front();
        node=nagr_s.node;
        b[node-1]=b[node-1]+nagr_s.prod;
        sosred.pop_front();
    }

    ster=bar;

    int i=1;

    while(!raspr.empty())
    {
        int sterz=0;
        nagr_r=raspr.front();
        sterz=nagr_r.sterzhen;

        if(sterz==1)
        {
            Q[0]=nagr_r.f*ster.front().l/2;
            ster.pop_front();

        }
        else if(sterz==n-1)
        {
            Q[n-1]=nagr_r.f*ster.back().l/2;
            Q[n-2]=Q[n-1];
            ster.pop_back();
        }
        else
        {
            Q[i]=nagr_r.f*ster.front().l/2;
            i++;
            ster.pop_front();
        }

        raspr.pop_front();
    }

    for(int i=1;i<n-1;i++)
    {
        b[i]=b[i]+Q[i]+Q[i-1];
    }


    b[0]=b[0]+Q[0];
    b[n-1]=b[n-1]+Q[n-1];

    for(int i=0;i<n;i++)
    {
        bx.push_back(b[i]);
    }

    f[0][0]=1;
    f[1][1]=2;
    f[1][2]=-1;
    f[2][1]=-1;
    f[2][2]=1;

    t[0]=0;
    t[1]=-1.5;
    t[2]=0.5;

    x=gauss(f,t,3);


    for(int i=0;i<n;i++)
    {
        delta[i]=x[i];
    }

    if(zadelka.l_zdel==true)
    {
        delta[0]=0;
    }

    if(zadelka.r_zadel==true)
    {
        delta[n-1]=0;
    }

    //setUx
    for(int i=0;i<n;i++)
    {
    SetUx(delta[i]);
    SetUp(delta[i]);
    }


}

void Processor::on_pushButton_3_clicked()
{
    this->ui->label->setText(QString("A = "));

    if(!A.empty())
    {
        this->ui->label_2->setText(QString::number(A.front()));
        A.pop_front();
    }

}
