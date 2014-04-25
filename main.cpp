#include <iostream>
#include <curses.h>
#include <string.h>

using namespace std;

//This is the map! It is an array that holds a bunch of chars.

//Map dimensions
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

int nMapArray[MAP_HEIGHT][MAP_WIDTH] = {
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

int nItemArray[MAP_HEIGHT][MAP_WIDTH];
/*
int nItemArray[MAP_HEIGHT][MAP_WIDTH] = {
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
*/

//initialized player inventory
#define INV_SLOTS 5
int nInventory[5] = {0, 0, 0, 0, 0};

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
    const char * pName;
    short nColorPair;
};

#define ITEM_EMPTY 0
#define ITEM_BOTTLEWINE 1
#define ITEM_THROWINGSTONE 2
#define ITEM_SHORTSWORD 3
#define ITEM_SKELETONKEY 4
#define ITEM_PICKAXE 5

ITEM_TYPE sItemIndex[] = {
    { ' ',  "Empty", 5},        //(0) Empty
    { '!', "bottle of wine", 2},  //(1) Bottle of wine!
    { '*', "throwing stone", 5},//(2) Throwing stone
    { '/', "short sword", 5},   //(3) Short sword
    { ',', "skeleton key", 1},
    { '(', "pickaxe", 5},
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

void DrawTile(int x, int y);


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

void OpenDoor(int nMapX, int nMapY)
{
    nMapArray[nMapY][nMapX] = 3;
    DrawMap();
}

void CloseDoor(int nMapX, int nMapY)
{
    int fTile = nMapArray[nMapY][nMapX];
    if(fTile == 3) {
        nMapArray[nMapY][nMapX] = 2;
        DrawMap();
    }
}

//Can I put these commands together? So confusing to read.
void CloseCommand (int x, int y)
{
                int dir;
                mvaddstr(MAP_HEIGHT + 2, 2,"Which direction?");
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
                clear();
}

//Thinking of reorganizing somehow.
void GetCommand(int nMapX, int nMapY);
void DropCommand(int nMapX, int nMapY);
void UseItem(void);

bool IsDoor(int nMapX, int nMapY)
{
    int fTile = nMapArray[nMapY][nMapX];
    if (fTile == 3) {
        return true;
    }
    return false;
}


bool IsPassable(int nMapX, int nMapY)
{
    if(nMapX < 0 || nMapX >= MAP_WIDTH || nMapY < 0 || nMapY >= MAP_HEIGHT){
        return false;
    }
    int fTile = nMapArray[nMapY][nMapX];

    //If it is a closed door, runs opendoor function.
    if(fTile == 2) {
        OpenDoor(nMapX, nMapY);
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


void ShowInventory(void)
{
    mvaddstr(1,MAP_WIDTH + 3, "Inventory:");
    mvaddstr(2,MAP_WIDTH + 3, "----------");

    for (int i = 0; i < INV_SLOTS; i++)
    {
        //Get the item type being stored in the array.
        int nItemType = nInventory[i];
        //Draw the item's name onto the screen
        //Addstr adds where the cursor left off.
        //Wonder if I should care to put the cursor back at 0,0?
        mvaddch(3+i, MAP_WIDTH + 2, 'a'+ i);
        addstr(": ");
        addstr(sItemIndex[nItemType].pName);
    }
}
//Saw this code online that people said was a better way to
//write zeros instead of memset.
/*
class ArrInit
{
    int nItemArray[MAP_HEIGHT][MAP_WIDTH];
public:
    ArrInit();
//private:

};

ArrInit::ArrInit()
{
    for(int h = 0; h < MAP_HEIGHT; ++h){
            for(int w = 0; w < MAP_WIDTH; ++w){
                nItemArray[h][w] = 0;
            }
    }
    //Testing the items for now
    nItemArray[3][1] = ITEM_SHORTSWORD;
    nItemArray[5][5] = ITEM_POTION;
    nItemArray[1][8] = ITEM_THROWINGSTONE;
}
*/
int main()
{
    initscr();
    keypad(stdscr,1);
    start_color();
    //Maybe should find a safer way to do this besides memset, heard it circumvents type safety
    //ArrInit nItemArray; //Trying this out instead of memset NOPE NOT FOR NOW

    memset(nItemArray, 0, sizeof(nItemArray)); //Initializes the item map with 0
    //Testing the items for now
    nItemArray[3][1] = ITEM_SHORTSWORD;
    nItemArray[5][5] = ITEM_BOTTLEWINE;
    nItemArray[1][8] = ITEM_THROWINGSTONE;
    nItemArray[1][7] = ITEM_PICKAXE;
    nItemArray[5][4] = ITEM_SKELETONKEY;


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
        ShowInventory();
        mvaddch(y,x,'@');
        if(nItemArray[y][x] != ITEM_EMPTY)
        {
            int nItemType = nItemArray[y][x];
            mvaddstr(MAP_HEIGHT + 3, 2, "You see here a ");
            addstr(sItemIndex[nItemType].pName);
            addstr(".");
        }
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
            case 'b': //testing ASCII codes
                mvaddch(MAP_HEIGHT + 4, 2, ch);
                break;
            //I realized I had to use the ASCII decimal that corresponds to the escape char!
            case 27: //ESCAPE
                return 0;
            case 'c': //c key
                CloseCommand(x,y);
                break;
            case 'g':
                GetCommand(x,y);
                break;
            case 'd':
                DropCommand(x,y);
                break;
            case 'u':
                UseItem();
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
        clear();
    }

    endwin();

    return 0;
}


void GetCommand(int nMapX, int nMapY)
{
    if(nItemArray[nMapY][nMapX] == ITEM_EMPTY)
    {
        mvaddstr(MAP_HEIGHT + 2, 2,"There is nothing here to pick up!");
        getch();
        return;
    }
    //The picking up part
    for(int i = 0; i < INV_SLOTS; i++)
    {
        //Looks for empty slot in inventory.
        if (nInventory[i]==ITEM_EMPTY)
        {
            //Copies item from map array into inventory.
            nInventory[i] = nItemArray[nMapY][nMapX];
            //Removes item from item map array.
            nItemArray[nMapY][nMapX] = ITEM_EMPTY;
            //This nItemType lets me get the name of the item.
            int nItemType = nInventory[i];
            mvaddstr(MAP_HEIGHT + 2, 2, "Picked up ");
            addstr(sItemIndex[nItemType].pName);
            addstr(".");
            return;
        }
    }
    mvaddstr(MAP_HEIGHT + 2, 2, "You can't carry anymore!");
    return;
}

void DropCommand(int nMapX, int nMapY)
{
    mvaddstr(MAP_HEIGHT + 2, 2, "What do you want to drop?");
    int input;
    int slot;
    input = getch();
    slot = input - 'a';//Uses ASCII codes to turn it into numbers for the array.

    //Check that it is valid input.
    if (slot < 0 || slot >= INV_SLOTS)
    {
        mvaddstr(MAP_HEIGHT + 2, 2, "That's not a valid inventory slot. ");
        getch();
    }
    //Check that there is an item in the slot.
    else if(nInventory[slot] == ITEM_EMPTY)
    {
        mvaddstr(MAP_HEIGHT + 2, 2, "You don't have an item in that slot! ");
        getch();
    }
    //Check that there is free space on the ground.
    else if(nItemArray[nMapY][nMapX] != ITEM_EMPTY)
    {
        mvaddstr(MAP_HEIGHT + 2, 2, "No space to drop item here. ");
        getch();
    }
    else
    {
        clear();
        int nItemType = nInventory[slot];
        nItemArray[nMapY][nMapX] = nInventory[slot];
        nInventory[slot] = ITEM_EMPTY;
        mvaddstr(MAP_HEIGHT + 2, 2, "Dropped ");
        addstr(sItemIndex[nItemType].pName);
        addstr(".");
        return;
    }

    clear();
    return;
//Bugs: Words get overwritten, doesn't clear? The dropping aborted doesn't show up.
//Dropped items are not appearing on the map array.
}

//switch case seems useful for inventory selection and use. Should there be array for inventory items?
void UseItem(void)
{
    mvaddstr(MAP_HEIGHT + 2, 2, "What do you want to use?");
    int input;
    int slot;
    input = getch();
    slot = input - 'a';
    if (slot < 0 || slot >= INV_SLOTS)
        {
            mvaddstr(MAP_HEIGHT + 2, 2, "That's not a valid inventory slot. ");
            getch();
        }
        //Check that there is an item in the slot.
    switch(nInventory[slot])
    {
        case ITEM_EMPTY:
            mvaddstr(MAP_HEIGHT + 2, 2, "You don't have an item in that slot! ");
            getch();
            break;
        default:
            int nItemType = nInventory[slot];
            mvaddstr(MAP_HEIGHT + 2, 2, "You fiddle with your ");
            addstr(sItemIndex[nItemType].pName);
            addstr(".");
            getch();
            break;
    }
    clear();
}
void DrawTile(int x, int y)
{


    if(nItemArray[y][x] != ITEM_EMPTY)
    {
        int nType = nItemArray[y][x];
        attron(COLOR_PAIR(sItemIndex[nType].nColorPair));
        mvaddch(y,x,sItemIndex[nType].nCharacter);
        attroff(COLOR_PAIR(sItemIndex[nType].nColorPair));
    }
    else
    {
        int nType = nMapArray[y][x];
        attron(COLOR_PAIR(sTileIndex[nType].nColorPair));
        mvaddch(y,x,sTileIndex[nType].nCharacter);
        attroff(COLOR_PAIR(sTileIndex[nType].nColorPair));
    }
}
