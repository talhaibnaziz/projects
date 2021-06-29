#ifndef QUESTIONTF_H
#define QUESTIONTF_H

#include <question.h>


class questiontf : public question
{
    public:
        questiontf();
        virtual ~questiontf();
        void setanswer(bool b);
        bool getanswer();
    protected:
    private:
        bool answer;
};

#endif // QUESTIONTF_H
