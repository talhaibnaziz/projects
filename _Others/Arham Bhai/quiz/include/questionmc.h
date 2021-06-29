#ifndef QUESTIONMC_H
#define QUESTIONMC_H

#include <question.h>


class questionmc : public question
{
    public:
        questionmc();
        virtual ~questionmc();
        void setchoices(string str[], int cnt);
        void setanswer(char ch);
        int getchoicecnt();
        string getchoice(int idx);
        char getanswer();
    protected:
    private:
        string choices[8];
        int choicecount;
        char answer;
};

#endif // QUESTIONMC_H
