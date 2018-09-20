#include "player.h"

Player::Player(PLAYER_TYPE type){
    p_type = type;
}

void Player::addChess(Chess c)
{
    p_chess.push_back(c);
}

void Player::setType(PLAYER_TYPE t){
    p_type = t;
}

int Player::getType(){
    return p_type;
}

Chess *Player::getchess(int i){
    return &p_chess[i];
}
