#include"sphere.hpp"
#include"math.h"
#include"iostream"

sphere::sphere(double radius,vector center, material mat) : shape(mat)
{   
    this->radius = radius;
    this->center = center;
}

vector sphere::getCenter()
{
    return center;
}

void sphere::setCenter(vector newCenter)
{
    this->center = newCenter;
}

int sign(int a)
{
    if (a < 0)
    {
        return -1;
    }
    return 1;
}


vector sphere::getNormal(vector pHit)
{
    return (pHit.substraction(center)).normalize();
}

vector sphere::calculateColor(vector pHit,light light)
{
    vector lightPosition = light.getPosition();
    vector lightIntensity = light.getColor();
    vector diffuseColor = this->getMaterial().getDifuseColor();
    vector specularColor = this->getMaterial().getSpecularColor();
    int shininess = this->getMaterial().getShininess();;
    //DIFUSE LIGHTING
    vector lightRay = (lightPosition.substraction(pHit)).normalize();
    vector normal = getNormal(pHit).normalize();
    vector diffuse = (diffuseColor.time(lightIntensity)).multiply(std::max(0.0,lightRay.scalar(normal)));

    //SPECULAR
    vector reflection = ((normal.multiply(2*lightRay.scalar(normal))).substraction(lightRay)).normalize();
    double maxCalc = std::max(0.0,reflection.scalar((pHit.multiply(-1)).normalize()));
    vector specular = (specularColor.time(lightIntensity)).multiply(pow(maxCalc,shininess));

    //RECURSIVE REFLECTION
    return specular + diffuse;
}

double sphere::isHit(ray Ray3f)
{
    vector L = center - Ray3f.getOrigin();
    double tca = L.scalar(Ray3f.getDirection());
    if (tca < 0)
    {
        return -1;
    }
    else
    {
        double s2 = (L.scalar(L)) - (tca*tca);
        double s = sqrt(s2);
        if(s>radius)
        {
            return -1;
        }
        else
        {
            double thc = sqrt((radius*radius) - s2);
            double t0 = tca -thc;
            return t0;
        }
    }
}