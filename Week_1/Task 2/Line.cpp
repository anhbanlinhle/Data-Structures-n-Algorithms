#include "Line.h"
#include "Point.h"

Line::Line(){
}

Line::~Line(){

}

Line::Line(Point A, Point B) {
        this->A = A;
        this->B = B;
}

Point Line::dFormula() {
    double m,n;

    if(A.x != B.x) {
        m = (A.y - B.y) / (A.x - B.x);
        n = A.y - m*A.x;

    }
    else {
        n = (A.y + B.y) / 2;
        m = (A.y - n) / A.x;

    }

        Point Formula(m,n);
        return Formula;
}