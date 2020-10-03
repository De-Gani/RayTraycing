#ifndef PLANE_H
#define PLANE_H
#include"shape.hpp"
#include"light.hpp"

/** @brief Plane class daughter of Shape class. 

    This class implements all the methods required to properly implement raytracing for the Plane
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class  plane : public shape
{
private:
    vector normal = vector(0,0,0) /**<initial normal vector of Plane*/;
    vector position = vector(0,0,0)/**<initial position vector of Plane*/;

public:
    
    /**
     * @brief Default Constructor for new plane object
     * 
     */
    plane() : shape()
    {
        normal = vector();
        position = vector();
    };

    /**
     * @brief Construct a new plane object
     * 
     * @param normal 
     * @param position 
     * @param mat 
     */
    plane(vector normal, vector position, material mat);

    /**
     * @brief Checks if plane is hit by Ray
     * 
     * @param Ray3f 
     * @return double 
     */
    double isHit(ray Ray3f);

    /**
     * @brief Calculates the color at a specific point pHit
     * 
     * @param pHit 
     * @return vector 
     */
    vector calculateColor(vector pHit, light lights);

    /**
     * @brief Get the Normal object
     * 
     * @return vector 
     */
    vector getNormal(){return normal;};

    /**
     * @brief Get the Normal object
     * 
     * @param pHit 
     * @return vector 
     */
    vector getNormal(vector pHit){return normal;};
    
    /**
     * @brief Get the Position object
     * 
     * @return vector 
     */
    vector getPosition(){return position;};
};

#endif