#include "fake_glm.h"
#include <cmath>

using namespace std;



//function generates a 3d translation matrix which translates in x and y axis
// assuming given mat is of size 4x4 (MAT_SIZE)
void genTransMat(float posX, float posY,  float * mat) {

    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            if (i==j)
            {
                mat[i*MAT_SIZE + j] = 1;
            }
            else
            {

                mat[i*MAT_SIZE + j] = 0;

            }                

        }

        //x axis translation
        mat[MAT_SIZE - 1] = posX;

        //y axis translation
        mat[2*MAT_SIZE - 1] = posY;

    }

};

//function generates a 3d rotation matrix which performs rotation around the z axis
// assuming given mat is of size 4x4 (MAT_SIZE)
void getRotMat(float angle, float * mat) {

    //identity matrix
    for (int i = 0; i < MAT_SIZE; i++)
    {
        for (int j = 0; j < MAT_SIZE; j++)
        {
            if (i==j)
            {
                mat[i*MAT_SIZE + j] = 1;
            }
            else
            {

                mat[i*MAT_SIZE + j] = 0;

            }                

        }

        // convert angel to radians
        float rad = angle * M_PI / 180.0f;

        mat[0] = cos(rad);
        mat[1] = -sin(rad);
        mat[MAT_SIZE] = sin(rad);
        mat[MAT_SIZE + 1] = cos(rad);

        
};