#include"plane.hpp"
#include"math.h"
#include"iostream"

plane::plane(vector normal, vector position, material mat) : shape(mat)
{
    this->normal = normal;
    this->position = position;
}

double plane::isHit(ray Ray3f)
{
    double denom = Ray3f.getDirection().scalar(normal);
    if(abs(denom) < 1e-6)
    {
        return 0;
    }
    else
    {
        vector tmp = position-Ray3f.getOrigin();
        double result = tmp.scalar(normal)/denom;       

        return result;
    }
}
    vector plane::calculateColor(vector pHit,light light)
    {
    vector lightPosition = light.getPosition();
    vector lightIntensity = light.getColor();
    vector diffuseColor = this->getMaterial().getDifuseColor();
    vector specularColor = this->getMaterial().getSpecularColor();
    int shininess = this->getMaterial().getShininess();;

    //DIFUSE LIGHTING
    vector lightRay = (lightPosition.substraction(pHit)).normalize();
    vector diffuse = (diffuseColor.time(lightIntensity)).multiply(std::max(0.0,lightRay.scalar(normal)));
    

    //SPECULAR
    vector reflection = ((normal.multiply(2*lightRay.scalar(normal))).substraction(lightRay)).normalize();
    double maxCalc = std::max(0.0,reflection.scalar((pHit.multiply(-1)).normalize()));
    vector specular = (specularColor.time(lightIntensity)).multiply(pow(maxCalc,shininess));
    return specular.add(diffuse);
    }


