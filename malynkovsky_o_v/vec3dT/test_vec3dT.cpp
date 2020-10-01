#include "vec3dT.h"
#include <iostream>

int main()
{
    using namespace std;
    Vec3dT<double> AB(7.2, -8.0, 1.4);
    Vec3dT<double> CD(7.5, 1.9, -2.0);
    cout << "Vector AB: " << AB << "Vector CD: " << CD << endl;
    cout << endl;
    cout << "Check copy constructor ( Let AB = copy, copy(1.3, -4.0, 8.6)):" << endl;
    Vec3dT<double> copy(1.3, -4.0, 8.6);
    AB = Vec3dT<double>(copy);
    cout << "Vector AB: " << AB << endl;
    cout << endl;

    cout << "Check = operator:" << endl;
    Vec3dT<double> EF(6.2, -3.0, 4.1);
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
    Vec3dT<double> QR(1.3, -4.0, 8.6);
    cout << "Check operator +=, AB+=QR : " << (AB += QR) << endl;
    cout << "Check operator -=, AB-=QR : " << (CD -= QR) << endl;
    cout << "k = " << k << endl;
    cout << "Check operator *=, AB*=k : " << (AB *= k) << endl;
    cout << "Check operator /=, CD/=k : " << (CD /= k) << endl;
    cout << endl;
    cout << "Check [AB * CD] - vector  " << Multiple(AB, CD) << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    ///////////////////////////

    Vec3dT<int> QW(7, -3, 4);
    Vec3dT<int> RT(5, 2, -8);
    cout << "Vector QW: " << QW << "Vector RT: " << RT << endl;
    cout << endl;
    cout << "Check copy constructor ( Let QW = copy, copy(3, -4, 6)):" << endl;
    Vec3dT<int> copy1(3, -4, 6);
    QW = Vec3dT<int>(copy1);
    cout << "Vector QW: " << QW << endl;
    cout << endl;

    cout << "Check = operator:" << endl;
    Vec3dT<int> OP(6, -3, 4);
    QW = OP;
    cout << "Let QW = OP,   OP = " << OP << "Vector QW: " << QW << endl;
    cout << "Module of QW : " << Module(QW) << endl;
    cout << endl;

    cout << "Check bool operators:" << endl;
    cout << "QW == QW : " << (QW == QW) << "    QW == OP : " << (QW == RT) << "    QW != RT : " << (QW != RT) << endl;
    cout << endl;

    cout << "Check operator +, QW+RT : " << (QW + RT) << endl;
    cout << "Check operator -, QW-RT : " << (QW - RT) << endl;
    cout << "Check operator *, (AB * CD) - scalar : " << (AB * CD) << endl;
    int s = 4;
    cout << "s = " << s << endl;
    cout << "Check operator *(double), AB * k : " << (AB * k) << endl;
    cout << endl;

    cout << "Vector QW: " << AB << "Vector RT: " << CD << endl;
    Vec3dT<int> CC(1, -4, 2);
    cout << "Check operator +=, QW+=CC : " << (QW += CC) << endl;
    cout << "Check operator -=, RT-=CC : " << (RT -= CC) << endl;
    cout << "s = " << s << endl;
    cout << "Check operator *=, QW*=s : " << (AB *= s) << endl;
    cout << "Check operator /=, RT/=s : " << (CD /= s) << endl;
    cout << endl;
    cout << "Check [QW * RT] - vector  " << Multiple(QW, RT) << endl;
    cin >> k;
    return 0;
}