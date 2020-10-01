#include "kvaternion.h"
#include <iostream>

int main()
{
    using namespace std;
    Kvaternion First(4, 6, -2, 3);
    Kvaternion Second(-7, 8, 0, 9);
    Kvaternion copy(-1, 4, -5, 0);
    
    cout << "First = " << First << endl;
    cout << "Second = " << Second << endl;
    cout << "Ckeck copy constructor, let Second = copy" << endl;
    cout << "copy = " << copy << endl;
    Second = Kvaternion(copy);
    cout << "Second = " << Second << endl;

    cout << "Check +=, -= , *=, /= \n";
    Kvaternion test(-2, 0, 8, 1);
    cout << "test = " << test << endl;
    First += test;
    cout << "First += test = " << First << endl;
    Second -= test;
    cout << "Second -= test = " << Second << endl;
    int inc = 10;
    First *= inc;
    cout << "First *= " << inc << " = "<< First << endl;
    First /= inc;
    cout << "First /= " << inc << " = " << First << endl;

    cout << "Check +, - , *\n";
    test = First + Second;
    cout << "First + Second = " << test << endl;
    test = First - Second;
    cout << "First - Second = " << test << endl;
    cout << "First * Second = " << First*Second << endl;
    cout << "test = " << test << endl;
    cout << "Determinate of test = " << test.Determinate() << endl;
    return 0;
}
