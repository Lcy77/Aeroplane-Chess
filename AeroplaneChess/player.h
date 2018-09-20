#ifndef PLAYER_H
#define PLAYER_H

#include "chess.h"
#include "qvector.h"

enum PLAYER_TYPE{
    PLAYER_RED = 1,
    PLAYER_YELLOW,
    PLAYER_BLUE,
    PLAYER_GREEN,
};

class Player{
public:
    QVector<Chess> p_chess;
    PLAYER_TYPE p_type;
public:
    Player(){}
    Player(PLAYER_TYPE type);
    void setType(PLAYER_TYPE t);
    int getType();
    Chess* getchess(int i);
    void addChess(Chess c);
};
#endif // PLAYER_H
