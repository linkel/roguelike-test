#ifndef ACTOR_H
#define ACTOR_H


class Actor
{
    public:
        Actor(void);
        ~Actor(void);
        //virtual ~Actor();
        void SetAppearance(char nDisplayChar, short nColorPair);
        void SetPos(int x, int y);
        void Draw(void);
    protected:
        int nPosX;
        int nPosY;
        char nDisplayChar;
        short nColorPair;
    private:
};

#endif // ACTOR_H
