#ifndef RAY_H
#define RAY_H
#include"vector.hpp"
/** @brief Ray class. 

    This class doesn't implement alot of methods however it clarifies the code since raytracing functions entirely with Rays.
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class ray
{
    private:
        vector origin/**<initial origin of Ray*/;
        vector direction/**<initial direction of Ray*/;

    public:
    
    /**
     * @brief Default Constructor for new ray object
     * 
     */
    ray()
    {
        origin = vector(0,0,0);
        direction = vector(0,0,0);
    }

    /**
     * @brief Construct a new ray object
     * 
     * @param origin 
     * @param direction 
     */
    ray(vector origin, vector direction);

    /**
     * @brief Calculates the point hited depending on t and a Ray
     * 
     * @param t 
     * @return vector 
     */
    vector pointHit(double t);

    /**
     * @brief Get the Origin object
     * 
     * @return vector 
     */
    vector getOrigin();
    /**
     * @brief Get the Direction object
     * 
     * @return vector 
     */
    vector getDirection();

};
#endif