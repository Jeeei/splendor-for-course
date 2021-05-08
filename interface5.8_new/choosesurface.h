#ifndef CHOOSESURFACE_H
#define CHOOSESURFACE_H

#include <QWidget>

namespace Ui {
class chooseSurface;
}

class chooseSurface : public QWidget
{
    Q_OBJECT

public:
    explicit chooseSurface(QWidget *parent = 0);
    ~chooseSurface();

signals:
    void Start();

private slots:
    void on_start_clicked();

    void on_add_clicked();

    void on_subtract_clicked();

    void on_img1_released();

    void on_img2_clicked(bool checked);

    void on_img3_clicked();

    void on_img4_clicked();

private:
    Ui::chooseSurface *ui;
};

#endif // CHOOSESURFACE_H
