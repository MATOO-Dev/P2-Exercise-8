#include <iostream>
#include "include/glad.h"
#include <GLFW/glfw3.h>
#include "include/ViewPortGL.h"
#include "include/ComplexNumber.h"
#include "include/MandelBrotCreator.h"

void test() {
    ViewPortGL vp = ViewPortGL("OpenGL Plain Test", 1000, 1000);
    bool isRunning = true;
    while (isRunning) {
        isRunning = !vp.windowShouldClose();

        vp.prepareTriangle(0, 999, 999, 999, 500, 0, 200, 0, 0, 0, 0, 200, 0, 200, 0);
        vp.sendTriangles();

        vp.swapBuffers();
    }
}

void OperatorTest()
{
    ComplexNumber left = ComplexNumber(3, 5);
    ComplexNumber right = ComplexNumber(7, 2);

    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    std::cout << "sum (+): " << left + right << std::endl;
    std::cout << "subtraction (-): " << left - right << std::endl;

    left = ComplexNumber(0, 1);
    right = ComplexNumber(0, 1);

    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;   

    std::cout << "multiplication (*): " << left * right << std::endl;

    std::cout << "division (/): " << left / right << std::endl;

    std::cout << std::endl;

    ComplexNumber complex = ComplexNumber(3, 5);
    double var = 5;

    std::cout << "complex: " << complex << std::endl;
    std::cout << "var: " << var << std::endl;

    std::cout << "complex + var: " << complex + var << std::endl;
    std::cout << "var + complex: " << var + complex << std::endl;

    std::cout << "complex - var: " << complex - var << std::endl;
    std::cout << "var - complex: " << var - complex << std::endl;

    std::cout << "test:" << 5 - ComplexNumber(3,-5) << std::endl;
}

void MandelBrot()
{
    //fire up the oven
    MandelBrotCreator mandelBrotOven;

    //create new window and swap buffers to show black screen instead of empty with artefacts
    ViewPortGL targetWindow = ViewPortGL("Mandelbrot yum yum", 1500, 1000);
    targetWindow.swapBuffers();

    //define corners of mandelbrot set
    ComplexNumber topLeft = ComplexNumber(-2, 1);
    ComplexNumber bottomRight = ComplexNumber(1, -1);
    //starting values:  (-2+1i)         (1-1i)
    //zoomed out:       (-15+10i)       (10-10i)
    //zoomed in:        (-1+0i)         (1-1i)
    //zoomed in alot:   (-0.8-0.1i)     (-0.79-0.15i)
    //zoomed recursion: (-0.796-0.126i) (-0.793-0.144i)
    //zoomed branch:    (-0.796-0.144i) (-0.793-0.146i)

    //draw mandelbrot set
    //mandelBrotOven.drawMandelbrotMenge(targetWindow);
    mandelBrotOven.drawMandelbrotMenge(targetWindow, topLeft, bottomRight);
    
    //swap buffer to mandelbrot set
    targetWindow.swapBuffers();

    //keep window open
    while (!targetWindow.windowShouldClose());
}

//note: this doesnt currently work correctly.
//the zoom in animation becomes faster and faster instead of staying at the correct speed
//my assumption is that this is due to floating point inprecision
void AnimateMandelBrot()
{
    //fire up the oven
    MandelBrotCreator mandelBrotOven;

    //create new window and swap buffers to show black screen instead of empty with artefacts
    ViewPortGL targetWindow = ViewPortGL("Mandelbrot zoom goes weeeeee", 300, 200);
    targetWindow.swapBuffers();

    //set starting coordinates
    ComplexNumber topLeftStart = ComplexNumber(-2, 1);
    ComplexNumber bottomRightStart = ComplexNumber(1, -1);

    //set end coordinates
    ComplexNumber topLeftEnd = ComplexNumber(-0.743386245800, -0.131851022015);
    ComplexNumber bottomRightEnd = ComplexNumber(-0.743375071321, -0.131855868434);
    //topLeftEnd = ComplexNumber(-1, 0.25);
    //bottomRightEnd = ComplexNumber(-0.25, -0.25);

    //calculate difference between start and end positions
    ComplexNumber topLeftDelta = topLeftEnd - topLeftStart;
    ComplexNumber bottomRightDelta = bottomRightEnd - bottomRightStart;

    //amount of images drawn
    double iterationSteps = 10;

    //calculate difference per step
    double leftStep = topLeftDelta.getReal() / iterationSteps;
    double topStep = topLeftDelta.getImg() / iterationSteps;
    double rightStep = bottomRightDelta.getReal() / iterationSteps;
    double bottomStep = bottomRightDelta.getImg() / iterationSteps;

    //iterate until step count is reached or user closes window
    unsigned int currentIteration = 0;
    while(currentIteration < iterationSteps && !targetWindow.windowShouldClose())
    {
        //increment step counter
        currentIteration++;

        //define corners of mandelbrot set
        double left = topLeftStart.getReal() + leftStep * currentIteration;
        double top = topLeftStart.getImg() + topStep * currentIteration;
        double right = bottomRightStart .getReal() + rightStep * currentIteration;
        double bottom = bottomRightStart.getImg() + bottomStep * currentIteration;

        ComplexNumber topLeft = ComplexNumber(left, top);
        ComplexNumber bottomRight = ComplexNumber(right, bottom);

        //draw mandelbrot set
        mandelBrotOven.drawMandelbrotMenge(targetWindow, topLeft, bottomRight);

        //swap buffer to mandelbrot set
        targetWindow.swapBuffers();
    }

    //keep window open
    while (!targetWindow.windowShouldClose());
}

int main()
{
    //OperatorTest();
    //OperatorTemplateTest();
    //MandelBrot();
    AnimateMandelBrot();

    return 0;
}