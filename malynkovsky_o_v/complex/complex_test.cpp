#include "complex.h"
#include <iostream>
#include <sstream>
#include <cmath>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error  : " << str << " -> " << z << endl;
    }
    return istrm.good();
}

int main()
{
    using namespace std;

    Complex z;
    z += Complex(8.2,2);
    cout << "z = " << z << endl;
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
    cout << endl;
    cout << endl;
    Complex a(6.5, 3.7);
    Complex b(2.3, 4.0);
    Complex Cmpl(2.0);
    Complex plus, minus, multi, div;
    plus = a + b; minus = a - b;
    multi = a * b; div = a / b;
    cout << "First complex number (a):  " << a << "    Second (b): " << b << endl;
    cout << endl;
    cout << "a == a  " << (a == a) << "   a != a  " << (a != a) << "    a == b  " << (a == b)<< endl;
    cout << endl;
    cout << "Complex (+-*/) Complex" << endl;
    cout << " a + b" << plus << "   a - b " << minus << "   a * b  " << multi << "    a / b  " << div << endl;
    cout << endl;
    double Dbl = 1.5;
    plus = a + Dbl; minus = a - Dbl;
    multi = b * Dbl; div = b / Dbl;
    cout << "Complex (+-*/) double" << "  double C = "<< Dbl << endl;
    cout << " a + C  " << plus << "    a - C  " << minus << "    b * C  " << multi << "    b / C  " << div << endl;
    cout << endl;
    plus += z; minus -= z; multi *= z; div /= z;
    cout << "Complex (+-*/)= Complex" << "complex Z = " << Cmpl << endl;
    cout << " a += Z  " << plus << "   a -= Z " << minus << "   a *= Z " << multi << "    a /= Z  " << div << endl;
    cout << endl;
    plus += Dbl; minus -= Dbl;
    multi *= Dbl; div /= Dbl;
    cout << "Complex (+-*/)= double" << "  double C = " << Dbl << endl;
    cout << " a += C  " << plus << "    a -= C  " << minus << "    a *= C  " << multi << "    a /= C  " << div << endl;
    cout << endl;
    cout << "Z = " << z << "    Complex number conjugate to z = " << Con(z) << endl;
    cout << endl;
    cout << "Z = " << z << "    Z to the power of 4 = " << Power(z,4) << endl;
    cout << endl;
    Complex *arr = Root(z, 4);
    cout << "Z = " << z << "    4th root from Z =  soon" << endl;
    int t;
    cin >> t;
    
    return 0;
}