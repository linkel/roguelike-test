#include <iostream>
#include <curses.h>

using namespace std;

//This is the map! It is an array that holds a bunch of chars.

//Map dimensions
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

//Tiles
#define TILE_FLOOR 0
#define TILE_WALL 1
#define TILE_CLOSEDDOOR 2
#define TILE_OPENDOOR 3

int firstMapArray[MAP_HEIGHT][MAP_WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 1, 1, 2, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void DrawMap(void)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        //move(0,y);
        for(int x = 0; x < MAP_WIDTH; x++)
        {
            switch (firstMapArray[y][x])
            {
            case TILE_FLOOR:
                mvaddch(y,x,'.');
                break;
            case TILE_WALL:
                mvaddch(y,x,'#');
                break;
            case TILE_CLOSEDDOOR:
                mvaddch(y,x,'+');
                break;
            case TILE_OPENDOOR:
                mvaddch(y,x,'/');
                break;
            }
        }
    }
}

int OpenDoor(int fMapX, int fMapY)
{
    firstMapArray[fMapY][fMapX] = TILE_OPENDOOR;
    DrawMap();
    return 0;
}

bool IsPassable(int fMapX, int fMapY)
{
    if(fMapX < 0 || fMapX >= MAP_WIDTH || fMapY < 0 || fMapY >= MAP_HEIGHT){
        return false;
    }
    int fTile = firstMapArray[fMapY][fMapX];
    //So if the tile looked at is a floor tile it returns true, else false.
    if(fTile == TILE_FLOOR || fTile == TILE_OPENDOOR) {
        return true;
    }
    if(fTile == TILE_CLOSEDDOOR) {
        OpenDoor(fMapX, fMapY);
        return false;
    }
    return false;
}


//function prototypes
void DrawMap(void);

int main()
{
    keypad(initscr(),1);
    start_color();
    int x = 1;
    int y = 1;
    //int yy;
    //int xx;
    int ch; //Key input variable
    curs_set(0);
    //keypad(stdscr, TRUE);
    noecho(); //Turns off echo, which is when input character shows on screen.
    while('q'!=(ch=getch())) //as long as the character input is not q the program goes on
    {
        //for(yy=0;yy<11;yy++){
        //    for(xx=0;xx<15;xx++){
        //        mvaddch(yy,xx,map[yy][xx]);
        //    }
        DrawMap();

        if (ch == KEY_DOWN && IsPassable(x,y+1))
        {
            y++;
        }
        if (ch == KEY_UP && IsPassable(x,y-1)) //same as above. upper left is 0,0, y increases downwards
        {
            y--;
        }
        if (ch == KEY_LEFT && IsPassable(x-1,y))
        {
            x--;
        }
        if (ch == KEY_RIGHT && IsPassable(x+1,y))
        {
            x++;
        }

        mvaddch(y,x,'@'); //mvaddch takes a char, mvprintw takes a string and invokes printf
        //refresh(); //do I need this?
    }
    endwin();

    return 0;
}


