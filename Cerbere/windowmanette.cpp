#include "windowmanette.h"
#include "ui_windowmanette.h"

#include "ressource.h"

WindowManette::WindowManette(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowManette)
{
    ui->setupUi(this);

    f_haveJoystick = input.initInput(0);

    if (!f_haveJoystick)
    {
        this->setWindowTitle("Joystick OFF");
    }
    else
    {
        this->setWindowTitle("Joystick ON");
    }


    //TIMER POUR IHM
    if(f_haveJoystick)
    {
        tmr_ihm.setInterval(TIMER_IHM);
        connect(&tmr_ihm,SIGNAL(timeout()),this,SLOT(readJoystickState()));
        tmr_ihm.start();
    }

//     refresh timer interval (reads new values from )
    if (f_haveJoystick)
    {
        tmr_bouton.setInterval(TIMER_BOUTON);
        connect(&tmr_bouton,SIGNAL(timeout()),this,SLOT(sendSignal()));
        tmr_bouton.start();
    }

    //Timer Axes
    if(f_haveJoystick)
    {
        tmr_axes.setInterval(TIMER_AXES);
        connect(&tmr_axes,SIGNAL(timeout()),this,SLOT(sendAxes()));
        tmr_axes.start();
    }

}

void WindowManette::sendAxes()
{
    if (!input.updateState()) return;

    emit sig_Axes(input.getVertical(),input.getHorizontal(),input.getRotationZ(),input.getThrottle());
}

void WindowManette::sendSignal()
{
    if (!input.updateState()) return;

    // Output buttons' state
    // 17 boutons
    for (int r = 0; r < NOMBRE_BOUTON; r++)
    {
        bool isPressed = input.isKeyPressed(r);


        if(isPressed)
        {
            emit sig_Bouton(r);
        }
    }

}

void WindowManette::readJoystickState()
{
    if (!input.updateState()) return;

    ui->joystick_left->setValue((input.getRotationZ()+1.0f)*50.0f);
    ui->joystick_right->setValue((input.getHorizontal()+1.0f)*50.0f);

    // Output buttons' state
    // 17 boutons
    for (int r = 0; r < NOMBRE_BOUTON; r++)
    {
        bool isPressed = input.isKeyPressed(r);

       switch(r)
        {
           break;
        case BOUTON_CROIX:
            if(isPressed)
            {
                ui->joystick_croix->setChecked(true);
            }
            else  ui->joystick_croix->setChecked(false);
            break;
        case BOUTON_TRIANGLE:
            if(isPressed) ui->joystick_triangle->setChecked(true);
            else  ui->joystick_triangle->setChecked(false);
            break;
        case BOUTON_ROND:
            if(isPressed) ui->joystick_rond->setChecked(true);
            else  ui->joystick_rond->setChecked(false);
            break;
        case BOUTON_CARRE:
            if(isPressed) ui->joystick_carre->setChecked(true);
            else  ui->joystick_carre->setChecked(false);
            break;
        case BOUTON_HAUT:
            if(isPressed) ui->joystick_haut->setChecked(true);
            else  ui->joystick_haut->setChecked(false);
            break;
        case BOUTON_BAS:
            if(isPressed) ui->joystick_bas->setChecked(true);
            else  ui->joystick_bas->setChecked(false);
            break;
        case BOUTON_DROITE:
            if(isPressed) ui->joystick_droite->setChecked(true);
            else  ui->joystick_droite->setChecked(false);
            break;
        case BOUTON_GAUCHE:
            if(isPressed) ui->joystick_gauche->setChecked(true);
            else  ui->joystick_gauche->setChecked(false);
            break;
        case BOUTON_R2:
            if(isPressed) ui->joystick_R2->setChecked(true);
            else  ui->joystick_R2->setChecked(false);
            break;
        case BOUTON_R1:
            if(isPressed) ui->joystick_R1->setChecked(true);
            else  ui->joystick_R1->setChecked(false);
            break;
        case BOUTON_L1:
            if(isPressed) ui->joystick_L1->setChecked(true);
            else  ui->joystick_L1->setChecked(false);
            break;
        case BOUTON_L2:
            if(isPressed) ui->joystick_L2->setChecked(true);
            else  ui->joystick_L2->setChecked(false);
            break;
        }
    }
}


WindowManette::~WindowManette()
{
    delete ui;
}
