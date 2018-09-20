#include "circle.h"

Circle::Circle(CIRCLE_TYPE t, int order, QPoint pt, int n){
    num = order;
    x_type = t;
    x_pt = pt;
    type = n;
    sum = 0;
}

Circle::~Circle(void){
}

QPoint Circle::point(){
    return x_pt;
}
