#ifndef GRAPHIC_NAGRUZKI_H
#define GRAPHIC_NAGRUZKI_H

#include <QDialog>

namespace Ui {
class Graphic_nagruzki;
}

class Graphic_nagruzki : public QDialog
{
    Q_OBJECT

public:
    explicit Graphic_nagruzki(QWidget *parent = 0);
    ~Graphic_nagruzki();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Graphic_nagruzki *ui;
};

#endif // GRAPHIC_NAGRUZKI_H
