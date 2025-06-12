#include "Label.h"

GLLabel::GLLabel(int _width, int _height, int _posX, int _posY){

    //init params
    width = _width;
    height = _height;
    posX = _posX;
    posY = _posY;

    //init color value
    bg_enabled = false;
    for (int i = 0; i < 3; i++)
    {
        text_color[i] = 0.0f;
        bg_color[i] = 0.0f;
    }

    //init text
    text = "";

};

void GLLabel::initWidget() {

    //create shaders -

    //vertext shader code for the background
	const char *vertShaderBg = "#version 420 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"uniform mat4 trans;\n"
		"uniform mat4 scale;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = scale*trans*vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

    //fragment shader code for the backgorund
	const char *fragShaderBg = "#version 330 core\n"
		"out vec4 FragColor;\n"
		"uniform vec4 color;\n"
		"void main()\n"
		"{\n"
		"   FragColor = color;\n"
		"}\n\0";

    //build and compile the background shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertShaderBg, NULL);
        glCompileShader(vertexShader);
        
        //build the fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader,1,&fragShaderBg,NULL);
        glCompileShader(fragmentShader);

        //link and build the shader program
        shaderProgramBg = glCreateProgram();
        glAttachShader(shaderProgramBg, vertexShader);
        glAttachShader(shaderProgramBg, fragmentShader);
        glLinkProgram(shaderProgramBg);

        //delete the inidividual programs
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);


    //text shader - TODO next

    //create vertices according to the size defintions

    //generate VAO

    //generate VBO

    //generate EBO

};

//
GLLabel::~GLLabel() {

    // delete buffers

};

void GLLabel::setText(){

    

};

void GLLabel::drawLabel() {



};

void GLLabel::setEnabled(bool enabled) {


};



int getYindex(char c);
int getXindex(char c);