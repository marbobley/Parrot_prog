#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "windowmanette.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void openManette( void );
    void commandReceive(int ID);
    void commandeAxesReceive(float , float , float , float );

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    WindowManette *manette;

};

#endif // MAINWINDOW_H
