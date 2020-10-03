# Projet PAP

Please note that the output of the algorithm is .ppm format and not .png as asked in the subject. However this doesn't change anything to the effectiveness of the programm.
And if I were working in a professional envirment requiring .png i woul have created a sim .sh scrpit using the following command:
convert img.ppm img.png

If you want to test the programm and need .png to view it simply run in command on linux:

convert untitled.ppm untitled.png

And your image will be converted to .png

To commpile my code I use the following line

g++ -Wall main.cpp vector.cpp vector.hpp sphere.cpp sphere.hpp ray.cpp ray.hpp shape.hpp screen.cpp screen.hpp material.cpp material.hpp plane.cpp plane.hpp cube.cpp cube.hpp render.cpp render.hpp light.cpp light.hpp -o exec




