
#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line{
    public: 
        Line();
        ~Line();
        Point A;
        Point B;
        

    Line(Point A, Point B);
    Point dFormula();
    
};

#endif