#include "player.h"

player::player()
{
    //ctor
    total_points = 0;
}

player::~player()
{
    //dtor
}
void player::setfirstname(string str)
{
    first_name = str;
}
void player::setlastname(string str)
{
    last_name = str;
}
void player::addpoint(int p)
{
    total_points += p;
}
string player::getfirstname()
{
    return first_name;
}
string player::getlastname()
{
    return last_name;
}
int player::getpoint()
{
    return total_points;
}
