#include "GLWidget.h"
#include <iostream>

GLWidget::GLWidget() {

    //create screens
    start_menu = new StartScreen();

    // menu screen - TODO

    // settings screen - TODO
    
    // game screen - TODO

    //set initial screen type
    type = ScreenType::start;

    //refresh timer to trigger refresh events
    connect(&refresh_timer, &QTimer::timeout, this, &GLWidget::refresh);

}

GLWidget::~GLWidget() {

    delete start_menu;

}

void GLWidget::initializeGL() {
    
    // init open GL functions
    initializeOpenGLFunctions();

    //TODO - init all types of screens if needed
    start_menu->initScreen();

    //start refresh timer
    refresh_timer.start(REF_RATE); 
    time_counter = 0;

    
}

//handle resize events
void GLWidget::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
}


void GLWidget::paintGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    switch(type){
        case ScreenType::start:
            start_menu->drawScreen();
            break;
        case ScreenType::main_menu:
            // TODO
            break;
        case ScreenType::settings:
            // TODO
            break;
        case ScreenType::game:
            // TODO
            break;
    }

}

//function sets the screen type to be presented
void GLWidget::setScreenType(ScreenType _type) {
    type = _type;
};


void GLWidget::refresh() {

    // implement a state machine
    switch(type) 
    {
        case ScreenType::start:
            if (time_counter < START_COUNT)
            {
                time_counter++;
            
            }
            else
            {
                type = ScreenType::main_menu;
            }
            break;
        case ScreenType::main_menu:
            //TODO
            break;
        case ScreenType::settings:
            //TODO
            break;
        case ScreenType::game:
            // TODO
            break;
    }

    //refresh screen
    update();
}