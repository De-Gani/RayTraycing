#include"light.hpp"

void light::setPosition(vector newPos)
{
            this->position = newPos;
}

void light::setColor(vector newColor)
{
            this->position = newColor;
}

vector light::getColor()
{
    return color;
}

vector light::getPosition()
{
    return position;
}