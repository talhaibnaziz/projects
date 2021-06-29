#ifndef QUESTIONSA_H
#define QUESTIONSA_H

#include <question.h>


class questionsa : public question
{
    public:
        questionsa();
        virtual ~questionsa();
        void setanswer(string str);
        string getanswer();
    protected:
    private:
        string answer;
};

#endif // QUESTIONSA_H
