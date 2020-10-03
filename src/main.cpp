#include"math.h"
#include"iostream"
#include"sphere.hpp"
#include"screen.hpp"
#include<fstream>
#include<algorithm>
#include"plane.hpp"
#include"cube.hpp"
#include"light.hpp"
#include"render.hpp"

int main()
{
    //Defining a List of shapes for the Scene
    shape* shapeArray[6];   
    shapeArray[4] = new cube(4,vector(7.5,-1.0,-60),vector(1,1,1).normalize(),vector(1,-2,1).normalize(),material(128,vector(0.65,0.77,0.97),vector(0.7,0.7,0.7),vector(0.65,0.77,0.97)));
    shapeArray[2] = new sphere(2,vector(-5,-2,-40),material(128,vector(0.5,0.5,0.5),vector(0.7,0.7,0.7),vector(0.5,0.5,0.5)));
    shapeArray[1] = new sphere(4,vector(0,0,-50),material(128,vector(0.9,0.76,0.46),vector(0.7,0.7,0.7),vector(0.9,0.76,0.46)));
    shapeArray[0] = new plane(vector(0,1,0),vector(0,-4,0),material(0,vector(0.8,0.8,0.8),vector(0.2,0.2,0.2),vector(0.2,0.2,0.2)));
    shapeArray[3] = new sphere(3,vector(-5.5,0,-70),material(128,vector(0.65,0.77,0.97),vector(0.7,0.7,0.7),vector(0.65,0.77,0.97)));
    shapeArray[5] = new sphere(3,vector(-5.5,0,-70),material(128,vector(0.65,0.77,0.97),vector(0.7,0.7,0.7),vector(0.65,0.77,0.97)));

    //Defining the light for the scene
    light test = light(vector(0,20,-30),vector(1,1,1));
    light lights[2];
    lights[0] = light(vector(-10,20,-30),vector(0.5,0.5,0.5));
    lights[1] = light(vector(10,20,-30),vector(0.5,0.5,0.5));
    //Defining the images
    int height =4096;
    int width = 4096;
    int alpha = 8;
    vector** img = new vector*[width];
    for(int i = 0; i < width; i++) img[i] =new vector[height];

    vector** imgAnti = new vector*[width/(alpha/2)];
    for(int i = 0; i < width/(alpha/2); i++) imgAnti[i] =new vector[height/(alpha/2)];

    //Renders the image
    //render(test,shapeArray,img,height,width,sizeof(shapeArray)/sizeof(shapeArray[0]));
    render(test,shapeArray,img,height/(alpha/2),width/(alpha/2),sizeof(shapeArray)/sizeof(shapeArray[0]));
    renderWithAntiAliasing(test,shapeArray,imgAnti,height,width,sizeof(shapeArray)/sizeof(shapeArray[0]),alpha);   
/*
    for(int i = 0; i < sizeof(shapeArray)/sizeof(shapeArray[0]);i++)
    {
        delete shapeArray[i];
    }
    delete shapeArray;
    for(int i = 0; i < width; i++) delete img[i] ;
    
    delete img;
    */
    return 1;
}