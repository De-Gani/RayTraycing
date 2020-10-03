#include"render.hpp"
#include"screen.hpp"
#include"math.h"
#include"iostream"
#include<fstream>
#include<algorithm>

vector raytrace(light light, shape** shapeArray,ray Ray3f,int height, int width,int sizeShapeArray,int depth)
{
    vector reflectColour;
    vector out;
    int shapeHit = -1;
    int maxDepth = 3;
            double tMin = INFINITY;
            for (int k = 0; k < sizeShapeArray; k++)
            {
                //CALCULATION OF THE t AT WHICH THE SHAPE IS INTERSECTED BY RAY T = -1 IF NO INTERSECTIOn
                double t = shapeArray[k]->isHit(Ray3f);
                
                //SELECTION OF THE SMALLEST T TO HAVE THE FIRST SHAPE HIT
                if( t > 0.0 && t < tMin)
                {                    
                    tMin = t;
                    shapeHit = k;
                } 
            }
                //IF NO SHAPE IS HITTED SET COLOR TO COLOR OF BACKGROUND THIS CASE WHITE
                if (shapeHit == -1)
                {
                    return vector(1,1,1);
                }
                else
                {
                    int lightRayHitShape = -1;
                    vector pHit = Ray3f.pointHit(tMin);
                    //CALCULATING THE LIGHT RAY TO SEE IF IN SHADOW

                    ray lightRay = ray(pHit + (shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4)), (light.getPosition() - pHit).normalize());
                    double t0 = tMin;
                    for(int i = 0; i < sizeShapeArray;i++)
                    {
                        double lightingHit = shapeArray[i]->isHit(lightRay);
                        //SELECTION OF THE FIRST SHAPE HIT
                        if(lightingHit > 0 && lightingHit < t0)
                        {
                            t0 = lightingHit;
                            lightRayHitShape = i;
                        }    
                    }

                    //IF LIGHT RAY HITS SHAPE SET COLOR TO SHADOW
                    if(lightRayHitShape != -1 )
                    {
                        //SETTING COLOR TO A SHADOW DEPENDING ON THE MATERIAL FOR MOR REALISM
                        return shapeArray[lightRayHitShape]->getMaterial().getColor().time(vector(0.1,0.1,0.1).time(shapeArray[shapeHit]->getMaterial
                        ().getColor()));
                    }
                    else
                    {   //RECURSIVE CALL OF RAYTRACE WITH MAX DEPTH TO PREVENT INFINIT RAY BOUNCING
                        if((depth < maxDepth) && (shapeArray[shapeHit])->getMaterial().getShininess() > 0)
                        {
                            vector reflectionRayDirection = Ray3f.getDirection() - shapeArray[shapeHit]->getNormal(pHit).multiply(2*Ray3f.getDirection().scalar(shapeArray[shapeHit]->getNormal(pHit)));
                            vector reflectionRayOrigin = pHit + shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4);
                            reflectColour = reflectColour + raytrace(light,shapeArray,ray(reflectionRayOrigin,reflectionRayDirection),height,width,sizeShapeArray,depth + 1).multiply(0.15);
                            return reflectColour + shapeArray[shapeHit]->calculateColor(pHit,light);
                        }
                        return shapeArray[shapeHit]->calculateColor(pHit,light);
                    }
                }
}

void render(light light, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray)
{
    ray eye = ray(vector(0,0,0),vector(1,0,0));
    screen screen1 = screen(height,width,1,eye);
    vector** pointS1 = screen1.GeneratePointsOfScreen();
    //ITERATION THE THE PIXELS OF SCREEN
    for (int x = 0; x <width   ; x++)
    {
        for (int y = 0; y <height; y++)
        {
            ray Ray3f = ray(vector(0,0,0),pointS1[x][y]);
            //CALUCLATION OF COLOR USING RAY TRACING
            img[x][y] = raytrace(light,shapeArray,Ray3f,height,width,sizeShapeArray,0);
        }
    }
    //ADD COLOR TO .PPM FILE
    std::ofstream ofs("./compare.ppm",std::ios::out | std::ios::binary);
    ofs << "P6\n" << width <<  " " << height << "\n255\n";
    for (int y = 0; y <height  ; y++)
    {
        for (int x = 0; x <width; x++)
        {
            ofs << (unsigned char)(std::min((double)1, (double)img[x][y].getX())*255) << 
            (unsigned char)(std::min((double)1, (double)img[x][y].getY())*255) <<
            (unsigned char)(std::min((double)1, (double)img[x][y].getZ())*255); 
        }
    }
    for(int i = 0; i < width; i++) delete pointS1[i]; 
    delete pointS1;
}

