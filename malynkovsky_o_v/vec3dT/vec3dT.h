#ifndef VEC3D_2017_5678
#define VEC3D_2017_5678

#include <iostream>

template <typename T>
struct Vec3dT
{
    Vec3dT() = default;
    Vec3dT(const T a, const T b, const T c);
    Vec3dT(const Vec3dT<T>& v);//копирующий конструктор
    ~Vec3dT() = default;//деструктор
    Vec3dT<T>& operator=(const Vec3dT<T>& rhs);//присваивание
    bool operator==(const Vec3dT<T>& rhs);
    bool operator!=(const Vec3dT<T>& rhs) { return !operator==(rhs); }
    Vec3dT<T>& operator+=(const Vec3dT<T>& rhs);
    Vec3dT<T>& operator-=(const Vec3dT<T>& rhs);
    Vec3dT<T>& operator*=(const double& rhs);
    Vec3dT<T>& operator/=(const double& rhs);

    std::ostream& writeTo(std::ostream& ostr);

    T x{ T() };
    T y{ T() };
    T z{ T() };

};

template<typename T>
Vec3dT<T>::Vec3dT(const T a, const T b, const T c)
    :x(a), y(b), z(c)
{
}

template<typename T>
Vec3dT<T>::Vec3dT(const Vec3dT<T>& v)
    : x(v.x), y(v.y), z(v.z)
{
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator=(const Vec3dT<T>& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

template<typename T>
inline bool Vec3dT<T>::operator==(const Vec3dT<T>& rhs)
{
    double eps = 1E-10;
    return (std::abs(x - rhs.x) < eps) && (std::abs(y - rhs.y) < eps) && (std::abs(z - rhs.z) < eps);
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator+=(const Vec3dT<T>& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator-=(const Vec3dT<T>& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator*=(const double& rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

template<typename T>
Vec3dT<T>& Vec3dT<T>::operator/=(const double & rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

template <typename T>
Vec3dT<T> operator+(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs) 
{
    return Vec3dT<T>(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

template <typename T>
Vec3dT<T> operator-(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)
{
    return Vec3dT<T>(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

template <typename T>
Vec3dT<T>  operator*(const Vec3dT<T>& lhs, const double& rhs)//умножение вектора на число
{
    return Vec3dT<T>(lhs.x*rhs, lhs.y*rhs, lhs.z*rhs);
}

template <typename T>
double operator*(const Vec3dT<T>& lhs, const Vec3dT<T>& rhs)// скалярное произведение
{
    return lhs.x*rhs.x + lhs.y*rhs.y + lhs.z*rhs.z;
}

template <typename T>
double Module(const Vec3dT<T>& rhs)//модуль(длина вектора)
{
    return std::sqrt(rhs.x*rhs.x + rhs.y*rhs.y + rhs.z*rhs.z);
}

template <typename T>
Vec3dT<T> Multiple(const Vec3dT<T> lhs, const Vec3dT<T>& rhs)//векторное произведение
{
    return Vec3dT<T>(lhs.y*rhs.z - lhs.z*rhs.y, lhs.z*rhs.x - lhs.x*rhs.z, lhs.x*rhs.y - lhs.y*rhs.x);
}

template <typename T>
inline std::ostream& operator<<(std::ostream& ostrm, Vec3dT<T>& b)
{
    return b.writeTo(ostrm);
}

template<typename T>
std::ostream & Vec3dT<T>::writeTo(std::ostream & ostr)
{
    ostr << "{ " << x << " , " << y << " , " << z << " }   ";
    return ostr;
}

#endif


