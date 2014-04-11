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


int firstMapArray[MAP_HEIGHT][MAP_WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//function prototypes
void DrawMap(void);

int main()
{
    keypad(initscr(),1);
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

        if (ch == KEY_DOWN && TILE_FLOOR==firstMapArray[y+1][x])
        {
            y++;
        }
        if (ch == KEY_UP && TILE_FLOOR==firstMapArray[y-1][x]) //same as above. upper left is 0,0, y increases downwards
        {
            y--;
        }
        if (ch == KEY_LEFT && TILE_FLOOR==firstMapArray[y][x-1])
        {
            x--;
        }
        if (ch == KEY_RIGHT && TILE_FLOOR==firstMapArray[y][x+1])
        {
            x++;
        }
        mvaddch(y,x,'@'); //mvaddch takes a char, mvprintw takes a string and invokes printf
        //refresh(); //do I need this?
    }
    endwin();

    return 0;
}

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
            }
        }
    }
}
