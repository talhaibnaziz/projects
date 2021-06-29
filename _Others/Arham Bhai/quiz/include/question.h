#ifndef QUESTION_H
#define QUESTION_H
#include <string>
using namespace std;

class question
{
    public:
        question();
        virtual ~question();
        void setpoint(int p);
        void setstatement(string str);
        int getpoint();
        string getstatement();
    protected:
    private:
        int point;
        string statement;
};

#endif // QUESTION_H
