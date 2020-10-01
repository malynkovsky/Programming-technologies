#ifndef VEC3D_2017_1234
#define VEC3D_2017_1234

#include <iostream>

struct Vec3d 
{
    Vec3d() = default;
    Vec3d(const double a, const double b, const double c);
    Vec3d(const Vec3d& v);//���������� �����������
    ~Vec3d() = default;//����������
    Vec3d& operator=(const Vec3d& rhs);//������������
    bool operator==(const Vec3d& rhs);
    bool operator!=(const Vec3d& rhs) { return !operator==(rhs); }
    Vec3d& operator+=(const Vec3d& rhs);
    Vec3d& operator-=(const Vec3d& rhs);
    Vec3d& operator*=(const double& rhs);
    Vec3d& operator/=(const double& rhs);
    
    std::ostream& writeTo(std::ostream& ostr);

    double x{ 0.0 };
    double y{ 0.0 };
    double z{ 0.0 };

};

Vec3d operator+(const Vec3d& lhs, const Vec3d& rhs);
Vec3d operator-(const Vec3d& lhs, const Vec3d& rhs);
double operator*(const Vec3d& lhs, const Vec3d& rhs);// ��������� ������������
Vec3d operator*(const Vec3d& lhs, const double& rhs);//��������� ������� �� �����

double Module(const Vec3d& rhs);//������(����� �������)
Vec3d Multiple(const Vec3d& lhs, const Vec3d& rhs);//��������� ������������

inline std::ostream& operator<<(std::ostream& ostrm, Vec3d& b)
{
    return b.writeTo(ostrm);
}

#endif
