#include "ataxx_state.h"
//#define DEBUG cout<<"Debugging is on."<<endl;
using namespace std;

mt19937 mt(01234567);

ataxx_state::ataxx_state()
{
	///Initially sets the board as false (not set yet)
	setup = false;
	///Initialize the move_stack to a fixed size
	for(int i=0; i<max_move_stack; i++)
		move_stack.push_back(0);
		
	///Initialize Zobrist Table for white and black pieces
	for(int i=0; i<max_grid; i++)
	{
		for(int j=0; j<max_grid; j++)
		{
			zobristTableW[i].push_back(randomInt());
			zobristTableB[i].push_back(randomInt());
		}
	}
}

void ataxx_state::set_size()
{
    cin>>board_size;
    if(board_size < min_grid || board_size > max_grid)
    {
        cout<<"WARNING: Invalid board size!"<<endl;
        cout<<"Must be greater than 3 and less than 9!"<<endl;
        board_size = -1;
    }
}

void ataxx_state::set_state()
{
	///If no board size has been given yet
	if(board_size == -1)
	{
		cout<<"WARNING: No board size given!"<<endl;
		return;
	}
	///Initialize board variables
	white = true; white_cnt = 0;
	black_cnt = 0; empty_cnt = 0;
	jump_moves = 0; stack_idx = 0;
	
	hashValue = 0ULL; Wstate = 0ULL; Bstate = 0ULL;
	
	for(int i=0; i<board_size; i++)
	{
		cin>>board[i];
		for(int j=0; j<board_size; j++)
		{
			/**
            Initialize board piece counters
            */
            if(board[i][j]=='e')    empty_cnt++;
            else if(board[i][j]=='w')
            {
                white_cnt++;
                hashValue ^= zobristTableW[i][j];
                Wstate |= (1ULL<<(i*board_size + j));
            }
            else if(board[i][j]=='b')
            {
                black_cnt++;
                hashValue ^= zobristTableB[i][j];
                Bstate |= (1ULL<<(i*board_size + j));
            }
            else if(board[i][j] != 'x')
            {
                cout<<"WARNING: Invalid board piece!\nSet board again!"<<endl;
                return;
            }
        }
    }
    setup = true;
}

void ataxx_state::show_state()
{
	if(setup == false)
	{
		cout<<"WARNING: The board has not been setup yet!"<<endl;
		return;
	}
	///Print board meta data
	//~ cout<<"White Meta: "<<Wstate<<endl;
	//~ cout<<"Black Meta: "<<Bstate<<endl;
	cout<<"White: "<<white_cnt<<endl;
	cout<<"Black: "<<black_cnt<<endl;
	cout<<"Empty: "<<empty_cnt<<endl<<" ";
	for(int i=0; i<board_size; i++)	cout<<" "<<(char)('a'+i);
	cout<<endl;
	
	for(int i=0; i<board_size; i++)
	{
		cout<< board_size-i;
		for(int j=0; j<board_size; j++)
		{
			if(board[i][j]=='e') cout<<" _";
			else cout<<" "<<board[i][j];
		}
		cout<<endl;
	}
	if(white) cout<<"White is to move:"<<endl;
	else cout<<"Black is to move:"<<endl;
}

int ataxx_state::evaluate_state()
{
	if(white)	return (white_cnt-black_cnt);
	return	(black_cnt-white_cnt);
}

void ataxx_state::set_turn(bool turn)
{
    white = turn;
}

