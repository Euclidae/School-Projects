#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double a,b,c,d ,X1,X2;
    cout << "Enter a: ";
    cin >> a;
    cout << endl;

    cout << "Enter b: ";
    cin >> b;
    cout << endl;

    cout << "Enter c: ";
    cin >> c;
    cout << endl;

    d = (pow(b,2)-(4*a*c));
    X1 = ((-b+sqrt(d))/(2*a));
    X2 = ((-b-sqrt(d))/(2*a));

    cout << "X1 = " << X1 << endl << "X2 = " << X2;
    cin.get();
    return 0;
    }
