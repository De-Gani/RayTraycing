#ifndef RENDER_H
#define RENDER_H
#include"shape.hpp"
#include"vector.hpp"
#include"light.hpp"
/**
 * @brief Renders a given a list of Shapes and a Light 
 * 
 * @param light 
 * @param shapeArray 
 * @param img 
 * @param height 
 * @param width 
 * @param sizeShapeArray 
 */
void render(light light, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray);

/**
 * @brief Renders the scene a given a list of Shapes and and a list Lights
 * 
 * @param lights 
 * @param shapeArray 
 * @param img 
 * @param height 
 * @param width 
 * @param sizeShapeArray 
 */
void renderMultipleLight(light* lights, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray);


void antiAliasing(vector** &img,int height, int width);


void renderWithAntiAliasing(light light, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray,int AntiCoefficient);


#endif