void ataxx_state::move_piece(const string &input)
{
	/**
	 * Converting move string to required
	 * board position values
	 */
	bool pass = false;
	int rowto, rowfrom, colto, colfrom;
	int local_rowto, local_colto;
	rowfrom = (board_size-1)-(input[2]-'1');
	rowto = (board_size-1)-(input[4]-'1');
	colfrom = input[1]-'a';
	colto = input[3]-'a';
	
	///If the move is a pass move
	if(rowfrom==rowto && colfrom==colto)
	{
		pass = true;
		///Check validity of pass move
		for(int i=0; i<board_size; i++)
		{
			for(int j=0; j<board_size; j++)
			{
				if(board[i][j]=='x' || board[i][j]=='e')	continue;
				for(int ii=0; ii<max_moves; ii++)
				{
					local_rowto = i+row_d2[ii];
					local_colto = j+col_d2[ii];
					if(local_rowto<0 || local_rowto>=board_size || local_colto<0 || local_colto>=board_size)
                        continue;
                    if(white)
                    {
                        if(board[i][j]=='w' && board[local_rowto][local_colto]=='e')
                            pass = false;
                    }
                    else
                    {
                        if(board[i][j]=='b' && board[local_rowto][local_colto]=='e')
                            pass = false;
                    }
				}
			}
		}
		if(!pass)
		{
			cout<<"WARNING: Invalid pass move!"<<endl;
			return;
		}
	}
	else if((board[rowfrom][colfrom]=='w' && !white) || (board[rowfrom][colfrom]=='b' && white))
    {
        cout<<"WARNING: You have chosen opposite piece!"<<endl;
        return;
    }
    else if(board[rowto][colto]!='e')
    {
        cout<<"WARNING: You can only move to an empty cell!"<<endl;
        return;
    }
    else if(abs(rowfrom-rowto)>2 || abs(colfrom-colto)>2)
    {
        cout<<"WARNING: Impossible move played!"<<endl;
        return;
    }

    ///Calling the function to perform the move
    do_move(rowfrom, colfrom, rowto, colto);
    int current_score = game_over();
    if(current_score != INT_MAX)
    {
        cout<<"GAME OVER: ";
        cout<<"White: "<<white_cnt;
        cout<<" - Black: "<<black_cnt;
        if(white) cout<<" = "<<current_score<<endl;
        else cout<<" = "<<-current_score<<endl;
        board_size = -1;
        setup = false;
    }
}

void ataxx_state::do_move(int rowfrom, int colfrom, int rowto, int colto)
{
    bool pass = false;
    
    ///Debugging for moves in search
    #ifdef DEBUG
    if(rowfrom==rowto && colfrom==colto)	cout<<"DEBUG: Pass move played"<<endl;
    else if((board[rowfrom][colfrom]=='w' && !white) || (board[rowfrom][colfrom]=='b' && white))
        cout<<"DEBUG: You have chosen opposite piece!"<<endl;
    else if(board[rowto][colto]!='e')
        cout<<"DEBUG: You can only move to an empty cell!"<<endl;
    else if(abs(rowfrom-rowto)>2 || abs(colfrom-colto)>2)
        cout<<"DEBUG: Impossible move played!"<<endl;
	#endif
    
    ///Jump moves for any piece
    if(abs(rowfrom-rowto)==2 || abs(colfrom-colto)==2)
    {
		board[rowto][colto] = board[rowfrom][colfrom];
        board[rowfrom][colfrom] = 'e';
        jump_moves++;
        if(white)
        {
			hashValue ^= zobristTableW[rowfrom][colfrom];
			hashValue ^= zobristTableW[rowto][colto];
			Wstate |= (1ULL << (rowto*board_size + colto));
			Wstate -= (1ULL << (rowfrom*board_size + colfrom));
		}
		else
		{
			hashValue ^= zobristTableB[rowfrom][colfrom];
			hashValue ^= zobristTableB[rowto][colto];
			Bstate |= (1ULL << (rowto*board_size + colto));
			Bstate -= (1ULL << (rowfrom*board_size + colfrom));
		}
    }
    ///Pass move
    else if(rowfrom==rowto && colfrom==colto)
    {
        pass = true;
        jump_moves = 0;
    }
    ///Cloning moves
    else if(abs(rowfrom-rowto)<2 && abs(colfrom-colto)<2)
    {
        empty_cnt--; jump_moves = 0;
		board[rowto][colto] = board[rowfrom][colfrom];
        if(white)
        {
            white_cnt++;
			hashValue ^= zobristTableW[rowto][colto];
			Wstate |= (1ULL << (rowto*board_size + colto));
        }
        else
        {
            black_cnt++;
            hashValue ^= zobristTableB[rowto][colto];
            Bstate |= (1ULL << (rowto*board_size + colto));
        }
    }

    ///Capturing of enemy pieces
    int adj_row, adj_col, capture = 0;;
    for(int i=0; i<8 && !pass; i++)
    {
        adj_row = rowto + row_d1[i];
        adj_col = colto + col_d1[i];
        if(adj_row<0 || adj_row>=board_size || adj_col<0 || adj_col>=board_size) continue;
        if(white && board[adj_row][adj_col] != 'b')  continue;
        if(!white && board[adj_row][adj_col] != 'w')  continue;

        board[adj_row][adj_col] = board[rowto][colto];
        hashValue ^= zobristTableW[adj_row][adj_col];
        hashValue ^= zobristTableB[adj_row][adj_col];

        if(white)
        {
            white_cnt++;
            black_cnt--;
            Wstate |= (1ULL << (adj_row*board_size + adj_col));
            Bstate -= (1ULL << (adj_row*board_size + adj_col));
        }
        else
        {
            white_cnt--;
            black_cnt++;
            Wstate -= (1ULL << (adj_row*board_size + adj_col));
            Bstate |= (1ULL << (adj_row*board_size + adj_col));
        }
        capture |= (1<<i);
    }
    ///Storing move information in stack
    compress_move(move_stack[stack_idx], rowto, colto, rowfrom, colfrom, capture);
    stack_idx++;

    ///Implicit change of turns
    white = !white;
}

