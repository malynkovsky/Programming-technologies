#include "rational.h"
#include <iostream>
#include <cmath>

void Rational::shorten(Rational& rhs)
{
    int a = abs(rhs.num), b = abs(rhs.denum), nod = 1;
    while ((a != 0) && (b != 0))
    {
        if (a > b) a = a % b;
        else b = b % a;
    }
    nod = a + b;
    rhs = Rational(rhs.num / nod, rhs.denum / nod);
}

Rational& Rational::operator+=(const Rational& rhs)
{
    
    *this = Rational(num*rhs.denum + rhs.num*denum, denum*rhs.denum);
    shorten(*this);
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    *this = Rational(num*rhs.denum - rhs.num*denum, denum*rhs.denum);
    shorten(*this);
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    num *= rhs.num;
    denum *= rhs.denum;
    shorten(*this);
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    num *= rhs.denum;
    denum *= rhs.num;
    shorten(*this);
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational minus(lhs);
    minus -= rhs;
    return minus;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    Rational multiple(lhs);
    multiple *= rhs;
    return multiple;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational div(lhs);
    div /= rhs;
    return div;
}

Rational operator+(const Rational& lhs, const int& rhs)
{
    return lhs + Rational(rhs);
}

Rational operator-(const Rational& lhs, const int& rhs) 
{
    return lhs - Rational(rhs);
}

Rational operator*(const Rational& lhs, const int& rhs)
{
    return lhs * Rational(rhs);
}

Rational operator/(const Rational& lhs, const int& rhs)
{
    return lhs / Rational(rhs);
}

Rational operator+(const int& lhs, const Rational& rhs)
{
    return Rational(lhs) + rhs;
}

Rational operator-(const int& lhs, const Rational& rhs)
{
    return Rational(lhs) - rhs;
}

Rational operator*(const int& lhs, const Rational& rhs)
{
    return Rational(lhs) * rhs;
}

Rational operator/(const int& lhs, const Rational& rhs)
{
    return Rational(lhs) / rhs;
}

Rational::Rational(const int up)
    : Rational(up, 1)
{
}

Rational::Rational(const int up, const int down)
    : num(up)
    , denum(down)
{
    //denum = 0 ?
    if (denum < 0) {
        denum = -denum;
        num = -num;
    }
}



std::ostream& Rational::writeTo(std::ostream& ostr)
{
    Rational a(num, denum);
    shorten(a);
    ostr << a.num << '/' << a.denum << "    ";
    return ostr;
}