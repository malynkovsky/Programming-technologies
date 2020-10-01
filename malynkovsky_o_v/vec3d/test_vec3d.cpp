#include "vec3d.h"

int main()
{
    using namespace std;
    Vec3d AB(7.2, -8.0, 1.4);
    Vec3d CD(7.5, 1.9, -2.0);
    
    cout << "Vector AB: " << AB << "Vector CD: " << CD << endl;
    cout << endl;
    cout << "Check copy constructor ( Let AB = copy, copy(1.3, -4.0, 8.6)):" << endl;
    Vec3d copy(1.3, -4.0, 8.6);
    AB = Vec3d(copy);
    cout << "Vector AB: " << AB << endl;
    cout << endl;

    cout << "Check = operator:" << endl;
    Vec3d EF(6.2, -3.0, 4.1);
    AB = EF;
    cout << "Let AB = EF,   EF = " << EF << "Vector AB: " << AB << endl;
    cout << "Module of AB : " << Module(AB) << endl;
    cout << endl;

    cout << "Check bool operators:" << endl;
    cout << "AB == AB : " << (AB == AB) << "    AB == EF : " << (AB == CD) << "    AB != CD : " << (AB != CD) << endl;
    cout << endl;

    cout << "Check operator +, AB+CD : " << (AB + CD) << endl;
    cout << "Check operator -, AB-CD : " << (AB - CD) << endl;
    cout << "Check operator *, (AB * CD) - scalar : " << (AB * CD) << endl;
    double k = 4.2;
    cout << "k = " << k << endl;
    cout << "Check operator *(double), AB * k : " << (AB * k) << endl;
    cout << endl;

    cout << "Vector AB: " << AB << "Vector CD: " << CD << endl;
    Vec3d QR(1.3, -4.0, 8.6);
    cout << "Check operator +=, AB+=QR : " << (AB += QR) << endl;
    cout << "Check operator -=, AB-=QR : " << (CD -= QR) << endl;
    cout << "k = " << k << endl;
    cout << "Check operator *=, AB*=k : " << (AB *= k) << endl;
    cout << "Check operator /=, CD/=k : " << (CD /= k) << endl;
    cout << endl;
    cout << "Check [AB * CD] - vector  " << Multiple(AB, CD) << endl;
    return 0;
}