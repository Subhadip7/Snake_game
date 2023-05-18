#ifndef SNAKE_H
#define SNAKE_H
#include<windows.h>

class Snake
{
    private:
        COORD pos;
        int len;
        int vel;
        char direction;


 public:
        Snake(COORD pos, int vel);
        void change_dir(char dir);
        void move_Snake();
        COORD get_pos();
        bool eaten (COORD food_pos);
        void grow();
 };
#endif // SNAKE_H
