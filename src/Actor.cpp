#include "Actor.h"

#define MAP_WIDTH 20
#define MAP_HEIGHT 15

Actor::Actor(void)
{
    //ctor
}

void Actor::SetAppearance(char nDisplayChar, short nColorPair)
{
    this->nDisplayChar = nDisplayChar;
    this->nColorPair = nColorPair;
}

void Actor::SetPos(int x, int y)
{
    if((x<0)||(x>=MAP_WIDTH)||(y<0)||(y>=MAP_HEIGHT))
    {
        return;
    }
    this->nPosX = x;
    this->nPosY = y;
}


Actor::~Actor()
{
    //dtor
}
