#include <iostream>
#include <cmath>
#include <string>

class ComplexNumber
{
private:
    double real = 0;
    double img = 0;
public:
    ComplexNumber();
    ComplexNumber(double r) : real(r) {}
    ComplexNumber(double r, double i) : real(r), img(i) {}
    double getReal() const { return real; }
    double getImg() const { return img; }
};

inline ComplexNumber operator+ (const ComplexNumber& a, const ComplexNumber& b)
{
    return ComplexNumber(a.getReal() + b.getReal(), a.getImg() + b.getImg());
}

#pragma region templateOperator+
//template <class T>
//inline ComplexNumber operator+ (const ComplexNumber& a, const T& b)
//{
//    return ComplexNumber(a.getReal() + b, a.getImg());
//}

//template <class T>
//inline ComplexNumber operator+ (const T& a, const ComplexNumber& b)
//{
//    return b + a;
//}
#pragma endregion

inline ComplexNumber operator- (const ComplexNumber& a, const ComplexNumber& b)
{
    return ComplexNumber(a.getReal() - b.getReal(), a.getImg() - b.getImg());
}

inline ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b)
{
    double ac = a.getReal() * b.getReal();
    double bd = a.getImg() * b.getImg();
    double ad = a.getReal() * b.getImg();
    double bc = a.getImg() * b.getReal();
    return ComplexNumber(ac - bd, ad + bc);
}

inline ComplexNumber operator/(const ComplexNumber& a, const ComplexNumber& b)
{
    double h = 1/(pow(b.getReal(), 2) + pow(b.getImg(), 2));
    double ac = a.getReal() * b.getReal();
    double bd = a.getImg() * b.getImg();
    double bc = a.getImg() * b.getReal();
    double ad = a.getReal() * b.getImg();
    return ComplexNumber(h * (ac + bd), h * (bc - ad));
}

inline void operator+= (ComplexNumber& a, const ComplexNumber& b)
{
    a = a + b;
}

inline void operator-= (ComplexNumber& a, const ComplexNumber& b)
{
    a = a - b;
}

inline void operator*= (ComplexNumber& a, const ComplexNumber& b)
{
    a = a * b;
}

inline void operator/= (ComplexNumber& a, const ComplexNumber& b)
{
    a = a / b;
}

inline void operator~ (const ComplexNumber& a)
{

}

inline void operator! (const ComplexNumber& b)
{

}

inline std::ostream& operator<< (std::ostream &os, const ComplexNumber& a)
{
    std::ostream result;
    //if(a.getImg() >= 0)
    //    printString += "+";
    //if(a.getImg() != 1)
    //    printString += a.getImg();

    return os << "(" << a.getReal() << (a.getImg() >= 0 ? "+" : "") << (a.getImg() != 1 ? std::to_string(a.getImg()) : "") << a.getImg() << "i)";
}