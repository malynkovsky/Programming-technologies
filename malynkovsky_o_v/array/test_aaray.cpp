#include "array.h"
#include <iostream>

int main()
{
    Array AB(5);
    AB.Add(-6);
    AB.Add(9);
    AB.Add(0);
    AB.Add(1);
    AB.Add(0);
    AB.Add(1);
    cout << AB;
    int t = 5;
    cin >> t;
    return 0;
}