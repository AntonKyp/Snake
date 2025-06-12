#include "StartScreen.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

void StartScreen::initScreen() {

        //init openGL functions
        initializeOpenGLFunctions();

        // define the shaders to draw the logo
        const char *vertexShaderSource = "#version 420 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec2 aTexCoord;\n"
        "out vec2 TexCoord;\n"
        "void main()\n"
        "{\n"
        "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "TexCoord = vec2(aTexCoord.x, aTexCoord.y);\n"
        "}";
    
        const char *fragmentShaderSource = "#version 420 core\n"
        "out vec4 FragColor;\n"
        "in vec2 TexCoord;\n"
        "uniform sampler2D in_texture;\n"
        "void main()\n"
        "{\n"
        "FragColor = texture(in_texture, TexCoord);\n"
        "}\n";
    
        //build and compile the shader program
        
        
        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        
        //build the fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
        glCompileShader(fragmentShader);

        //link and build the shader program
        shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);

        //delete the inidividual programs
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // generate vertices for the game logo/texture
        float vertices[] = { -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,
                              0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
                              0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
                              -0.5f, -0.5f, 0.0f, 0.0f, 0.0f};

        unsigned int indices[] = {0,1,3,
                                  1,2,3};

        // generate vertex array object, vertex buffer object and element buffer object
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        //define the different vertex array attribues
        //vertex attribute
        glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        //texture coord attribute
        glVertexAttribPointer(1,2,GL_FLOAT, GL_FALSE, 5*sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        //unbind the VAO
        glBindVertexArray(0);
        glBindBuffer(GL_ARRAY_BUFFER,0);

        //load texture from file
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture); 

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        int img_width, img_heigth, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char * img_data = stbi_load("game_logo.png", &img_width, &img_heigth, &nrChannels, 0);

        if (img_data) 
        {

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_width, img_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, img_data);
            glGenerateMipmap(GL_TEXTURE_2D);
        }

        stbi_image_free(img_data);

};

//function 
void StartScreen::drawScreen() {

    //apply the shader
    glUseProgram(shaderProgram);

    //draw
    glBindVertexArray(VAO);

    // bind Texture
    glBindTexture(GL_TEXTURE_2D, texture);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    //unbind VAO
    glBindVertexArray(0); 


}

 
StartScreen::~StartScreen() {

    // TODO - this!!!

    //release both RAM and GPU allocated memory!

};


