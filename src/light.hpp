#ifndef LIGHT_H
#define LIGHT_H
#include"vector.hpp"

/** @brief Light class. 

    This class simply represents an Object which is a Light.
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class light
{
    private:
        vector position = vector(0,0,0)/**<initial Position of Light*/;
        vector color = vector(0,0,0)/**<initial Color of Light*/;
    public:
    
        /**
        * @brief Construct a new light object
        * 
        */
        light()
        {
            this->position = vector();
            this->color = vector();
        }

        /**
         * @brief Construct a new light object
         * 
         * @param position 
         * @param color 
         */
        light(vector position, vector color)
        {
            this->position = position;
            this->color = color;
        }

        /**
         * @brief Set the Position object
         * 
         * @param newPos 
         */
        void setPosition(vector newPos);

        /**
         * @brief Get the Position object
         * 
         * @return vector 
         */
        vector getPosition();

        /**
         * @brief Get the Color object
         * 
         * @return vector 
         */
        vector getColor();

        /**
         * @brief Set the Color object
         * 
         * @param newColor 
         */
        void setColor(vector newColor);

};

#endif