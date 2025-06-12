#ifndef START_SCR
#define START_SCR

#include <QOpenGLFunctions_3_3_Core>

class StartScreen: protected QOpenGLFunctions_3_3_Core {
    public:

        ~StartScreen();

        void drawScreen();

        void initScreen();

    private:

        //OpenGL objects    
        unsigned int VAO, VBO, EBO;
        // shader program used by this screen
        unsigned int shaderProgram;
        unsigned int texture;
};


#endif