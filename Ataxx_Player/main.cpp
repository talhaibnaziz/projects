#include "ataxx_state.h"

#include <iostream>
#include <stdlib.h>
using namespace std;

//Termination Function needs changing

int main()
{
    std::cout.setf(std::ios_base::unitbuf);
    std::ios_base::sync_with_stdio(false);

    ///Input command variable
    char game_input[6];

    ///Creating an Ataxx state class
    ataxx_state state;

    /**
    Continue taking input until asked for
    termination and handle each scenario
    through specific functions/statements
    P.S: Serial of conditions must not be changed
    */
    while(true)
    {
        cin>>game_input;
        ///For taking input of board size
        if(game_input[0] == 'i')
            state.set_size();
        ///Taking board setup as input
        else if(game_input[0] == 's')
        {
            state.set_state();
            state.set_fixed_height(MAX_DEPTH);
            state.set_time_limit(MAX_TIME);
            state.set_game_time(-1);
            state.set_search_mode(2);
            state.show_state();
        }
        else if(game_input[0] == 'b')
        {
            state.set_turn(false);
            state.show_state();
        }
        else if(game_input[0] == 'w')
        {
            state.set_turn(true);
            state.show_state();
        }
        else if(game_input[0] == 'm')
        {
            state.move_piece(game_input);
            state.show_state();
        }
        else if(game_input[0]=='1' || game_input[0]=='2')
        {
            state.set_search_mode((int)(game_input[0]-'0'));
        }
        else if(game_input[0]=='r' && game_input[1]=='t')
        {
            double time;
            cin>>time;
            state.set_fixed_height(MAX_DEPTH);
            state.set_game_time(time);
        }
        else if(game_input[0]=='f' && game_input[1]=='t')
        {
            double time;
            cin>>time;
            state.set_fixed_height(MAX_DEPTH);
            state.set_time_limit(time);
        }
        else if(game_input[0]=='d')
        {
            int depth;
            cin>>depth;
            state.set_fixed_height(depth);
            state.set_time_limit(MAX_TIME);
        }
        else if(game_input[0] == 'g')
        {
            state.Iterative_AlphaBeta();
            state.show_state();
        }
        else if(game_input[0] == 'u')
        {
            state.undo_move();
            state.show_state();
        }
        else if(game_input[0] == 'q') break;
        else    cout<<"WARNING: Wrong input given!"<<endl;
    }

    return 0;
}
/*
Testing Errors
i 8
s
wwwwbbbb
bbbbwwww
wwwwbbbb
bbbbwwww
wwwebbbb
bbbbwwww
wwwwbbbb
bbbbwwww
ft 1

i 5
s
wwwww
eeeee
wwwww
wwwww
bbbbb
b
2
d 3

i 8
s
wwwwwwee
wxxxxxxw
exeeeexw
exeeeexb
exeeeexb
exeeeexb
exxxxxxb
eeeebbbb
b

i 8
s
wwwwwwww
eeeeeeee
wwwwwwww
wwwwwwww
bbbbbbbb
bbbbbbbb
bbbbbbbb
wwwwwwww
ft 1

i 8
s
weeeeeee
exxxxxxe
exeeeexe
exeeeexe
exeeeexe
exeeeexe
exxxxxxe
eeeeeeeb

i 8
s
weeeeeeb
eeeeeeee
eexeexee
eeeeeeee
eeeeeeee
eexeexee
eeeeeeee
beeeeeew
b
2
ft 1
g
*/

/*
Pass move Tests
i 4
s
weex
xxxx
xxxx
xxxx

i 4
s
weex
xxxx
xxxx
xxeb
g

i 5
s
weeee
exxxx
exxxx
exxee
exxeb
g

i 5
s
weeee
exxxx
exxxx
exxee
exxeb
g

i 5
s
weeee
eeeee
eeeee
eeeee
eeeeb
g
*/

/*
MiniMax DFS Test Inputs
i 4
s
xxxx
weee
eeeb
xxxx
g

i 4
s
weee
eeee
eeee
eeeb
g

i 7
s
beeeeew
eeeeeee
eeeeeee
eeeeeee
eeeeeee
eeeeeee
weeeeeb
*/

/*
Small Test Input
i 4
s
xxxx
weee
eeeb
xxxx
ma3a2
ma3a2
ma2b2
ma2b2
ma3b3
ma3b3
*/

/*
Sample Input
i 5
s
eeeee
eeeee
exwbe
exeee
eeeex
mc3b4
mb3b4
mb4c4
mb4b5
*/

