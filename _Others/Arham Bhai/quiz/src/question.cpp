#include "question.h"

question::question()
{
    //ctor
}

question::~question()
{
    //dtor
}

void question::setpoint(int p)
{
    point = p;
}
void question::setstatement(string str)
{
    statement = str;
}
int question::getpoint()
{
    return point;
}
string question::getstatement()
{
    return statement;
}
