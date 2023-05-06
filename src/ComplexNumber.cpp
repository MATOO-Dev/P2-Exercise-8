#include "../include/ComplexNumber.h"

ComplexNumber::ComplexNumber(): real(0), img(0) {}

ComplexNumber::ComplexNumber(double r, double i) : real(r), img(i) {}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b)
{
    return ComplexNumber(a.getReal() + b.getReal(), a.getImg() + b.getImg());
}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b)
{
    return ComplexNumber(a.getReal() - b.getReal(), a.getImg() - b.getImg());
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b)
{
    double ac = a.getReal() * b.getReal();
    double bd = a.getImg() * b.getImg();
    double ad = a.getReal() * b.getImg();
    double bc = a.getImg() * b.getReal();
    return ComplexNumber(ac - bd, ad + bc);
}

ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b)
{
    double h = 1/(pow(b.getReal(), 2) + pow(b.getImg(), 2));
    double ac = a.getReal() * b.getReal();
    double bd = a.getImg() * b.getImg();
    double bc = a.getImg() * b.getReal();
    double ad = a.getReal() * b.getImg();
    return ComplexNumber(h * (ac + bd), h * (bc - ad));
}