#include <iostream>
#include <cmath>
#include "ComplexNumber.h"
#include "ViewPortGL.h"

class MandelBrotCreator
{
public:
    unsigned int getMandelbrotIndex(ComplexNumber& x, double limes, int max);
    void drawMandelbrotMenge(ViewPortGL& vp);
    void drawMandelbrotMenge(ViewPortGL& vp, const ComplexNumber& upperLeft, const ComplexNumber& lowerRight);
};