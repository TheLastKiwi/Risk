#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
//#include "game.h"
class Game;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Game *theGame;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Game_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
