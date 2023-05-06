#include <iostream>
#include <cmath>

class ComplexNumber
{
private:
    double real;
    double img;
public:
    ComplexNumber();
    ComplexNumber(double r, double i);
    double getReal() const { return real; }
    double getImg() const { return img; }
    
    friend std::ostream& operator<< (std::ostream &os, const ComplexNumber& a)
    {
        if(a.getImg() < 0)
            return os << a.getReal() << a.getImg() << "i";
        return os << a.getReal() << "+" << a.getImg() << "i";
    }
};

ComplexNumber operator+ (const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator- (const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator* (const ComplexNumber& a, const ComplexNumber& b);
ComplexNumber operator/ (const ComplexNumber& a, const ComplexNumber& b);