#ifndef RATIONAL_H_CAT
#define RATIONAL_H_CAT

#include <iosfwd>

class Rational {
public:
    Rational() = default;
    explicit Rational(const int up);
    Rational(const int up, const int down);
    bool operator==(const Rational& rhs) const { return (num == rhs.num) && (denum == rhs.denum); }
    bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
    bool operator<(const Rational& rhs)  const { return ((num * rhs.denum - denum * rhs.num) < 0)||((denum * rhs.denum) < 0); }
    bool operator>(const Rational& rhs)  const { return !operator<(rhs) && !operator==(rhs); }
    void shorten(Rational& rhs);
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
    std::ostream& writeTo(std::ostream& ostr);
private:
    int num{ 0 };
    int denum{ 1 };

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

Rational operator+(const Rational& lhs, const int& rhs);
Rational operator-(const Rational& lhs, const int& rhs);
Rational operator*(const Rational& lhs, const int& rhs);
Rational operator/(const Rational& lhs, const int& rhs);

Rational operator+(const int& lhs, const Rational& rhs);
Rational operator-(const int& lhs, const Rational& rhs);
Rational operator*(const int& lhs, const Rational& rhs);
Rational operator/(const int& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, Rational& b)
{
    return b.writeTo(ostrm);
}

#endif