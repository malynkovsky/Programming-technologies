#include "vec3d.h"

Vec3d::Vec3d(double a, double b, double c)
    :x(a), y(b), z(c)
{
}

Vec3d::Vec3d(const Vec3d& v) 
    :x(v.x), y(v.y), z(v.z) 
{
}

bool Vec3d::operator==(const Vec3d & rhs)
{
    double eps = 1E-10;
    return (std::abs(x - rhs.x) < eps) && (std::abs(y - rhs.y) < eps) && (std::abs(z - rhs.z) < eps);
}

Vec3d & Vec3d::operator+=(const Vec3d & rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vec3d & Vec3d::operator-=(const Vec3d & rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vec3d & Vec3d::operator*=(const double & rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Vec3d & Vec3d::operator/=(const double & rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

Vec3d & Vec3d::operator=(const Vec3d & rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

std::ostream& Vec3d::writeTo(std::ostream & ostr)
{
    ostr << "{ " << x << " , " << y << " , " << z << " }   ";
    return ostr;
}

Vec3d operator+(const Vec3d & lhs, const Vec3d & rhs)
{
    return Vec3d(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vec3d operator-(const Vec3d & lhs, const Vec3d & rhs)
{
    return Vec3d(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

double operator*(const Vec3d & lhs, const Vec3d & rhs)
{
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

Vec3d operator*(const Vec3d & lhs, const double & rhs)
{
    return Vec3d(lhs.x*rhs, lhs.y*rhs, lhs.z*rhs);
}

double Module(const Vec3d & rhs)
{
    return std::sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z);
}

Vec3d Multiple(const Vec3d & lhs, const Vec3d & rhs)
{
    return Vec3d(lhs.y*rhs.z - lhs.z*rhs.y, lhs.z*rhs.x - lhs.x*rhs.z, lhs.x*rhs.y - lhs.y*rhs.x);
}
