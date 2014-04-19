#include <iostream>
#include <curses.h>

using namespace std;

//This is the map! It is an array that holds a bunch of chars.

//Map dimensions
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

int fMapArray[MAP_HEIGHT][MAP_WIDTH] = {
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

int fItemArray[MAP_HEIGHT][MAP_WIDTH] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 3, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

//These are types of tiles!
struct TILE_TYPE
{
    char nCharacter;
    bool bPassable;
    short nColorPair;
};

#define TILE_FLOOR 0
#define TILE_WALL 1
#define TILE_CLOSEDDOOR 2
#define TILE_OPENDOOR 3
#define TILE_WATER 4

TILE_TYPE sTileIndex[] = {
    {'.', TRUE, 5},    //(0) TILE_FLOOR
    {'#', FALSE, 5},   //(1) TILE_WALL
    {'+', FALSE, 1},   //(2) TILE_CLOSEDDOOR
    {'/', TRUE, 1},    //(3) TILE_OPENDOOR
    {'~', FALSE, 6},   //(4) TILE_WATER
};

struct ITEM_TYPE
{

    char nCharacter;
    char * pName;
    short nColorPair;
};

#define ITEM_EMPTY 0

ITEM_TYPE sItemIndex[] = {
    { ' ',  "Empty", 5},        //(0) Empty
    { '!', "Potion", 3},  //(1) Potion
    { 'b', "Throwing stone", 5},//(2) Throwing stone
    { '/', "Short sword", 5},   //(3) Short sword

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


    if(fItemArray[y][x] != ITEM_EMPTY)
    {
        int nType = fItemArray[y][x];
        attron(COLOR_PAIR(sItemIndex[nType].nColorPair));
        mvaddch(y,x,sItemIndex[nType].nCharacter);
        attroff(COLOR_PAIR(sItemIndex[nType].nColorPair));
    }
    else
    {
        int nType = fMapArray[y][x];
        attron(COLOR_PAIR(sTileIndex[nType].nColorPair));
        mvaddch(y,x,sTileIndex[nType].nCharacter);
        attroff(COLOR_PAIR(sTileIndex[nType].nColorPair));
    }
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
    fMapArray[fMapY][fMapX] = 3;
    DrawMap();
    return 0;
}

int CloseDoor(int fMapX, int fMapY)
{
    int fTile = fMapArray[fMapY][fMapX];
    if(fTile == 3) {
        fMapArray[fMapY][fMapX] = 2;
        DrawMap();
    }
    return 0;
}

bool IsDoor(int fMapX, int fMapY)
{
    int fTile = fMapArray[fMapY][fMapX];
    if (fTile == 3) {
        return true;
    }
    return false;
}
bool IsPassable(int fMapX, int fMapY)
{
    if(fMapX < 0 || fMapX >= MAP_WIDTH || fMapY < 0 || fMapY >= MAP_HEIGHT){
        return false;
    }
    int fTile = fMapArray[fMapY][fMapX];

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

int main()
{
    initscr();
    keypad(stdscr,1);
    start_color();
    //init_color(COLOR_YELLOW, 220, 210, 0); //Not sure if my commandline can change colors
    ColorInit();
    //Location variables
    int x = 1;
    int y = 1;
    int ch; //Key input variable
    curs_set(0);
    noecho(); //Turns off echo, which is when input character shows on screen.
    int nDeX;
    int nDeY;
    while(true)
    {
        DrawMap();
        mvaddch(y,x,'@');
        nDeX = 0;
        nDeY = 0;
        //ch=getch();
        switch(ch=getch())
        {
            case KEY_DOWN:
                nDeX = 0;
                nDeY = 1;
                break;
            case KEY_UP:
                nDeX = 0;
                nDeY = -1;
                break;
            case KEY_LEFT:
                nDeX = -1;
                nDeY = 0;
                break;
            case KEY_RIGHT:
                nDeX = 1;
                nDeY = 0;
                break;
            case KEY_C2:
                nDeX = 0;
                nDeY = 1;
                break;
            case KEY_A2:
                nDeX = 0;
                nDeY = -1;
                break;
            case KEY_B1:
                nDeX = -1;
                nDeY = 0;
                break;
            case KEY_B3:
                nDeX = 1;
                nDeY = 0;
                break;
            case KEY_C1:
                nDeX = -1;
                nDeY = 1;
                break;
            case KEY_C3:
                nDeX = 1;
                nDeY = 1;
                break;
            case KEY_A1:
                nDeX = -1;
                nDeY = -1;
                break;
            case KEY_A3:
                nDeX = 1;
                nDeY = -1;
                break;
            //I realized I had to use the ASCII decimal that corresponds to the escape char!
            case 27: //ESCAPE
                return 0;
            case 'c': //c key
                int dir;
                addstr("Which direction?");
                mvaddch(y,x,'@');
                refresh();
                dir = getch();
                switch(dir)
                {
                case KEY_DOWN:
                    CloseDoor(x,y+1);
                    break;
                case KEY_UP:
                    CloseDoor(x,y-1);
                    break;
                case KEY_LEFT:
                    CloseDoor(x-1,y);
                    break;
                case KEY_RIGHT:
                    CloseDoor(x+1,y);
                    break;
                case KEY_C2:
                    CloseDoor(x,y+1);
                    break;
                case KEY_A2:
                    CloseDoor(x,y-1);
                    break;
                case KEY_B1:
                    CloseDoor(x-1,y);
                    break;
                case KEY_B3:
                    CloseDoor(x+1,y);
                    break;
                case KEY_C1:
                    CloseDoor(x-1,y+1);
                    break;
                case KEY_C3:
                    CloseDoor(x+1,y+1);
                    break;
                case KEY_A1:
                    CloseDoor(x-1,y-1);
                    break;
                case KEY_A3:
                    CloseDoor(x+1,y-1);
                    break;
                }
                clear(); //This gets rid of the leftover addstr.
                //refresh(); //Don't seem to need this?
                break;
            //If it receives anything else, it gets ignored.
            default:
                break;
        }

        //Check passability
        if(IsPassable(x+nDeX, y+nDeY))
        {
            x += nDeX;
            y += nDeY;
        }
    }

    endwin();

    return 0;
}


