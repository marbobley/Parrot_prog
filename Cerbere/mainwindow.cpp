#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressource.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    manette = new WindowManette(this);

    QObject::connect(ui->pB_Manette, SIGNAL(clicked()), this, SLOT(openManette()));
    QObject::connect(manette, SIGNAL(sig_Bouton(int)), this, SLOT(commandReceive(int)));
    QObject::connect(manette, SIGNAL(sig_Axes(float,float,float,float)), this, SLOT(commandeAxesReceive(float,float,float,float)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openManette(void)
{

}

void MainWindow::commandReceive(int ID)
{
    if(ID == BOUTON_PLAY )
        manette->show();
    else if( ID == BOUTON_START )
        manette->hide();

}

void MainWindow::commandeAxesReceive(float g_v,float g_h,float d_v , float d_h)
{
    ui->horizontalSlider->setValue((1+g_h)*50);
    ui->verticalSlider->setValue((1-g_v)*50);
    ui->horizontalSlider_2->setValue((1+d_h)*50);
    ui->verticalSlider_2->setValue((1-d_v)*50);
}
