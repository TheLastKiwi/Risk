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
    Ui::MainWindow *ui;
    Game *theGame;
    //Ui::MainWindow *u;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Game_triggered();

    void on_pushButton_clicked();

private:

};

#endif // MAINWINDOW_H
