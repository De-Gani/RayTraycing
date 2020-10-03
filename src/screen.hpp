#ifndef SCREEN_H
#define SCREEN_H
#include"ray.hpp"
/** @brief Screen class.

    This class implements all the methods required to properly manipulate and create a screen as defined in the subject.
    @author De Gani. Guillaume, Moummou. Nisrine
    @date December 2019
*/
class screen 

{
    private:
        ray eye/**<initial eye ray of screen*/;
        int ImgHeight/**<initial ImgHeight int of screen*/;
        int ImgWidth /**<initial ImgWidth int of screen*/;
        int NbrPixel /**<initial NbrPixel int of screen*/;
    
    public:

        /**
         * @brief Construct a new screen object 
         * @param ImgHeight 
         * @param ImgWidth 
         * @param NbrPixel 
         * @param eye 
         */
        screen(int ImgHeight,int ImgWidth,int NbrPixel, ray eye);

        /**
         * @brief Generates position of each pixel for a given screen.
         * 
         * @return vector** 
         */
        vector** GeneratePointsOfScreen();






};
#endif