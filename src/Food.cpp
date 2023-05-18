#include "Food.h"

Food::Food()
{
   gen_Food();
}
void Food:: gen_Food(){
    pos.X = rand() % WIDTH + 1;
    pos.Y = rand() % HEIGHT + 1;
}
COORD Food :: get_pos(){ return pos ;}
