#ifndef ACTOR_H
#define ACTOR_H


class Actor
{
    public:
        //Constructor
        Actor(void);
        //Deconstructor
        ~Actor(void);
        //virtual ~Actor(); //Another way to make deconstructor, gotta look this up

        //My various functions, which are all in the cpp
        void SetAppearance(char nDisplayChar, short nColorPair);
        void SetPos(int x, int y);
        void Draw(void);

    protected:
        //Position
        int nPosX;
        int nPosY;

        //What it displays as
        char nDisplayChar;

        //What color it is
        short nColorPair;
    private:
};

#endif // ACTOR_H
