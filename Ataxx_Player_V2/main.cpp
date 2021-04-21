#include "ataxx_search.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout.setf(std::ios_base::unitbuf);
    std::ios_base::sync_with_stdio(false);
    
    ataxx_state state;
    ataxx_search search_ataxx;
    int time_limit = 1; ///Default time limit is 1 seconds
    int height_limit = 6; ///Default height limit is 6
    int search_mode = 2;
    string game_input;
    bool game_on = true;
    int test = 0;
    
    while(game_on)
    {
		cin>>game_input;
		switch(game_input[0])
		{
			case 'i':
			state.set_size();
			break;
			
			case 's':
			state.set_state();
			state.show_state();
			break;
			
			case 'f':
			cin>>time_limit;
			height_limit = INT_MAX;
			break;
			
			case 'd':
			cin>>height_limit;
			time_limit = INT_MAX;
			break;
			
			case 'g':
			if(search_mode == 2) search_ataxx.Iterative_AlphaBeta(state, height_limit, time_limit);
			if(search_mode == 1) search_ataxx.MCTS(state, time_limit);
			state.show_state();
			break;
			
			case 'p':
			test = 0;
			while(state.game_over() == INT_MAX)
			{
				test++;
				search_ataxx.MCTS(state, time_limit);
				state.show_state();
				search_ataxx.Iterative_AlphaBeta(state, height_limit, time_limit);
				state.show_state();
			}
			cout<<"Runs: "<<test<<endl;
			break;
			
			case 'm':
			state.move_piece(game_input);
            state.show_state();
            break;
            
            case 'u':
            state.undo_move();
            state.show_state();
            break;
            
            case 'w':
            state.set_turn(true);
            state.show_state();
            break;
            
            case 'b':
            state.set_turn(false);
            state.show_state();
            break;
            
            case 'q':
            game_on = false;
            break;
            
            case '2':
            cout<<"Search mode set to Alpha-Beta"<<endl;
            search_mode = 2;
            break;
            
            case '1':
            cout<<"Search mode set to MCTS"<<endl;
            search_mode = 1;
            break;
            
            default:
            cout<<"WARNING: wrong input command!"<<endl;
		}
	}

    return 0;
}
/*
Tournament Input
i 8
s
weewwwww
xxxxxxxx
xxxxxxxx
xxxeexxx
xxxeexxx
xxxxxxxx
xxxxxxxx
beebbbbb
2
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
2
ft 1
p

i 8
s
weeeeeee
exxxxxxe
exxxxxxe
exxeexxe
exxeexxe
exxxxxxe
exxxxxxe
eeeeeeeb
ft 1
p

i 8
s
weeeeeee
eeeeeeee
exeeeexe
eeeeeeee
eeeeeeee
exeeeexe
eeeeeeee
eeeeeeeb
ft 1
p

g
mh1h2
ma8c8
*  
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
