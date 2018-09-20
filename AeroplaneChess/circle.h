#ifndef CIRCLE_H
#define CIRCLE_H

#include "qpoint.h"
enum CIRCLE_TYPE{
    CIRCLE_RED = 1,
    CIRCLE_YELLOW,
    CIRCLE_BLUE,
    CIRCLE_GREEN,
    CIRCLE_MAX,
};

class Circle
{
private:
    int num;        //位置的顺序编号
    int type;       //位置的类型，1为常规，0为起始点，2为特殊
    int sum;        //位置上棋子的数量，初始为0
    CIRCLE_TYPE x_type;      //位置颜色类型
    QPoint x_pt;			//位置
public:
    Circle(){}
    Circle(CIRCLE_TYPE t, int order, QPoint pt, int n);
    ~Circle(void);
    Circle &operator = (const Circle &c){
        num = c.num;
        x_type = c.x_type;
        x_pt = c.x_pt;
        type = c.type;
    }
    QPoint point();
};
#endif // CIRCLE_H
