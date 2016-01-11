#ifndef WINDOWMANETTE_H
#define WINDOWMANETTE_H

#include <QMainWindow>
#include <QTimer>

#include "xinputGamepad.h"
#include "xqTblMgr.h"


namespace Ui {
class WindowManette;
}

class WindowManette : public QMainWindow
{
    Q_OBJECT

public:
    explicit WindowManette(QWidget *parent = 0);
    ~WindowManette();

private:
    Ui::WindowManette *ui;
    XInput input;
    QTimer tmr;

    QTimer tmr_ihm; //Timer de la sortie graphique
    QTimer tmr_bouton; // Timer pour les boutons -- Latence de 0,2s à mettre
    QTimer tmr_axes ;

    bool f_haveJoystick;
signals:
    void sig_Bouton( int ID);
    void sig_Axes( float, float, float, float);

public slots:
    void readJoystickState();
    void sendSignal(void);
    void sendAxes(void);
};

#endif // WINDOWMANETTE_H
