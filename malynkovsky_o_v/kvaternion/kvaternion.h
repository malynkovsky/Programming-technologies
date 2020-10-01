#ifndef KVATERNION_KOSHKA
#define KVATERNION_KOSHKA
#include <iostream>

class Kvaternion
{
public:
    Kvaternion() = default;
    Kvaternion(const int a, const int b, const int c, const int d);
    Kvaternion(const Kvaternion& v);
    ~Kvaternion() = default;
    Kvaternion& operator=(const Kvaternion& rhs);
    Kvaternion Multiple(const Kvaternion& rhs);
    int Determinate();//Определитель
    Kvaternion& operator+=(const Kvaternion& rhs);
    Kvaternion& operator-=(const Kvaternion& rhs);
    Kvaternion& operator*=(const int& rhs);
    Kvaternion& operator/=(const int& rhs);

    std::ostream& writeTo(std::ostream& ostr);

private:
    int a;
    int b;
    int c;
    int d;
};

Kvaternion operator+(const Kvaternion& lhs, const Kvaternion& rhs);
Kvaternion operator-(const Kvaternion& lhs, const Kvaternion& rhs);
Kvaternion operator*(const Kvaternion& lhs, const Kvaternion& rhs);//произведение матриц

inline std::ostream& operator<<(std::ostream& ostrm, Kvaternion& b)
{
    return b.writeTo(ostrm);
}

#endif