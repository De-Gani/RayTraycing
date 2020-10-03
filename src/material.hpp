#ifndef MATERIAL_H
#define MATERIAL_H
#include"vector.hpp"

/** @brief Material class. 

    This class simply represents an Object which is a Marterial for each Shape
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class material
{
private:
    int shininess = 0/**<initial Shininess of Material*/;
    vector difuseColor = vector(0,0,0)/**<initial diffuseColor vector of Material*/;
    vector specularColor = vector(0,0,0)/**<initial specularColor vector of Material*/;
    vector colour = vector(0,0,0)/**<initial Colour vector of Material*/;

public:
    /**
     * @brief Construct a new material object
     * 
     * @param shine 
     * @param difuse 
     * @param specular 
     * @param color 
     */
    material(int shine,vector difuse, vector specular, vector color);

    /**
     * @brief Construct a new material object
     * 
     * @param color 
     */
    material(vector color)
    {
        colour = color;
    };
    /**
     * @brief Default constructor of material object
     * 
     */
    material()
    {
        difuseColor = vector(0,0,0);
        specularColor = vector(0,0,0);
        shininess = 0; 
        colour = vector(0,0,0);
        };

    /**
     * @brief Get the Shininess object
     * 
     * @return int 
     */
    int getShininess(){return shininess;};

    /**
     * @brief Get the Difuse Color object
     * 
     * @return vector 
     */
    vector getDifuseColor(){return difuseColor;};

    /**
     * @brief Get the Specular Color object
     * 
     * @return vector 
     */
    vector getSpecularColor(){return specularColor;};

    /**
     * @brief Get the Color object
     * 
     * @return vector 
     */
    vector getColor(){return colour;};
};
#endif