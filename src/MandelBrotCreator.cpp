#include "../include/MandelBrotCreator.h"

unsigned int MandelBrotCreator::getMandelbrotIndex(ComplexNumber &x, double limes, int max)
{
    //set starting value for j
    unsigned int index = 0;
    //set mjMinusOne to m0(x) -> always zero
    ComplexNumber mjMinusOne = 0;

    //iterate while j < max
    while(index < max)
    {
        //increment index -> exit condition
        index++;
        //calculate value of mj(x)
        ComplexNumber mj = (mjMinusOne * mjMinusOne) + x;
        //if mj is larget than limes, return j of mj
        if(!mj > limes)
            return index;
        //else cache value in mjMinusOne for next loop iteration
        mjMinusOne = mj;
    }
    //if no mj > limes was found within max steps, return max instead
    return max;
}

void MandelBrotCreator::drawMandelbrotMenge(ViewPortGL& vp)
{
    //complex number value for pixel
    //real is between -2 and 1
    //imaginary is between -1 and 1

    //first, define delta
    //horizontal delta = 3
    //vertical delta = 2
    unsigned int horizontalDelta;
    unsigned int verticalDelta;
        int horizontalMin = -2;
        int horizontalMax = 1;
        horizontalDelta = abs(horizontalMin) + abs(horizontalMax);

        int verticalMin = 1;
        int verticalMax = -1;
        verticalDelta = abs(verticalMin) + abs(verticalMax);

    //next, define delta fraction
    //double fraction = delta / windows size
    //do this for both vertical and horizontal

    //define additional value for x 
    //double xAdditional = pixel xPos * yFraction
    //double yAdditional = pixel yPos * yFraction

    //define values for new complex number
    //complexX = -2 + xAdditional
    //complexY = +1 - yAdditional

    //complexNumber x = ComplexNumber(complexX, complexY)

    //get index of complex number x
    //additional parameter values open to interpretation
    //unsigned int n = getMandelbrotIndex(x, 100, 255);

    //check needed color
    //if n at least 255
    //if n >= 255
        //prepare black pixel
    //else
        //prepare pixel with color (n,n,0)

    //note: before prepare, check for max number of preparable pixels
    //if max pixels is reached, send them and reset the counter

    //alternative color (f(n),f(n),0)
    //f(n) = ((2n^2)/510)+2x






















}