vector raytraceMultiLight(light light, shape** shapeArray,ray Ray3f,int height, int width,int sizeShapeArray,int depth)
{
    vector reflectColour;
    vector out;
    int shapeHit = -1;
    int maxDepth = 3;
            double tMin = INFINITY;
            for (int k = 0; k < sizeShapeArray; k++)
            {
                //CALCULATION OF THE t AT WHICH THE SHAPE IS INTERSECTED BY RAY T = -1 IF NO INTERSECTIOn
                double t = shapeArray[k]->isHit(Ray3f);
                
                //SELECTION OF THE SMALLEST T TO HAVE THE FIRST SHAPE HIT
                if( t > 0.0 && t < tMin)
                {                    
                    tMin = t;
                    shapeHit = k;
                } 
            }
                //IF NO SHAPE IS HITTED SET COLOR TO COLOR OF BACKGROUND THIS CASE WHITE
                if (shapeHit == -1)
                {
                    return vector(1,1,1);
                }
                else
                {
                    int lightRayHitShape = -1;
                    vector pHit = Ray3f.pointHit(tMin);
                    //CALCULATING THE LIGHT RAY TO SEE IF IN SHADOW

                    ray lightRay = ray(pHit + (shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4)), (light.getPosition() - pHit).normalize());
                    double t0 = tMin;
                    for(int i = 0; i < sizeShapeArray;i++)
                    {
                        double lightingHit = shapeArray[i]->isHit(lightRay);
                        //SELECTION OF THE FIRST SHAPE HIT
                        if(lightingHit > 0 && lightingHit < t0)
                        {
                            t0 = lightingHit;
                            lightRayHitShape = i;
                        }    
                    }

                    //IF LIGHT RAY HITS SHAPE SET COLOR TO SHADOW
                    if(lightRayHitShape != -1 )
                    {
                        //SETTING COLOR TO A SHADOW DEPENDING ON THE MATERIAL FOR MOR REALISM
                        return shapeArray[lightRayHitShape]->getMaterial().getColor().time(vector(0.1,0.1,0.1).time(shapeArray[shapeHit]->getMaterial
                        ().getColor()));
                    }
                    else
                    {   //RECURSIVE CALL OF RAYTRACE WITH MAX DEPTH TO PREVENT INFINIT RAY BOUNCING
                        if((depth < maxDepth) && (shapeArray[shapeHit])->getMaterial().getShininess() > 0)
                        {
                            vector reflectionRayDirection = Ray3f.getDirection() - shapeArray[shapeHit]->getNormal(pHit).multiply(2*Ray3f.getDirection().scalar(shapeArray[shapeHit]->getNormal(pHit)));
                            vector reflectionRayOrigin = pHit + shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4);
                            reflectColour = reflectColour + raytrace(light,shapeArray,ray(reflectionRayOrigin,reflectionRayDirection),height,width,sizeShapeArray,depth + 1).multiply(0.15);
                            return reflectColour + shapeArray[shapeHit]->calculateColor(pHit,light);
                        }
                        return shapeArray[shapeHit]->calculateColor(pHit,light);
                    }
                }
}
/**
vector raytraceMultiLight(light* lights, shape** shapeArray,ray Ray3f,int height, int width,int sizeShapeArray,int depth)
{
    int numLights = 2;
    vector reflectColour;
    vector out;
    int shapeHit = -1;
    int maxDepth = 3;
            double tMin = INFINITY;
            for (int k = 0; k < sizeShapeArray; k++)
            {
                //CALCULATION OF THE t AT WHICH THE SHAPE IS INTERSECTED BY RAY T = -1 IF NO INTERSECTIOn
                double t = shapeArray[k]->isHit(Ray3f);
                
                //SELECTION OF THE SMALLEST T TO HAVE THE FIRST SHAPE HIT
                if( t > 0.0 && t < tMin)
                {                    
                    tMin = t;
                    shapeHit = k;
                } 
            }
                //IF NO SHAPE IS HITTED SET COLOR TO COLOR OF BACKGROUND THIS CASE WHITE
                if (shapeHit == -1)
                {
                    return vector(1,1,1);
                }
                else
                {   
                    int doesLightHit[numLights];
                    for(int i = 0; i < numLights; i++)
                    {  
                        doesLightHit[i] = -1;
                    }
                    int lightRayHitShape = -1;
                    vector pHit = Ray3f.pointHit(tMin);
                    //CALCULATING THE LIGHT RAY TO SEE IF IN SHADOW
                    for (int j = 0; j < numLights; j++)
                    {                                            
                        double t0 = tMin;
                        ray lightRay = ray(pHit + (shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4)), (lights[j].getPosition() - pHit).normalize());
                        for(int i = 0; i < sizeShapeArray;i++)
                        {
                            double lightingHit = shapeArray[i]->isHit(lightRay);
                            //SELECTION OF THE FIRST SHAPE HIT
                            if(lightingHit > 0 && lightingHit < t0)
                            {
                                t0 = lightingHit;
                                lightRayHitShape = i;
                                doesLightHit[j] = i;
                            }    
                        }
                    }
                    
                    //IF LIGHT RAY HITS SHAPE SET COLOR TO SHADOW NOTE THIS MEANS THE SHAPE IS HITTEN BY 0 LIGHT RAYS
                    int i;
                    for(i = 0; i < numLights+1; i++)
                    {
                        if(i == 1)
                        {
                            std::cout << "Casting second light\n";
                        }
                        if(doesLightHit[i] != -1 )
                        {
                            //SETTING COLOR TO A SHADOW DEPENDING ON THE MATERIAL FOR MORE REALISM
                            return shapeArray[lightRayHitShape]->getMaterial().getColor().time(vector(0.1,0.1,0.1).time(shapeArray[shapeHit]->getMaterial().getColor()));
                        }
                        else
                        {   
                            //RECURSIVE CALL OF RAYTRACE WITH MAX DEPTH TO PREVENT INFINIT RAY BOUNCING
                            if((depth < 1) && (shapeArray[shapeHit])->getMaterial().getShininess() > 0)
                            {
                                vector reflectionRayDirection = Ray3f.getDirection() - shapeArray[shapeHit]->getNormal(pHit).multiply(2*Ray3f.getDirection().scalar(shapeArray[shapeHit]->getNormal(pHit)));
                                vector reflectionRayOrigin = pHit + shapeArray[shapeHit]->getNormal(pHit).multiply(1e-4);
                                reflectColour = reflectColour + raytraceMultiLight(lights,shapeArray,ray(reflectionRayOrigin,reflectionRayDirection),height,width,sizeShapeArray,depth + 1).multiply(0.15);
                                reflectColour = reflectColour + shapeArray[shapeHit]->calculateColor(pHit,lights[i]);                                    
                                return reflectColour;
                            }
                            

                        }
   
                    }
                    reflectColour = reflectColour + shapeArray[shapeHit]->calculateColor(pHit,lights[i]);
                    return reflectColour;
                }
}
**/
void renderMultipleLight(light* lights, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray)
{
    ray eye = ray(vector(0,0,0),vector(1,0,0));
    screen screen1 = screen(height,width,1,eye);
    vector** pointS1 = screen1.GeneratePointsOfScreen();
    //ITERATION THE THE PIXELS OF SCREEN
    for (int x = 0; x <width   ; x++)
    {
        for (int y = 0; y <height; y++)
        {
            //CALUCLATION OF COLOR USING RAY TRACING
            for(int i = 0;i < 2;i++)
            { 
                ray Ray3f = ray(vector(0,0,0),pointS1[x][y]);
                img[x][y] = img[x][y] + raytrace(lights[i],shapeArray,Ray3f,height,width,sizeShapeArray,0);
            }
           

        }
    }
    //ADD COLOR TO .PPM FILE
    std::ofstream ofs("./multiLightFinal.ppm",std::ios::out | std::ios::binary);
    ofs << "P6\n" << width <<  " " << height << "\n255\n";
    for (int y = 0; y <height  ; y++)
    {
        for (int x = 0; x <width; x++)
        {
            ofs << (unsigned char)(std::min((double)1, (double)img[x][y].getX())*255) << 
            (unsigned char)(std::min((double)1, (double)img[x][y].getY())*255) <<
            (unsigned char)(std::min((double)1, (double)img[x][y].getZ())*255); 
        }
    }
    for(int i = 0; i < width; i++) delete pointS1[i]; 
    delete pointS1;
}

