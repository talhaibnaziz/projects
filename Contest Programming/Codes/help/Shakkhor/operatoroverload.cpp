#include<bits/stdc++.h>
using namespace std;

class Box{
    public:
    int l,b,h;
    Box(){
        l = b = h = 0;
    }
    Box(int x,int y,int z){
        l = x; b = y; h = z;
    }
    Box(const Box &B){
        l = B.l; b = B.b; h = B.h;
    }
    int getLength(){
        return l;
    }
    int getBreadth(){
        return b;
    }
    int getHeight(){
        return h;
    }
    long long CalculateVolume(){
        return (long long)l*(long long)b*(long long)h;
    }

    bool operator < (const Box &B){
        if(this->b==B.b and this->l==B.l)return this->h<B.h;
        if(this->l==B.l)return this->b<B.b;
        return this->l<B.l;
    }

    friend ostream& operator<<(ostream& out, const Box& B){ ///Hocche na
        return out;
    }
};

int main()
{

}
