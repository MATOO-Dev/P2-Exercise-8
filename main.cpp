#include <iostream>
#include "include/glad.h"
#include <GLFW/glfw3.h>
#include "include/ViewPortGL.h"
#include "include/ComplexNumber.h"

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
}

void OperatorTemplateTest()
{

}

void OperatorSetTest()
{

}

void SingleOperatorTest()
{

}

void MandelBrot()
{
    
}

int main()
{
    OperatorTest();


    return 0;
}