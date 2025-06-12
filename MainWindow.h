#ifndef MAIN_W
#define MAIN_W

#define DEF_W 800
#define DEF_H 800

#include <QMainWindow>
#include "GLWidget.h"

class MainWindow: public QMainWindow {
    public:

        //constructor
        MainWindow(QWidget *parent);

        //destructor
        ~MainWindow();

    private:
        //private function
        void showStartScreen();
        void openMainMenu();
        void startGame();
        void handleButton();

        //OpenGL Widget
        GLWidget * screen;

};


#endif