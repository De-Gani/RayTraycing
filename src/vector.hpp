#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>

/** @brief Vector class used to make basic vector calculation. 

    This class is simply a reprogramming a Vec3 lib that already exsists in c++
    @author De Gani. Guillaume, Nisrine Moummou
    @date December 2019
    */
class vector
{   
    private:
        double x/**<initial x-coordinate of vector*/;
        double y/**<initial y-coordinate of vector*/;
        double z/**<initial z-coordinate of vector*/;

    public:
    
          /**
         * @brief Default constructor intialise to vectot with only zeros
         * 
         */
        vector()
        {
            x = 0;
            y = 0;
            z = 0;
        }

        /**
         * @brief Getter function for x
         * 
         * @return double 
         */
        double getX(){return x;};

        /**
         * @brief Getter function for y
         * 
         * @return double 
         */
        double getY(){return y;};

        /**
         * @brief Getter function for Z
         * 
         * @return double 
         */
        double getZ(){return z;};
      
        /**
         * @brief Construct a new vector object
         * 
         * @param x1 
         * @param y1 
         * @param z1 
         */
        vector(double x1,double y1, double z1);
        
        /**
         * @brief Copy Construct a new vector object 
         * 
         * @param v 
         */
        vector(const vector &v);
        
        /**
         * @brief 
         * 
         * @param v 
         * @return vector 
         */
        vector substraction(vector v);

        /**
         * @brief 
         * 
         * @param v 
         * @return vector 
         */
        vector add(vector v);
        
        /**
         * @brief Calculate v1.v2
         * 
         * @param v 
         * @return double 
         */
        double scalar(vector v);

        /**
         * @brief Calculate |v|
         * 
         * @return double 
         */
        double abs();

        /**
         * @brief Normalizes the vector v
         * 
         * @return vector 
         */
        vector normalize();

        /**
         * @brief Multiplies every coordinate of vecto by coef
         * 
         * @param coef 
         * @return vector 
         */
        vector multiply(double coef);

        /**
         * @brief Calculates the cross product between two vectors
         * 
         * @param u 
         * @return vector 
         */
        vector cross(vector u);

        /**
         * @brief 
         * 
         * @param out 
         * @param obj 
         * @return std::ostream& 
         */
        friend std::ostream& operator<< (std::ostream& out, const vector& obj);

        /**
         * @brief v.multiply(u) returns the multiplication of each coordinate by the coresponding coordinate in the other vector ergo (v.x*u.x, v.y*u.y, v.z*u.z)
         * 
         * @param u 
         * @return vector 
         */
        vector time(vector u);

        /**
         * @brief Surcharge de l'operator ==
         * 
         * @param rhs 
         * @return true 
         * @return false 
         */
        bool operator == (const vector& rhs) const
        {
            return x == rhs.x && y == rhs.y && z == rhs.z ;
        }

        /**
         * @brief Surcharge de l'operator +
         * 
         * @return vector 
         */
       vector operator + (vector);

       /**
        * @brief Surcharge de l'operator -
        * 
        * @return vector 
        */
       vector operator - (vector);
};

#endif