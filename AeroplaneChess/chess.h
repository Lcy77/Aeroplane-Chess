#ifndef CHESS_H
#define CHESS_H

#include "qpoint.h"
enum CHESS_TYPE{
    CHESS_RED = 1,
    CHESS_YELLOW,
    CHESS_BLUE,
    CHESS_GREEN,
    CHESS_MAX,
};

class Chess
{
public:
    Chess(){}
    Chess(CHESS_TYPE t,QPoint pt);
    ~Chess(void);
    void Fly(bool);     //飞机起飞
    void Position(int);     //设定所在位置的编号
    void Forward(int);      //前进X格
    void ChangePoint(QPoint);       //改变棋子的坐标
public:
    int position;   //所在位置编号
    CHESS_TYPE c_type;      //棋子类型
    QPoint c_pt;			//位置
    bool ifStart;			//棋子是否已经出发
};


#endif // CHESS_H
