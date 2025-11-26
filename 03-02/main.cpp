#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <memory>
#include "Compare.h"
using namespace std;

int main() {
    SetConsoleOutputCP(65001);

    int a = 10;
    int b = 12;
    float c = 5.5f;
    float d = 7.1f;
    double e = 12.3505;
    double f = 20.007;

    Compare<int,int> compare1(a,b);
    cout << compare1.Min() << endl; // 10

    Compare<float,int> compare2(c,b);
    cout << compare2.Min() << endl; // 5.5f

    Compare<float,float> compare3(c,d);
    cout << compare3.Min() << endl; // 5.5f

    Compare<double,int> compare4(e,a);
    cout << compare4.Min() << endl; // 10

    Compare<double,float> compare5(e,c);
    cout << compare5.Min() << endl; // 5.5f

    Compare<double,double> compare6(e,f);
    cout << compare6.Min() << endl; // 12.3505

    return 0;
}