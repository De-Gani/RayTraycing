
#ifndef CUBE_H
#define CUBE_H
#include"shape.hpp"
#include"light.hpp"

/** @brief Cube class daughter of Shape class. 

    This class implements all the methods required to properly implement raytracing for the Cube its also uses Plan class alot sice a cube can be viewd as 6 planes
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class  cube : public shape
{
private:
    double width /**<initial width double of cube*/;
    vector center = vector(0,0,0) /**<initial cencter vector of cube*/;
    vector direction1 = vector(0,0,0)/**<initial direction1 vector of cube*/;
    vector direction2 = vector(0,0,0)/**<initial direction2 vector of cube*/;
    vector direction3 = vector(0,0,0)/**<initial direction3 vector of cube*/;

public:
    /**
     * @brief Determins if a point hited is in a Cube
     * 
     * @param pHit 
     * @param k 
     * @return true 
     * @return false 
     */
    bool inDaCube(vector pHit,int k);

    /**
     * @brief Construct a new cube object
     * 
     * @param width 
     * @param center 
     * @param direction1 
     * @param direction2 
     * @param mat 
     */
    cube(double width,vector center,vector direction1, vector direction2 ,material mat);

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
 * @brief 
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
 * @brief 
 * 
 * @param pHit 
 * @return vector 
 */
    vector calculateColor(vector pHit,light lights);

};
#endif
/**
@enduml
**/