void antiAliasing(vector** &img,int height, int width)
{
   
    std::ofstream ofs("./antiAliasing.ppm",std::ios::out | std::ios::binary);
    ofs << "P6\n" << width/2 <<  " " << height/2 << "\n255\n";
    for (int y = 0; y <height-1  ; y+= 2)
    {
        for (int x = 0; x <width-1; x+=2)
        {
            ofs << (unsigned char)(((double)img[x][y].getX() + (double)img[x + 1][y].getX() + (double)img[x][y+1].getX() + (double)img[x + 1][y+1].getX())/4)  << 
            (unsigned char)(((double)img[x][y].getY() + (double)img[x + 1][y].getY() + (double)img[x][y+1].getY() + (double)img[x + 1][y+1].getY())/4) <<
            (unsigned char)(((double)img[x][y].getZ() + (double)img[x + 1][y].getZ() + (double)img[x][y+1].getZ() + (double)img[x + 1][y+1].getZ())/4) ; 
        }
    }
}

void renderWithAntiAliasing(light light, shape** shapeArray,vector** &img,int height, int width,int sizeShapeArray,int AntiCoefficient)
{
    ray eye = ray(vector(0,0,0),vector(1,0,0));
    screen screen1 = screen(height,width,1,eye);
    vector** pointS1 = screen1.GeneratePointsOfScreen();
    //ITERATION THE THE PIXELS OF SCREEN
    double coef = (double)1/AntiCoefficient; 

    for (int x = 0; x <width-AntiCoefficient/4    ; x+= AntiCoefficient/2)
    {
        for (int y = 0; y <height- AntiCoefficient/4; y+=AntiCoefficient/2)
        {
                for (int i = 0; i <= AntiCoefficient/4; i++)
                {
                    for (int j = 0; j <= AntiCoefficient/4;j++)
                    {
                        ray Ray3f = ray(vector(0,0,0),pointS1[x+i][y+j]);
                        img[x/(AntiCoefficient/2)][y/(AntiCoefficient/2)] = img[x/(AntiCoefficient/2)][y/(AntiCoefficient/2)] + raytrace(light,shapeArray,Ray3f,height,width,sizeShapeArray,0);  
                    }
                }
                img[x/(AntiCoefficient/2)][y/(AntiCoefficient/2)] = img[x/(AntiCoefficient/2)][y/(AntiCoefficient/2)].multiply((double)coef);
        }
    }
    //ADD COLOR TO .PPM FILE
    std::ofstream ofs("./test2AntiAliasing.ppm",std::ios::out | std::ios::binary);
    ofs << "P6\n" << width/(AntiCoefficient/2) <<  " " << height/(AntiCoefficient/2) << "\n255\n";
    for (int y = 0; y <height/(AntiCoefficient/2)  ; y++)
    {
        for (int x = 0; x <width/(AntiCoefficient/2); x++)
        {
            ofs << (unsigned char)(std::min((double)1, (double)img[x][y].getX())*255) << 
            (unsigned char)(std::min((double)1, (double)img[x][y].getY())*255) <<
            (unsigned char)(std::min((double)1, (double)img[x][y].getZ())*255); 
        }
    }
    for(int i = 0; i < width; i++) delete pointS1[i]; 
    delete pointS1;
}

