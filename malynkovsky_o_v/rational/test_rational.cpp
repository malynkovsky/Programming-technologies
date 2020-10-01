#include "rational.h"
#include <iostream>

int main()
{
    using namespace std;

    Rational a(20, 15), b(3, 27), c(-9, 2), d(4, -7);
    Rational q(15), w(-9), r(2);
    cout << "a = " << a << "    b = " << b << "    c = " << c << "   d = " << d << endl;
    cout << "(a == b)  " << (a == b) << "    (c != d)  " << (c != d) << "   (d > b)  " << (d > b) << "   (a < d)  " << (a < d) << "   q > c  " << (q > c) << endl;
    cout << endl;
    

    Rational plus, minus, multiple, div;
    plus = a + b; minus = b - c; multiple = c * d; div = d / a;
    cout << "Rational +-*/ Rational " << endl;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "a + b =  " << plus << "    b - c = " << minus << "    c * d = " << multiple << "    d / a = " << div << endl;
    cout << endl;
    cout << "(plus == minus) " << (plus == minus) << "    (multiple != div) " << (multiple != div) << "    (div > minus) " << (div > minus) << "    (plus < div) " << (plus < div) << endl;
    cout << endl;
    cout << "Rational (+-*/)= Rational" <<endl;
    plus += a; minus -= b; multiple *= c; div /= d;
    cout << "   PLus               " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "Plus += a " << plus << "    Minus -= b " << minus << "    Multiple *= c " << multiple << "    Div /= d " << div << endl;
    cout << endl;
    cout << "(plus != minus) " << (plus != minus) << "    (multiple == div) " << (multiple == div) << "    (div < minus) " << (div < minus) << "    (plus > div) " << (plus > div) << endl;
    cout << endl;

    cout << "q = " << q << "    w = " << w << "    r = " << r << endl;
    cout << "(q == w)  " << (q == w) << "    (w != r)  " << (w != r) << "    (w != w)  " << (w != w) << "    (r < q)  " << (r < q) << endl;
    cout << endl;
    plus = Rational(0); minus = Rational(0); multiple = Rational(0); div = Rational(0);
    cout << "plus =  " << plus << "    minus = " << minus << "    multiple = " << multiple << "    div = " << div << endl;
    cout << endl;
    plus = q + w; minus = w - r; multiple = r * q; div = q / w;
    cout << "Rational +-*/ Rational " << endl;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "q + w =  " << plus << "    w - r = " << minus << "    r * q = " << multiple << "    q / w = " << div << endl;
    cout << endl;
    cout << "(plus == minus) " << (plus == minus) << "    (multiple != div) " << (multiple != div) << "    (div > minus) " << (div > minus) << "    (plus < div) " << (plus < div) << endl;
    cout << endl;
    cout << "Rational (+-*/)= Rational" << endl;
    plus += q; minus -= w; multiple *= r; div /= q;
    cout << "   PLus               " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "Plus += q " << plus << "    Minus -= w " << minus << "    Multiple *= r " << multiple << "    Div /= q " << div << endl;
    cout << endl;
    cout << "(plus != minus) " << (plus != minus) << "    (multiple == div) " << (multiple == div) << "    (div < minus) " << (div < minus) << "    (plus > div) " << (plus > div) << endl;
    cout << endl;
    cout << endl;

    cout << "Rational +-*/ int      int dec = 4" << endl;
    cout << endl;
    plus = Rational(0); minus = Rational(0); multiple = Rational(0); div = Rational(0);
    int dec = 4;
    plus = a + 4; minus = b - 4; multiple = c * 4; div = d / 4;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "a + dec =  " << plus << "    b - dec = " << minus << "    c * dec = " << multiple << "    d / dec = " << div << endl;
    cout << endl;
    plus = Rational(0); minus = Rational(0); multiple = Rational(0); div = Rational(0);
    plus = q + 4; minus = w - 4; multiple = r * 4; div = q / 4;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "q + dec =  " << plus << "    w - dec = " << minus << "    r * dec = " << multiple << "    q / dec = " << div << endl;
    cout << endl;

    cout << "int +-*/ Rational            int dec = 4" << endl;
    cout << endl;
    plus = Rational(0); minus = Rational(0); multiple = Rational(0); div = Rational(0);
    plus = 4 + a; minus = 4 - b; multiple = 4 * d; div = 4 / d;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "dec + a =  " << plus << "    dec - b = " << minus << "    dec * c = " << multiple << "    dec / d = " << div << endl;
    cout << endl;
    plus = Rational(0); minus = Rational(0); multiple = Rational(0); div = Rational(0);
    plus = 4 + q; minus = 4 - w; multiple = 4 * r; div = 4 / q;
    cout << "   PLus          " << "    Minus             " << "    Multiple            " << "    Div " << endl;
    cout << "dec + q =  " << plus << "    dec - w = " << minus << "    dec * r = " << multiple << "    q / dec = " << div << endl;
    cout << endl;

    int t;
    cin >> t;
    return 0;
}