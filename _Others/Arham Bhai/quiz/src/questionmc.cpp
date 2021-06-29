#include "questionmc.h"

questionmc::questionmc()
{
    //ctor
}

questionmc::~questionmc()
{
    //dtor
}
void questionmc::setanswer(char ch)
{
    answer = ch;
}
void questionmc::setchoices(string str[], int cnt)
{
    for(int i=0; i<cnt; i++)
    {
        choices[i]=str[i];
    }
    choicecount = cnt;
}
int questionmc::getchoicecnt()
{
    return choicecount;
}
string questionmc::getchoice(int idx)
{
    return choices[idx];
}
char questionmc::getanswer()
{
    return answer;
}
