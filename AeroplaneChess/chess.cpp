#include "chess.h"

Chess::Chess(CHESS_TYPE t,QPoint pt)
{
    c_type = t;
    c_pt = pt;
    ifStart = false;
    position = 0;
}

Chess::~Chess(void)
{
}

void Chess::Fly(bool x)
{
    ifStart = x;
}

void Chess::Position(int x)
{
    position = x;
}

void Chess::Forward(int x)
{
    position += x;
}

void Chess::ChangePoint(QPoint t)
{
    c_pt = t;
}
