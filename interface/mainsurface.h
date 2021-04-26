#ifndef MAINSURFACE_H
#define MAINSURFACE_H

#include <QWidget>
#include "gameinterface.h"

namespace Ui {
class mainSurface;
}

class mainSurface : public QWidget
{
    Q_OBJECT

public:
    explicit mainSurface(QWidget *parent = 0);
    ~mainSurface();

private slots:
    void on_start_button_clicked();

    void on_rule_button_clicked();

private:
    Ui::mainSurface *ui;
};

#endif // MAINSURFACE_H
