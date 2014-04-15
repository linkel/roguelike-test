#include <iostream>
#include <curses.h>

using namespace std;

//This is the map! It is an array that holds a bunch of chars.

//Map dimensions
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

/*
//Tiles. I don't think I need this anymore after rewriting the tile type code.
#define TILE_FLOOR 0
#define TILE_WALL 1
#define TILE_CLOSEDDOOR 2
#define TILE_OPENDOOR 3
*/

int firstMapArray[MAP_HEIGHT][MAP_WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4 },
    { 0, 0, 1, 2, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 4, 4, 4 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

struct TILE_TYPE
{
    char nCharacter;
    bool bPassable;
    short nColorPair;
};

TILE_TYPE sTileIndex[] = {
    {'.', TRUE, 5},    //(0) TILE_FLOOR
    {'#', FALSE, 5},   //(1) TILE_WALL
    {'+', FALSE, 1},   //(2) TILE_CLOSEDDOOR
    {'/', TRUE, 1},    //(3) TILE_OPENDOOR
    {'~', FALSE, 6},   //(4) TILE_WATER
};


void ColorInit (void)
{
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);
    init_pair(6, COLOR_BLUE, COLOR_BLUE);
}

void DrawTile(int x, int y)
{
    int nType = firstMapArray[y][x];
    attron(COLOR_PAIR(sTileIndex[nType].nColorPair));
    mvaddch(y,x,sTileIndex[nType].nCharacter);
    attroff(COLOR_PAIR(sTileIndex[nType].nColorPair));
}

void DrawMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            DrawTile(x,y);
        }
    }
}

int OpenDoor(int fMapX, int fMapY)
{
    firstMapArray[fMapY][fMapX] = 3;
    DrawMap();
    return 0;
}

bool IsPassable(int fMapX, int fMapY)
{
    if(fMapX < 0 || fMapX >= MAP_WIDTH || fMapY < 0 || fMapY >= MAP_HEIGHT){
        return false;
    }
    int fTile = firstMapArray[fMapY][fMapX];

    //If it is a closed door, runs opendoor function.
    if(fTile == 2) {
        OpenDoor(fMapX, fMapY);
        return false;
    }

    return sTileIndex[fTile].bPassable;
    /*
    //So if the tile looked at is a floor tile it returns true, else false.
    if(fTile == TILE_FLOOR || fTile == TILE_OPENDOOR) {
        return true;
    }
    }
    return false;
    */
}

int nChangeX;
int nChangeY;

int main()
{
    initscr();
    keypad(stdscr,1);
    start_color();
    //init_color(COLOR_YELLOW, 220, 210, 0); //Not sure if my commandline can change colors
    ColorInit();
    int x = 1;
    int y = 1;
    int ch; //Key input variable
    curs_set(0);
    noecho(); //Turns off echo, which is when input character shows on screen.
    while('q'!=(ch=getch())) //as long as the character input is not q the program goes on
    {
        DrawMap();

        if (ch == KEY_DOWN && IsPassable(x,y+1))
        {
            nChangeX=0;
            nChangeY=1;
            //y++;
        }
        if (ch == KEY_UP && IsPassable(x,y-1)) //same as above. upper left is 0,0, y increases downwards
        {
            nChangeX=0;
            nChangeY=1;
            //y--;
        }
        if (ch == KEY_LEFT && IsPassable(x-1,y))
        {
            nChangeX=1;
            nChangeY=0;
            //x--;
        }
        if (ch == KEY_RIGHT && IsPassable(x+1,y))
        {
            nChangeX=0;
            nChangeY=1;
            //x++;
        }

        mvaddch(nChangeY,nChangeX,'@');
        //refresh(); //do I need this?
    }
    endwin();

    return 0;
}


