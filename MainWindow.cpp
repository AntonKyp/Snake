#include "MainWindow.h"


//constructor
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent) {

    //use default values
    resize(DEF_W, DEF_H);

    //set the GLWidget as the central widget for the window
    screen = new GLWidget();
    setCentralWidget(screen);

};


//destructor
MainWindow::~MainWindow() {

    delete screen;

};


void MainWindow::showStartScreen() {

    //TODO

};


void MainWindow::openMainMenu() {
    
    //TODO


};


void MainWindow::startGame() {

    //TODO

};


void MainWindow::handleButton() {

    //TODO

};