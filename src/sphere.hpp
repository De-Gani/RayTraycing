#ifndef SPHERE_H
#define SPHERE_H
#include"shape.hpp"
#include"light.hpp"

/** @brief Sphere class daughter of Shape class. 

    This class implements all the methods required to properly implement raytracing for the Sphere
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class  sphere : public shape
{
private:
    double radius/**<initial radius of Sphere*/;
    vector center = vector(0,0,0)/**<initial Position of the Sphere*/;

public:

/**
 * @brief Construct a new sphere object
 * 
 * @param radius 
 * @param center 
 * @param mat 
 */
    sphere(double radius,vector center,material mat);
/**
 * @brief Get the Center object
 * 
 * @return vector 
 */
    vector getCenter();
/**
 * @brief Set the Center object
 * 
 * @param newCenter 
 */
    void setCenter(vector newCenter);
/**
 * @brief Checks if sphere is hit by ray
 * 
 * @param Ray3f 
 * @return double 
 */
    double isHit(ray Ray3f);

/**
 * @brief Get the Normal object
 * 
 * @param pHit 
 * @return vector 
 */
    vector getNormal(vector pHit);

/**
 * @brief Calculates the color at a specific point pHit
 * 
 * @param pHit 
 * @return vector 
 */
    vector calculateColor(vector pHit,light light);

};
#endif