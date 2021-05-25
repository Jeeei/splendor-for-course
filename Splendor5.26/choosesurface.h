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

    //显示函数
    void showImg1(QString);
    void showImg2(QString);
    void showImg3(QString);
    void showImg4(QString);

signals:
    void Start();
    void add();
    void subtract();
    void image1();
    void image2();
    void image3();
    void image4();
    void sequenceChange();
    void no1_clicked();
    void no2_clicked();
    void no3_clicked();
    void no4_clicked();
    void name1(QString);
    void name2(QString);
    //void name3(QString);
    //void name4(QString);

private slots:
    void on_start_clicked();

    void on_add_clicked();

    void on_subtract_clicked();

    void on_img1_clicked();

    void on_img2_clicked();

    void on_img3_clicked();

    void on_img4_clicked();

    void on_help_clicked();

    void on_haveRead_clicked();

    void on_sequence_clicked();

    void on_no1_clicked();

    void on_no2_clicked();

    void on_no3_clicked();

    void on_no4_clicked();

    void on_name1_editingFinished();

    void on_name2_editingFinished();

    //void on_name3_editingFinished();

    //void on_name4_editingFinished();

private:
    Ui::chooseSurface *ui;
    bool ifSequenceChange;

    ///////////////////////////////////1
    int nowNum=2;
};

#endif // CHOOSESURFACE_H
