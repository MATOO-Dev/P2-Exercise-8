#include "../include/MandelBrotCreator.h"
#include <cmath>
#include <cstdlib>

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
    //first, define delta
    //real is between -2 and 1
    //horizontal delta = 3
    int horizontalMin = -2;
    int horizontalMax = 1;
    unsigned int horizontalDelta = abs(horizontalMax - horizontalMin);

    //imaginary is between -1 and 1
    //vertical delta = 2
    int verticalMin = 1;
    int verticalMax = -1;
    unsigned int verticalDelta = abs(verticalMax - verticalMin);

    //next, define delta fraction
    //double fraction = delta / windows size
    double xFraction = (double)horizontalDelta / (double)vp.getXSize();
    double yFraction = (double)verticalDelta / (double)vp.getYSize();
 
    //counter for currently prepared pixels
    unsigned int preparedPixelCount = 0;
    unsigned int processedPixels = 0;

    for(int yPos = 0; yPos < vp.getYSize(); yPos++)
        for(int xPos = 0; xPos < vp.getXSize(); xPos++)
        {
            //print current progress to console
            if(processedPixels % 100000 == 0)
                printProgressReport(xPos, yPos, vp);

            //define additional value for x 
            double xAdditional = xPos * yFraction;
            double yAdditional = yPos * yFraction;

            //define values for new complex number
            double complexX = horizontalMin + xAdditional;
            double complexY = verticalMin - yAdditional;

            ComplexNumber x = ComplexNumber(complexX, complexY);

            //get index of complex number x
            //additional parameter values open to interpretation
            unsigned int n = getMandelbrotIndex(x, 100, 255);

            //check color
            //if n at least 255
            if (n >= 255)
            {
                //prepare black pixel
                vp.preparePix(xPos, yPos, 0, 0, 0);
            }
            else
            {
                //prepare pixel with color (n,n,0)
                //vp.preparePix(xPos, yPos, n, n, 0);
                //alternative color (f(n),f(n),0) with f(n) = ((2n^2)/510)+2n
                double twoXSquared = 2 * (n * n);
                double fraction = twoXSquared / (double)510;
                double fn = fraction + double(2*n);
                vp.preparePix(xPos, yPos, 0, fn, fn);
            }
            //update prepared pixel count
            preparedPixelCount++;
            processedPixels++;
            //if max number of prepared pixels is reached, send them to buffer and reset counter
            if(preparedPixelCount == ViewPortGL::getMaxNumberOfPreparedPixels())
            {
                vp.sendPixels();
                preparedPixelCount = 0;
            }
        }
    //final sendpixels for remaining pixels not yet sent
    vp.sendPixels();
    printProgressReport(vp.getXSize(), vp.getYSize(), vp);
    std::cout << "Enjoy your Mandelbrot, freshly baked!\n";
}

void MandelBrotCreator::printProgressReport(unsigned int xPos, unsigned int yPos, ViewPortGL &vp)
{
    //clear previous progress bar print
    system("clear");
    //get percentage of completion
    unsigned int currentPixelIndex = (yPos * vp.getXSize()) + xPos;
    unsigned int totalViewPortPixels = vp.getXSize() * vp.getYSize();
    unsigned int roundedFraction = int(((double)currentPixelIndex / (double)totalViewPortPixels) * 100);
    //print completion percentage
    std::cout << "Progress: " << roundedFraction << "%  ";
    //extra space if percentage smaller 10 so progress bar looks nicer ^^
    if(roundedFraction < 10)
        std::cout << " ";
    //print progress bar
    std::cout << "[";
    unsigned int totalBarCount = 20;
    unsigned int fullBarCount = ((float)roundedFraction/100) * totalBarCount;
    for(int i = 0; i < fullBarCount; i ++)
        std::cout << "#";
    for (int i = 0; i < totalBarCount - fullBarCount; i++)
        std::cout << ".";
    std::cout << "]\n";
}