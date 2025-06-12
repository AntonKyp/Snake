#include <iostream>
#include <QApplication>

#include "MainWindow.h"


// run main function
int main(int argc, char* argv[]) {

    QApplication app(argc, argv);

    // TODO - load initial setting params!

    MainWindow window(nullptr);
    window.show();


    return app.exec();

}

// Then a menu screen - for this I need to implement text

// Then a settings screen

// finally the game screen


//########################################################
// implement the translation and rotation matrices
// implement the shaders in the Label class