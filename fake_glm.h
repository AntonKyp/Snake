#ifndef FGLM
#define FGLM

#define MAT_SIZE 4

// a collection of transformation matrices


//function generates a 3d translation matrix which translates in x and y axis
void genTransMat(float posX, float posY,  float * mat);

//function generates a 3d rotation matrix which performs rotation around the z axis
void getRotMat(float posX, float posY, float * mat);


#endif