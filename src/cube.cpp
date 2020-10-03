#include"cube.hpp"
#include"math.h"
#include"iostream"
#include"plane.hpp"

vector cube::getNormal(vector pHit)
{
    plane CubesFaces[6];
    CubesFaces[0] = plane(direction1,center.add(direction1.multiply(width/2)),this->getMaterial());
    CubesFaces[1] = plane(direction1.multiply(-1),center.add(direction1.multiply(-width/2)),this->getMaterial());
    CubesFaces[2] = plane(direction2,center.add(direction2.multiply(width/2)),this->getMaterial());
    CubesFaces[3] = plane(direction2.multiply(-1),center.add(direction2.multiply(-width/2)),this->getMaterial());
    CubesFaces[4] = plane(direction3,center.add(direction3.multiply(width/2)),this->getMaterial());
    CubesFaces[5] = plane(direction3.multiply(-1),center.add(direction3.multiply(-width/2)),this->getMaterial());
    int faceHit = -1;
    int nbrFaceHit = 0;
    float kMin = INFINITY;

    for(int k = 0;k < 6 ; k++)
    {
        if(((pHit.substraction(CubesFaces[k].getPosition()).normalize()).scalar(CubesFaces[k].getNormal())) <= kMin)
        {

                
                kMin = ((pHit.substraction(CubesFaces[k].getPosition()).normalize()).scalar(CubesFaces[k].getNormal()));
                faceHit = k;
                nbrFaceHit += 1;       
        }
    }
    return CubesFaces[faceHit].getNormal().multiply(-1);   
}

cube::cube(double width,vector center, vector direction1,vector direction2, material mat) : shape(mat)
{
    this->direction1 = direction1;
    this->direction2 = direction2;
    this->direction3 = (direction1.cross(direction2)).normalize();
    this->width = width;
    this->center = center;
}

