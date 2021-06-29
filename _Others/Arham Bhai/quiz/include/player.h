#ifndef PLAYER_H
#define PLAYER_H
#include <string>

using namespace std;


class player
{
    public:
        player();
        virtual ~player();
        void setfirstname(string str);
        void setlastname(string str);
        void addpoint(int p);
        string getfirstname();
        string getlastname();
        int getpoint();
    protected:
    private:
        string first_name;
        string last_name;
        int total_points;
};

#endif // PLAYER_H