void ataxx_state::undo_move()
{
	if(!stack_idx)
	{
		cout<<"No more moves to undo!"<<endl;
		return;
	}
	
	///Implicit undo of turns
	white = !white;
	stack_idx--;
	
	///Getting move info from move history/stack
	bool pass = false;
	int rowto, colto, rowfrom, colfrom, capture;
	decompress_move(move_stack[stack_idx], rowto, colto, rowfrom, colfrom, capture);
	
	///Undo jump moves
	if(abs(rowfrom-rowto)==2 || abs(colfrom-colto)==2)
	{
		if(jump_moves)	jump_moves--;
		board[rowfrom][colfrom] = board[rowto][colto];
		board[rowto][colto] = 'e';
		if(white)
        {
            hashValue ^= zobristTableW[rowfrom][colfrom];
            hashValue ^= zobristTableW[rowto][colto];
            Wstate |= (1ULL << (rowfrom*board_size + colfrom));
            Wstate -= (1ULL << (rowto*board_size + colto));
        }
        else
        {
            hashValue ^= zobristTableB[rowfrom][colfrom];
            hashValue ^= zobristTableB[rowto][colto];
            Bstate |= (1ULL << (rowfrom*board_size + colfrom));
            Bstate -= (1ULL << (rowto*board_size + colto));
        }
	}
	///Handling pass moves
	else if(rowfrom==rowto && colfrom==colto)	pass = true;
	///Undo clone moves
	else
	{
		board[rowto][colto] = 'e';
		empty_cnt++;
		if(white)
		{
			white_cnt--;
			hashValue ^= zobristTableW[rowto][colto];
            Wstate -= (1ULL << (rowto*board_size + colto));
		}
		else
		{
			black_cnt--;
			hashValue ^= zobristTableB[rowto][colto];
            Bstate -= (1ULL << (rowto*board_size + colto));
		}
	}
	
	int adj_row, adj_col;
	for(int i=0; i<8 && !pass; i++)
	{
		///if adjacent piece was captured
		if(capture & (1<<i))
		{
			adj_row = rowto + row_d1[i];
			adj_col = colto + col_d1[i];
            hashValue ^= zobristTableW[adj_row][adj_col];
            hashValue ^= zobristTableB[adj_row][adj_col];
            
			if(white)
			{
				board[adj_row][adj_col] = 'b';
				white_cnt--;	black_cnt++;
                Wstate -= (1ULL << (adj_row*board_size + adj_col));
                Bstate |= (1ULL << (adj_row*board_size + adj_col));
			}
			else
			{
				board[adj_row][adj_col] = 'w';
				white_cnt++;	black_cnt--;
                Wstate |= (1ULL << (adj_row*board_size + adj_col));
                Bstate -= (1ULL << (adj_row*board_size + adj_col));
			}
		}
	}
}

