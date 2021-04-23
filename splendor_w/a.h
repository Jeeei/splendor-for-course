#ifndef A_H
#define A_H

#include <QMainWindow>

namespace Ui {
class GameInterface;
}

class GameInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameInterface(QWidget *parent = nullptr);
    ~GameInterface();

private:
    Ui::GameInterface *ui;
};

#endif // A_H
