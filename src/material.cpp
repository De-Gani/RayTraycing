#include"material.hpp"


material::material(int shine,vector difuse, vector specular, vector color)
{
    shininess = shine;
    difuseColor = difuse;
    specularColor = specular;
    colour=color;
};