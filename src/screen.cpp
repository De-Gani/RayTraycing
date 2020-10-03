#include"screen.hpp"
#include<math.h>
#include<algorithm>
#include <cmath>

screen::screen(int ImgHeight,int ImgWidth,int NbrPixel, ray eye)
{
    this->ImgHeight = ImgHeight;
    this->ImgWidth = ImgWidth;
    this->NbrPixel = NbrPixel;
    this->eye = eye;
}


vector** screen::GeneratePointsOfScreen()
{
    vector** matOut = new vector*[ImgWidth];

    for(int i = 0; i < ImgWidth; i++) matOut[i] =new vector[ImgHeight];
    for (int i = 0; i < ImgWidth; i++)
    {
        for (int j = 0;  j< ImgHeight; j++)
        {
            double pixNormX = (i + 0.5) /ImgWidth;
            double pixNormY = (j + 0.5) /ImgHeight;
            double ImgRatio = ImgWidth/ImgHeight;
            double pixRemapX = (2*pixNormX - 1)*ImgRatio;
            double pixRemapY = 1-2*pixNormY;
            double fov = std::tan(((30*M_PI)/180)/2);
            double pixCameraX = pixRemapX*fov;
            double pixCameraY = pixRemapY*fov;
            vector cameraSpace = vector(pixCameraX,pixCameraY,-1);
            vector rayDirection = cameraSpace.substraction(vector(0,0,0));
            rayDirection = rayDirection.normalize();
            matOut[i][j]=rayDirection;
        }        
    }
    return matOut;
}