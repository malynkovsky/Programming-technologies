#ifndef COMPLEX_H_21092017
#define COMPLEX_H_21092017

#include <iosfwd>
#include <iostream>
struct Complex {
    Complex() {}
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);
    bool operator==(const Complex& rhs) const 
    {
        double eps = 1E-10;
        return (std::abs(re - rhs.re) < eps ) && (std::abs(im - rhs.im) < eps);
    }
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }
    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs) { return operator+=(Complex(rhs)); }
    Complex& operator-=(const Complex& rhs);
    Complex& operator-=(const double rhs) { return operator-=(Complex(rhs)); }
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const Complex& rhs);
    Complex& operator/=(const double rhs);
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };

    static const char leftBrace{ '{' };
    static const char separetor{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);


Complex operator/(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);

Complex operator+(const double& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);

Complex Con(const Complex& rhs);
Complex Power(const Complex& rhs, const int p);
Complex* Root(const Complex& rhs, const int p);

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

#endif;
