#include <bits/stdc++.h>
using namespace std;

#define pi 2*acos(0.0)

int main()
{
    freopen("Progress Pie.txt", "w", stdout);
    int t=0, cases;
    scanf("%d", &cases);
    while(t++<cases)
    {
        float p, x, y;
        scanf("%f %f %f", &p, &x, &y);
        x-=50; y-=50;

        printf("Case #%d: ", t);

        float distance;
        distance = sqrt(x*x+y*y);
        if(distance > 50)   printf("white\n");
        else
        {
            float slope;
            slope = y/x;
            float angle;
            angle = atan(slope);

            if(angle >= 0 && angle <= pi/2.0)   angle = pi/2.0 - angle;
            else if(angle < 0)  angle += pi/2.0;
            else angle = pi/2.0 - (angle - pi/2.0) + 3*pi/2.0;

            //cout<<pi/2.0<<' ';

            float pieangle;
            pieangle = 2.0*pi*p/100.0;

            if(pieangle < angle)    printf("white\n");
            else    printf("black\n");

            //cout<<angle<<' '<<pieangle<<endl;
        }
    }

    return 0;
}
