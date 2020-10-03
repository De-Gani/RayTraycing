#include"vector.hpp"
#include"math.h"
#include"iostream"



vector::vector(double x1,double y1, double z1)
{
    x = x1;
    y = y1;
    z = z1;
}

vector::vector(const vector &v)
{
    x = v.x;
    y = v.y;
    z = v.z;  
}

vector vector::substraction(vector v)
{
    return vector(x - v.getX(),y - v.getY(),z - v.getZ());
}

vector vector::add(vector v)
{
    return vector(x + v.getX(),y + v.getY(),z + v.getZ());
}

double vector::scalar(vector v)
{
    return x*v.getX() + y*v.getY() + z*v.getZ();
}



double vector::abs()
{
    return std::sqrt(x*x + y*y + z*z);
} 

vector vector::normalize()
{
    return vector(x/(*this).abs(),y/(*this).abs(),z/(*this).abs());
}

vector vector::operator+(vector param) 
{
            vector temp;
            temp.x = x + param.x;
            temp.y = y + param.y;
            temp.z = z + param.z;
            return (temp);
}
vector vector::operator-(vector param) 
{
            vector temp;
            temp.x = x - param.x;
            temp.y = y - param.y;
            temp.z = z - param.z;
            return (temp);
}

vector vector::multiply(double coef)
{
    return vector(x*coef,y*coef,z*coef);
}
vector vector::time(vector u)
{
    return vector(x*u.getX(),z*u.getZ(),z*u.getZ());
}
vector vector::cross(vector u)
{
    return vector(y*u.getZ() - z*u.getY(),z*u.getX() - x*u.getZ(),x*u.getY() - y*u.getX());
}

std::ostream& operator<< (std::ostream &out, vector const& data) {
    out << "vector is" << ": \nx =";
    out << data.x << " \ny =";
    out << data.y << " \nz =";
    out << data.z << '\n';
    return out;
}

