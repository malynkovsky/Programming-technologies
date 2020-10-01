#include "kvaternion.h"
#include <iostream>

Kvaternion::Kvaternion(const int a, const int b, const int c, const int d)
    :a(a), b(b), c(c), d(d)
{
}

Kvaternion::Kvaternion(const Kvaternion& v)
    :a(v.a), b(v.b), c(v.c), d(v.d)
{
}

Kvaternion & Kvaternion::operator=(const Kvaternion & rhs)
{
    a = rhs.a;
    b = rhs.b;
    c = rhs.c;
    d = rhs.d;
    return *this;
}

Kvaternion Kvaternion::Multiple(const Kvaternion& rhs)
{
    *this = Kvaternion(a * rhs.a, b *rhs.c, c *rhs.b, d*rhs.d);
    return *this;
}

int Kvaternion::Determinate()
{
    return (a*d - b*c);
}

Kvaternion & Kvaternion::operator+=(const Kvaternion & rhs)
{
    a += rhs.a;
    b += rhs.b;
    c += rhs.c;
    d += rhs.d;
    return *this;
}

Kvaternion & Kvaternion::operator-=(const Kvaternion & rhs)
{
    a -= rhs.a;
    b -= rhs.b;
    c -= rhs.c;
    d -= rhs.d;
    return *this;
}

Kvaternion & Kvaternion::operator*=(const int & rhs)
{
    a *= rhs;
    b *= rhs;
    c *= rhs;
    d *= rhs;
    return *this;
}

Kvaternion & Kvaternion::operator/=(const int & rhs)
{
    a /= rhs;
    b /= rhs;
    c /= rhs;
    d /= rhs;
    return *this;
}

std::ostream & Kvaternion::writeTo(std::ostream & ostr)
{
    ostr << "( " << a << ", " << b << ", " << c << ", " << d << ")";
    return ostr;
}

Kvaternion operator+(const Kvaternion & lhs, const Kvaternion & rhs)
{
    Kvaternion sum(lhs);
    sum += rhs;
    return sum;
}

Kvaternion operator-(const Kvaternion & lhs, const Kvaternion & rhs)
{
    Kvaternion minus(lhs);
    minus -= rhs;
    return minus;
}

Kvaternion operator*(const Kvaternion & lhs, const Kvaternion & rhs)
{
    Kvaternion a = lhs;
    return a.Multiple(rhs);
}
