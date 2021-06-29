#include<bits/stdc++.h>
using namespace std;

char arr[500][500];
int w,h;
int srch(int x,int y,int cnt) {
    printf("\nayes");
    printf("\n%d %d",x,y);
    if(x<0 || x>=w || y<0 || y>=h) {
        printf("\n%d %d",w,h);
        printf("\nbyes");
        return 0;
    } else if(arr[x][y]=='#') {
        printf("\ncyes");
        return 1;
    } else if(arr[x][y]=='.' || arr[x][y]=='@') {
        arr[x][y]='#';
        printf("\ndyes");
        ++cnt;
        int a,b,c,d;
        printf("\n\ncount==%d",cnt);

        a=srch(x-1,y,cnt);
        b=srch(x+1,y,cnt);
        c=srch(x,y-1,cnt);
        d=srch(x,y+1,cnt);
        if(a==1 && b==1 && c==1 && d==1) {
            return cnt;
        }
    }
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        //int w,h;
        scanf("%d %d",&w,&h);
        getchar();
        //char array[w][h],p;
        int p;
        int i,j;
        for(i=0; i<w; i++) {
            scanf("%c",&p);
            for(j=0; j<h; j++) {
                scanf("%c",&arr[i][j]);
            }
        }
        cout<<"input fin"<<endl;
        for(i=0; i<w; i++) {
            for(j=0; j<h; j++) {
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
        int cnt=0,cnt1;
        for(i=0; i<w; i++) {
            for(j=0; j<h; j++) {
                if(arr[i][j]=='@') {
                    cnt1=srch(i,j,cnt);
                }
            }
        }
        printf("\n\n\n%d\n",cnt);
        for(i=0; i<w; i++) {
            for(j=0; j<h; j++) {
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
    }

}
/*
4
6 9
....#.
.....#
......
......
......
......
......
#@...#
.#..#.
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........
11 6
..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..
7 7
..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
