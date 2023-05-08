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
    ViewPortGL targetWindow = ViewPortGL("Mandelbrot yum yum", 300, 200);
    targetWindow.swapBuffers();

    //define corners of out mandelbrot set
    ComplexNumber topLeft = ComplexNumber(-0.796, -0.144);
    ComplexNumber bottomRight = ComplexNumber(-0.793, -0.146);
    //starting values:  (-2+1i)         (1-1i)
    //zoomed out:       (-20+10i)       (10-10i)
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

int main()
{
    //OperatorTest();
    //OperatorTemplateTest();
    MandelBrot();

    return 0;
}