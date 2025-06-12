#ifndef GL_LABEL
#define GL_LABEL

#include <string>
#include <QOpenGLFunctions_3_3_Core>

using namespace std;

class GLLabel : protected QOpenGLFunctions_3_3_Core {
    public:
        
        GLLabel(int height, int width, int posX, int posY);

        ~GLLabel();

        //init widgets GL objects
        void initWidget();

        void setText();

        void setColor(float red, float green, float blue);

        void drawLabel();

        void setEnabled(bool enabled);

    private:

        // properties - size and position
        int width, height, posX, posY;

        //Color
        float text_color[3];
        float bg_color[3];
        bool bg_enabled;

        //Text
        string text;

        //General openGL objects    
        unsigned int VAO_B, VBO_B, EBO_B;
        // shader programs used by this screen
        unsigned int shaderProgramBg, shaderProgramTxt;

        //helper function
        int getYindex(char c);
        int getXindex(char c);

};



#endif