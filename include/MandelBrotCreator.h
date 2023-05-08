#include <iostream>
#include <cmath>
#include "ComplexNumber.h"
#include "ViewPortGL.h"
#include "Color.h"

class MandelBrotCreator
{
public:
    unsigned int getMandelbrotIndex(ComplexNumber& x, double limes, int max);
    void drawMandelbrotMenge(ViewPortGL& vp);
    void drawMandelbrotMenge(ViewPortGL& vp, const ComplexNumber& upperLeft, const ComplexNumber& lowerRight);
    void printProgressReport(unsigned int xPos, unsigned int yPos, ViewPortGL& vp);
};