int ataxx_state::game_over()
{
    ///GAME OVER: Return difference of pieces
    if(jump_moves >= 50 || !check_moves(true, true))
    {
		if(white) return (white_cnt-black_cnt);
		else return (black_cnt-white_cnt);
	}
    else    return INT_MAX;
}

void ataxx_state::compress_move(int &c_state, int &rowto, int &colto, int &rowfrom, int &colfrom, int &capture)
{
	///clean previous state compression
	c_state = 0;
	///store new move history entry
	c_state |= colto;
	c_state |= (rowto << 4);
	c_state |= (colfrom << 8);
	c_state |= (rowfrom << 12);
	c_state |= (capture << 16);
}

void ataxx_state::decompress_move(int &c_state, int &rowto, int &colto, int &rowfrom, int &colfrom, int &capture)
{
	colto = (c_state % 16);
	rowto = (int)((c_state>>4) % 16);
	colfrom = (int)((c_state>>8) % 16);
	rowfrom = (int)((c_state>>12) % 16);
	capture = (int)((c_state>>16) % 256);
}

int ataxx_state::check_moves(bool forWhite, bool forBlack)
{
	int pass = 0;
	int rowto, colto;
	for(int i=0; i<board_size; i++)
	{
		for(int j=0; j<board_size; j++)
		{
			if(board[i][j]=='x' || board[i][j]=='e') continue;
			for(int ii=0; ii<max_moves; ii++)
			{
				rowto = i+row_d2[ii];
				colto = j+col_d2[ii];
				if(rowto<0 || rowto>=board_size || colto<0 || colto>=board_size) continue;
				if((forWhite && board[i][j]=='w') && board[rowto][colto]=='e')
					pass++;
				if((forBlack && board[i][j]=='b') && board[rowto][colto]=='e')
					pass++;
			}
		}
	}
	return pass;
}

unsigned long long ataxx_state::randomInt()
{
	uniform_int_distribution<unsigned long long> dist(0, UINT64_MAX);
	return dist(mt);
}

bool ataxx_state::get_white()
{
	return white;
}

unsigned long long ataxx_state::get_hash()
{
	return hashValue;
}

void ataxx_state::TTstore(unsigned long long idx, vector <unsigned char> &TTwhite, vector <unsigned long long> &TTWstate, vector <unsigned long long> &TTBstate)
{
	if(white) TTwhite[idx/8ULL] |= (unsigned char)(1<<(idx%8ULL));
	else TTwhite[idx/8ULL] &= (unsigned char)((255ULL)-(1<<(idx%8ULL)));
	TTWstate[idx] = Wstate;
	TTBstate[idx] = Bstate;
}

bool ataxx_state::TTcompare(unsigned long long idx, vector <unsigned char> &TTwhite, vector <unsigned long long> &TTWstate, vector <unsigned long long> &TTBstate)
{
	/**
	 * There are four possibilities - turn is white (white = true)
	 * and TT turn is white, turn is white and TT turn is black,
	 * turn is black (white = false) and TT turn is black, and
	 * turn is black and TT turn is white.
	 */
	///If turn is black and TT turn is white, then return false
	if(!white && (TTwhite[idx/8ULL] & (unsigned char)(1<<(idx%8ULL)))) return false;
	///If turn is white and TT turn is black, then return false
	else if(white && !(TTwhite[idx/8ULL] & (unsigned char)(1<<(idx%8ULL)))) return false;
	
	if(TTWstate[idx] != Wstate)	return false;
	if(TTBstate[idx] != Bstate)	return false;
	return true;
}

ataxx_state::~ataxx_state()
{
    //dtor
}
