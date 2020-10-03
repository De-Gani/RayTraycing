#include"ray.hpp"



ray::ray(vector origin, vector direction)
{
    this->origin = origin;
    this->direction = direction;
}

vector ray::getOrigin()
{
    return origin;
}

vector ray::getDirection()
{
    return direction;
}

vector ray::pointHit(double t)
{
    return origin.add(direction.multiply(t)); 
}