bool cube::inDaCube(vector pHit,int k)
{
    plane CubesFaces[6];
    CubesFaces[0] = plane(direction1,center.add(direction1.multiply(width/2)),this->getMaterial());
    CubesFaces[1] = plane(direction1.multiply(-1),center.add(direction1.multiply(-width/2)),this->getMaterial());
    CubesFaces[2] = plane(direction2,center.add(direction2.multiply(width/2)),this->getMaterial());
    CubesFaces[3] = plane(direction2.multiply(-1),center.add(direction2.multiply(-width/2)),this->getMaterial());
    CubesFaces[4] = plane(direction3,center.add(direction3.multiply(width/2)),this->getMaterial());
    CubesFaces[5] = plane(direction3.multiply(-1),center.add(direction3.multiply(-width/2)),this->getMaterial());
    if(k == 0)
    {
        vector b = CubesFaces[0].getPosition().add(direction2.multiply(width/2)).add(direction3.multiply(width/2));
        vector c = (CubesFaces[0].getPosition()).add(direction2.multiply(-width/2)).add(direction3.multiply(width/2));
        vector e = (CubesFaces[0].getPosition()).add(direction2.multiply(width/2)).add(direction3.multiply(-width/2));

        return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);    
    }
    if(k == 1)
    {
        vector b = CubesFaces[1].getPosition().add(direction2.multiply(width/2)).add(direction3.multiply(width/2));
        vector c = (CubesFaces[1].getPosition()).add(direction2.multiply(-width/2)).add(direction3.multiply(width/2));
        vector e = (CubesFaces[1].getPosition()).add(direction2.multiply(width/2)).add(direction3.multiply(-width/2));

        return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);
    }
    if(k == 2)
    {
        vector b =   CubesFaces[2].getPosition().add(direction1.multiply(width/2)).add(direction3.multiply(width/2));
        vector c = (CubesFaces[2].getPosition()).add(direction1.multiply(-width/2)).add(direction3.multiply(width/2));
        vector e = (CubesFaces[2].getPosition()).add(direction1.multiply(width/2)).add(direction3.multiply(-width/2));

        return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);
    }
    if(k == 3)
    {
        vector b =   CubesFaces[3].getPosition().add(direction1.multiply(width/2)).add(direction3.multiply(width/2));
        vector c = (CubesFaces[3].getPosition()).add(direction1.multiply(-width/2)).add(direction3.multiply(width/2));
        vector e = (CubesFaces[3].getPosition()).add(direction1.multiply(width/2)).add(direction3.multiply(-width/2));

        return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);
    }
        if(k == 4)
    {
        vector b =  CubesFaces[4].getPosition().add(direction1.multiply(width/2)).add(direction2.multiply(width/2));
        vector c=(CubesFaces[4].getPosition()).add(direction1.multiply(-width/2)).add(direction2.multiply(width/2));
        vector e =(CubesFaces[4].getPosition()).add(direction1.multiply(width/2)).add(direction2.multiply(-width/2));

        return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);
    }
        if(k == 5)
    {
        vector b =  CubesFaces[5].getPosition().add(direction1.multiply(width/2)).add(direction2.multiply(width/2));
        vector c = (CubesFaces[5].getPosition()).add(direction1.multiply(-width/2)).add(direction2.multiply(width/2));
        vector e = (CubesFaces[5].getPosition()).add(direction1.multiply(width/2)).add(direction2.multiply(-width/2));

return(b.scalar(c - b) - pHit.scalar(c - b) <= 1e-1 && pHit.scalar(c - b) - c.scalar(c - b) <= 1e-1 && b.scalar(e-b) -  pHit.scalar(e - b) <= 1e-1 &&  pHit.scalar(e - b) - e.scalar(e-b) <= 1e-1);
    }




    return(false);
}
double cube::isHit(ray Ray3f)
{
    plane CubesFaces[6];
    CubesFaces[0] = plane(direction1,center.add(direction1.multiply(width/2)),this->getMaterial());
    CubesFaces[1] = plane(direction1.multiply(-1),center.add(direction1.multiply(-width/2)),this->getMaterial());
    CubesFaces[2] = plane(direction2,center.add(direction2.multiply(width/2)),this->getMaterial());
    CubesFaces[3] = plane(direction2.multiply(-1),center.add(direction2.multiply(-width/2)),this->getMaterial());
    CubesFaces[4] = plane(direction3,center.add(direction3.multiply(width/2)),this->getMaterial());
    CubesFaces[5] = plane(direction3.multiply(-1),center.add(direction3.multiply(-width/2)),this->getMaterial());
    double tMin = INFINITY;
    for(int k = 0;k < 6 ; k++)
    {
        double t = CubesFaces[k].isHit(Ray3f);
       

        
        if( t > 0.0) 
        {
            
            vector pHit = Ray3f.pointHit(t);


            if(this->inDaCube(pHit,k))
            {
                if(t<tMin )
                {
                    tMin = t;
                }
            }    
        }   
    }
    if (tMin == INFINITY)
    {
        return 0;
    }
    else
    {
        return tMin;
    }
}


    vector cube::calculateColor(vector pHit,light light)
    {
    vector lightPosition = light.getPosition();
    vector lightIntensity = light.getColor();
    vector diffuseColor = this->getMaterial().getDifuseColor();
    vector specularColor = this->getMaterial().getSpecularColor();
    int shininess = this->getMaterial().getShininess();;

    //DIFUSE LIGHTING
    vector normal = getNormal(pHit);
    vector lightRay = (lightPosition.substraction(pHit)).normalize();
    vector diffuse = (diffuseColor.time(lightIntensity)).multiply(std::max(0.0,lightRay.scalar(normal)));


    //SPECULAR
    vector reflection = ((normal.multiply(2*lightRay.scalar(normal))).substraction(lightRay)).normalize();
    double maxCalc = std::max(0.0,reflection.scalar((pHit.multiply(-1)).normalize()));
    
    vector specular = (specularColor.time(lightIntensity)).multiply(pow(maxCalc,shininess));
    return specular.add(diffuse);

    }

