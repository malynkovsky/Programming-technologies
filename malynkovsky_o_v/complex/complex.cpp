#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

Complex operator/(const Complex& lhs, const double rhs) { return lhs / Complex(rhs); };
Complex operator*(const Complex& lhs, const double rhs) { return lhs * Complex(rhs); };
Complex operator+(const Complex& lhs, const double rhs) { return lhs + Complex(rhs); };
Complex operator-(const Complex& lhs, const double rhs) { return lhs - Complex(rhs); };

Complex operator+(const double& lhs, const Complex& rhs) { return Complex(lhs) + rhs; };
Complex operator-(const double& lhs, const Complex& rhs) { return Complex(lhs) - rhs; };
Complex operator/(const double& lhs, const Complex& rhs) { return Complex(lhs) * rhs; };
Complex operator*(const double& lhs, const Complex& rhs) { return Complex(lhs) / rhs; };

Complex Con(const Complex& rhs)//получение сопряжённого комплексного числа
{
    return Complex(rhs.re, -rhs.im);
}

Complex Power(const Complex& rhs, const int p)//Возведение в степень комплексного числа
{
    double z = sqrt(rhs.re*rhs.re + rhs.im*rhs.im);
    double sin_phi = rhs.im / z;
    double cos_phi = rhs.re / z;
    double phi = acos(cos_phi);
    double zpow = pow(z, p);
    return Complex(zpow*cos(p*phi), zpow*sin(p*phi));
}

Complex* Root(const Complex& rhs, const int p)//Извлечение корня из комплексного числа
{
    double z = sqrt(rhs.re*rhs.re + rhs.im*rhs.im);
    double sin_phi = rhs.im / z;
    double cos_phi = rhs.re / z;
    double phi = acos(cos_phi);
    double zpow = pow(z, (1 / p));
    const int n = p - 1;
    Complex *mass = new Complex[n];
    for (int i = 0; i < n; i++)
    {
        mass[i] = Complex(zpow*cos((phi + (2 * i * 3.14)) / p), zpow*sin((phi + (2 * i * 3.14)) / p));
    }
    return mass;
}

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    Complex sub(lhs);
    sub -= rhs;
    return sub;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    double remult(0.0);
    remult = lhs.re*rhs.re - lhs.im*rhs.im;
    double immult(0.0);
    immult = lhs.re*rhs.im + rhs.re*lhs.im;
    return Complex(remult, immult);
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    double rediv(0.0);
    rediv = (lhs.re*rhs.re + lhs.im*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    double imdiv(0.0);
    imdiv = (lhs.im*rhs.re - lhs.re*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    return Complex(rediv, imdiv);
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double remult(0.0);
    remult = re*rhs.re - im*rhs.im;
    double immult(0.0);
    immult = re*rhs.im + rhs.re*im;
    return Complex(remult, immult);
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator/=(const double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}



Complex& Complex::operator/=(const Complex& rhs)
{
    double rediv(0.0);
    rediv = (re*rhs.re + im*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    double imdiv(0.0);
    imdiv = (im*rhs.re - re*rhs.im) / (rhs.re*rhs.re + rhs.im*rhs.im);
    re = rediv;
    im = imdiv;
    return *this;
}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separetor << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separetor == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

