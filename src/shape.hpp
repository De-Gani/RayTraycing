#ifndef SHAPE_H
#define SHAPE_H
#include"material.hpp"
#include"ray.hpp"
#include"vector.hpp"
#include"light.hpp"

/** @brief Shape abstract class. 

    This class implements virtual methods required to properly implement raytracing for the various difrent shapes.
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class shape
{
private:
    material mat/**<initial material of Shape*/;
public:
    
    /**
     * @brief Default Constructor of shape object
     * 
     */
    shape()
    {
        mat = material();
    }

    /**
     * @brief Construct a new shape object
     * 
     * @param mat 
     */
    shape(material mat)
    {
        this->mat = mat;
    };

    /**
     * @brief Get the Material object
     * 
     * @return material 
     */
    material getMaterial(){return mat;};

    /**
     * @brief Calculates the point t a which a ray intersects a Shape and returns -1 if it doesn't intersect
     * 
     * @param Ray3f 
     * @return double 
     */
    virtual double isHit(ray Ray3f) = 0;

    /**
     * @brief Calculates the color of a Shape at a point pHit
     * 
     * @param pHit 
     * @return vector 
     */
    virtual vector calculateColor(vector pHit,light light) = 0;

    /**
     * @brief Get the Normal object
     * 
     * @param pHit 
     * @return vector 
     */
    virtual vector getNormal(vector pHit) = 0;    
};
#endif