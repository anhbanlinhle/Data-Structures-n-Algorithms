#include <iostream>
#include <iomanip>

#include "Point.h"
#include "Line.h"

using namespace std;

int main() {

	double a1,a2,b1,b2,c1,c2,d1,d2;
    cin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2;
    
    Point A(a1,a2);
    Point B(b1,b2);
    Line AB(A,B);

    Point C(c1,c2);
    Point D(d1,d2);
    Line CD(C,D);

    cout << fixed << setprecision(2);

    Point L1 = AB.dFormula();
    Point L2 = CD.dFormula();

    if (L1.x == L2.x) {
        if (L1.y == L2.y) 
            cout << "MANY";
        else 
            cout << "NO";
    }

    else {
            double m = (L1.y - L2.y) / (L2.x - L1.x);
            double n = L1.y + m * L1.x;
            
            cout << m << " " << n;
    }

}