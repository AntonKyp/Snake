#ifndef GL_WIDGET
#define GL_WIDGET

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include "StartScreen.h"
#include <QTimer>

#define REF_RATE 20  // refresh every 20 ms
#define START_COUNT 250  //number of iterations before hidign the start screen

enum class ScreenType {start, main_menu, settings, game};


class GLWidget: public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {

    public:
    //constructor
    GLWidget();
    ~GLWidget();

    void setScreenType(ScreenType _type);

    private:

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
    void refresh();

    //game screens
    ScreenType type;
    StartScreen * start_menu;

    //timer for screen and game refresh
    QTimer refresh_timer;
    int time_counter;

};



#endif