#include "ataxx_state.h"

mt19937 mt(01234567);

///Transposition Table Parameters
unsigned long long max_size;
unsigned long long zobristTable[8][8][2];
unsigned long long hashValue;
unsigned long long TTWstate[MAX_TT_SIZE];
unsigned long long TTBstate[MAX_TT_SIZE];
int TTscore[MAX_TT_SIZE], TTheight[MAX_TT_SIZE];
char TTMove[MAX_TT_SIZE][2];
char TTfvalue[MAX_TT_SIZE];
bool TTwhite[MAX_TT_SIZE];
int gc; int TTgc[MAX_TT_SIZE];
long long TTQ, TTF, TTC;

ataxx_state::ataxx_state()
{
    //ctor
    n_board = -1;
    setup = false;

    ///Initialize Zobrist Table
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            zobristTable[i][j][0] = randomInt();
            zobristTable[i][j][1] = randomInt();
        }
    }
}

void ataxx_state::set_size()
{
    cin>>n_board;
    if(n_board < 4 || n_board > 8)
    {
        cout<<"WARNING: Invalid board size! Must be greater than 3 and less than 9!"<<endl;
        n_board = -1;
    }
}

void ataxx_state::set_state()
{
    ///If no board size has been given yet
    if(n_board == -1)
    {
        cout<<"WARNING: No board size given!"<<endl;
        return;
    }
    ///Initialize board variables
    white = true;
    white_cnt = 0;
    black_cnt = 0;
    empty_cnt = 0;

    stack_idx = 0;
    jump_moves = 0;

    ///Initialize Transposition Table variables
    hashValue = 0ULL;
    Wstate = 0ULL;
    Bstate = 0ULL;
    gc = 1;
    for(int i=0; i<MAX_TT_SIZE; i++)
    {
        TTWstate[i] = 0ULL;
        TTBstate[i] = 0ULL;
        TTwhite[i] = true;
    }
    for(int i=0; i<n_board; i++)
    {
        cin>>board[i];
        for(int j=0; j<n_board; j++)
        {
            /**
            Initialize board piece counters and
            Hash Values using Zobrist Table
            */
            if(board[i][j]=='e')    empty_cnt++;
            else if(board[i][j]=='w')
            {
                white_cnt++;
                hashValue ^= zobristTable[i][j][0];
                Wstate |= (1ULL<<(i*n_board + j));
            }
            else if(board[i][j]=='b')
            {
                black_cnt++;
                hashValue ^= zobristTable[i][j][1];
                Bstate |= (1ULL<<(i*n_board + j));
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
    cout<<"White: "<<white_cnt<<endl;
    cout<<"Black: "<<black_cnt<<endl;
    cout<<"Empty: "<<empty_cnt<<endl;
    cout<<" ";
    for(int i=0; i<n_board; i++)
        cout<<" "<<(char)('a'+i);
    cout<<endl;

    for(int i=0; i<n_board; i++)
    {
        cout<<n_board-i;
        for(int j=0; j<n_board; j++)
        {
            if(board[i][j]=='e')
                cout<<" _";
            else
                cout<<" "<<board[i][j];
        }
        cout<<endl;
    }
    if(white)   cout<<"White is to move:"<<endl;
    else        cout<<"Black is to move:"<<endl;
}

void ataxx_state::set_turn(bool turn)
{
    white = turn;
}

void ataxx_state::move_piece(char *input)
{
    /**
    Converting move string to required
    board position values
    */
    bool pass = false; gc++;
    int rowto, rowfrom, colto, colfrom;
    rowfrom = (n_board-1)-(input[2]-'1');
    rowto = (n_board-1)-(input[4]-'1');
    colfrom = input[1]-'a';
    colto = input[3]-'a';

    ///Performing the required move
    if(rowfrom==rowto && colfrom==colto)
    {
        pass = true;
        ///Check if pass is a valid move now
        for(int i=0; i<n_board; i++)
        {
            for(int j=0; j<n_board; j++)
            {
                if(board[i][j] == 'x' || board[i][j] == 'e')    continue;
                for(int ii=0; ii<24; ii++)
                {
                    int local_rowto = i+row_d2[ii];
                    int local_colto = j+col_d2[ii];
                    if(local_rowto<0 || local_rowto>=n_board || local_colto<0 || local_colto>=n_board)
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
    current_score = game_over();
    if(current_score != MAX_SCORE)
    {
        cout<<"GAME OVER: ";
        cout<<"White: "<<white_cnt;
        cout<<" - Black: "<<black_cnt;
        cout<<" = "<<current_score<<endl;
    }
}

void ataxx_state::do_move(int rowfrom, int colfrom, int rowto, int colto)
{
    bool pass = false;
    ///Valid moves Processing
    board[rowto][colto] = board[rowfrom][colfrom];
    ///Jump moves for any piece
    if(abs(rowfrom-rowto)==2 || abs(colfrom-colto)==2)
    {
        board[rowfrom][colfrom] = 'e';
        jump_moves++;
        ///Current state processing for Transposition Table
        if(white)
        {
            hashValue ^= zobristTable[rowfrom][colfrom][0];
            hashValue ^= zobristTable[rowto][colto][0];
            Wstate |= (1ULL<<(rowto*n_board + colto));
            Wstate -= (1ULL<<(rowfrom*n_board + colfrom));
        }
        else
        {
            hashValue ^= zobristTable[rowfrom][colfrom][1];
            hashValue ^= zobristTable[rowto][colto][1];
            Bstate |= (1ULL<<(rowto*n_board + colto));
            Bstate -= (1ULL<<(rowfrom*n_board + colfrom));
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
        if(white)
        {
            white_cnt++;
            hashValue ^= zobristTable[rowto][colto][0];
            Wstate |= (1ULL<<(rowto*n_board + colto));
        }
        else
        {
            black_cnt++;
            hashValue ^= zobristTable[rowto][colto][1];
            Bstate |= (1ULL<<(rowto*n_board + colto));
        }
    }

    ///Storing move history in stack
    move_stack[stack_idx][0] = (char)(rowfrom | (rowto << 4));
    move_stack[stack_idx][1] = (char)(colfrom | (colto << 4));
    move_stack[stack_idx][2] = 0;

    ///Capturing of enemy pieces
    for(int i=0; i<8 && !pass; i++)
    {
        int adj_row = rowto + row_d1[i];
        int adj_col = colto + col_d1[i];
        if(adj_row<0 || adj_row>=n_board || adj_col<0 || adj_col>=n_board)
            continue;
        if(white && board[adj_row][adj_col] != 'b')  continue;
        if(!white && board[adj_row][adj_col] != 'w')  continue;

        board[adj_row][adj_col] = board[rowto][colto];
        hashValue ^= zobristTable[adj_row][adj_col][0];
        hashValue ^= zobristTable[adj_row][adj_col][1];

        if(white)
        {
            white_cnt++;
            black_cnt--;
            Wstate |= (1ULL<<(adj_row*n_board + adj_col));
            Bstate -= (1ULL<<(adj_row*n_board + adj_col));
        }
        else
        {
            white_cnt--;
            black_cnt++;
            Wstate -= (1ULL<<(adj_row*n_board + adj_col));
            Bstate |= (1ULL<<(adj_row*n_board + adj_col));
        }

        ///Storing capture history in stack
        move_stack[stack_idx][2] = (1<<i) | move_stack[stack_idx][2];
    }

    ///Implicit change of turns
    white = !white;
    ///Preparation for storing next move history
    stack_idx++;
}

int ataxx_state::game_over()
{
    ///GAME OVER: Return difference of pieces
    bool pass = true;
    for(int i=0; i<n_board; i++)
    {
        for(int j=0; j<n_board; j++)
        {
            if(board[i][j] == 'x' || board[i][j] == 'e')    continue;
            for(int ii=0; ii<24; ii++)
            {
                int rowto = i+row_d2[ii];
                int colto = j+col_d2[ii];
                if(rowto<0 || rowto>=n_board || colto<0 || colto>=n_board)
                    continue;
                if(board[i][j]=='w' && board[rowto][colto]=='e')
                    pass = false;
                else if(board[i][j]=='b' && board[rowto][colto]=='e')
                    pass = false;
            }
        }
    }

    if(jump_moves >= 50 || pass)
    {
        n_board = -1;
        setup = false;
        return (white_cnt-black_cnt);
    }
    else    return MAX_SCORE;
}

void ataxx_state::undo_move()
{
    if(!stack_idx)
    {
        cout<<"No more moves to undo!"<<endl;
        return;
    }

    ///Implicit undo of turns as well
    white = !white;
    stack_idx--;

    ///Implementing undo from move history
    bool pass = false;
    int rowto, rowfrom, colto, colfrom;
    rowfrom = (int)(move_stack[stack_idx][0] & 15);
    rowto = (int)((move_stack[stack_idx][0]>>4) & 15);
    colfrom = (int)(move_stack[stack_idx][1] & 15);
    colto = (int)((move_stack[stack_idx][1]>>4) & 15);

    board[rowfrom][colfrom] = board[rowto][colto];
    ///Undoing jump moves
    if(abs(rowfrom-rowto)==2 || abs(colfrom-colto)==2)
    {
        if(jump_moves)  jump_moves--;
        board[rowto][colto] = 'e';
        if(white)
        {
            hashValue ^= zobristTable[rowfrom][colfrom][0];
            hashValue ^= zobristTable[rowto][colto][0];
            Wstate |= (1ULL<<(rowfrom*n_board + colfrom));
            Wstate -= (1ULL<<(rowto*n_board + colto));
        }
        else
        {
            hashValue ^= zobristTable[rowfrom][colfrom][1];
            hashValue ^= zobristTable[rowto][colto][1];
            Bstate |= (1ULL<<(rowfrom*n_board + colfrom));
            Bstate -= (1ULL<<(rowto*n_board + colto));
        }
    }
    else if(rowfrom==rowto && colfrom==colto)
    {
        pass = true;
    }
    ///Undoing clone moves
    else
    {
        board[rowto][colto] = 'e';
        empty_cnt++;
        if(white)
        {
            white_cnt--;
            hashValue ^= zobristTable[rowto][colto][0];
            Wstate -= (1ULL<<(rowto*n_board + colto));
        }
        else
        {
            black_cnt--;
            hashValue ^= zobristTable[rowto][colto][1];
            Bstate -= (1ULL<<(rowto*n_board + colto));
        }
    }

    for(int i=0; i<8 && !pass; i++)
    {
        ///If the adjacent piece was captured
        if(move_stack[stack_idx][2] & (1<<i))
        {
            int adj_row = rowto + row_d1[i];
            int adj_col = colto + col_d1[i];
            hashValue ^= zobristTable[adj_row][adj_col][0];
            hashValue ^= zobristTable[adj_row][adj_col][1];
            if(white)
            {
                board[adj_row][adj_col] = 'b';
                white_cnt--;
                black_cnt++;
                Wstate -= (1ULL<<(adj_row*n_board + adj_col));
                Bstate |= (1ULL<<(adj_row*n_board + adj_col));
            }
            else
            {
                board[adj_row][adj_col] = 'w';
                white_cnt++;
                black_cnt--;
                Wstate |= (1ULL<<(adj_row*n_board + adj_col));
                Bstate -= (1ULL<<(adj_row*n_board + adj_col));
            }
        }
    }
}

int ataxx_state::AlphaBeta(int height, int alpha, int beta)
{
    nodes_evaluated++;
    ///Time Measurements for setting time limits
    endt = chrono::steady_clock::now();
    chrono::duration<double> elapsed_seconds = endt-start;
    if(!timeout && elapsed_seconds.count() > time_limit)
    {
        timeout = true;
        cout<<"TIMEOUT"<<endl;
    }

    ///Base case for fixed depth or terminal state
    if(timeout || !height || jump_moves >= 50)
    {
        if(white)   return (white_cnt-black_cnt);
        else    return (black_cnt-white_cnt);
    }

    ///Use Transposition Table
    unsigned long long int idx = checkTT(height, alpha, beta);
    if(idx!=-1ULL && alpha >= beta)
    {
        TTC++;
        return TTscore[idx];
    }

    ///Start of normal cases
    int rowto, colto; valid_moves = 0;
    int score = -MAX_SCORE; int al = alpha;
    bool pass = true;
    int local_colto=0, local_colfrom=0, local_rowto=0, local_rowfrom=0;
    ///Move with best heuristics according to TT
    if(idx != -1ULL)
    {
        int i = (int)(TTMove[idx][0] & 15);
        rowto = (int)((TTMove[idx][0]>>4) & 15);
        int j = (int)(TTMove[idx][1] & 15);
        colto = (int)((TTMove[idx][1]>>4) & 15);
        if(board[rowto][colto]=='e')
        {
            pass = false; valid_moves++;
            do_move(i, j, rowto, colto);
            int x = -AlphaBeta(height-1, -beta, -al);
            if(score < x)
            {
                score = x;
                local_rowto = rowto;
                local_colto = colto;
                local_rowfrom = i;
                local_colfrom = j;
                if(height == max_height)
                {
                    bestrowto = rowto;
                    bestcolto = colto;
                    bestrowfrom = i;
                    bestcolfrom = j;
                }
                if(score > al)   al = score;
                /**
                Better move is taken but too much
                means the subtree is useless
                */
                if(score >= beta)
                {
                    undo_move();
                    CBF += (double)valid_moves;
                    betacuts++;
                    saveTT(score, local_rowto, local_rowfrom, local_colto, local_colfrom, height, alpha, beta);

                    return score;
                }
            }
            undo_move();
        }
    }
    for(int i=0; i<n_board; i++)
    {
        for(int j=0; j<n_board; j++)
        {
            ///Move for WHITE or BLACK piece
            if((white && board[i][j]=='w') || (!white && board[i][j]=='b'))
            {
                ///All possible move generation
                for(int ii=0; ii<24; ii++)
                {
                    if(timeout) return score;
                    rowto = i+row_d2[ii];
                    colto = j+col_d2[ii];
                    if(rowto<0 || rowto>=n_board || colto<0 || colto>=n_board)
                        continue;
                    if(idx != -1ULL && (i==(int)(TTMove[idx][0] & 15) && j==(int)(TTMove[idx][1] & 15) && rowto==(int)((TTMove[idx][0]>>4) & 15) && colto==(int)((TTMove[idx][1]>>4) & 15)))
                        continue;
                    if(board[rowto][colto]=='e')
                    {
                        pass = false; valid_moves++;
                        do_move(i, j, rowto, colto);
                        int x = -AlphaBeta(height-1, -beta, -al);
                        if(score < x)
                        {
                            score = x;
                            local_rowto = rowto;
                            local_colto = colto;
                            local_rowfrom = i;
                            local_colfrom = j;
                            if(height == max_height)
                            {
                                bestrowto = rowto;
                                bestcolto = colto;
                                bestrowfrom = i;
                                bestcolfrom = j;
                            }
                            if(score > al)   al = score;
                            /**
                            Better move is taken but too much
                            means the subtree is useless
                            */
                            if(score >= beta)
                            {
                                undo_move();
                                CBF += (double)valid_moves;
                                betacuts++;
                                saveTT(score, local_rowto, local_rowfrom, local_colto, local_colfrom, height, alpha, beta);

                                return score;
                            }
                        }
                        undo_move();
                    }
                }
            }
        }
    }
    ///If there are no moves available
    if(pass)
    {
        do_move(0, 0, 0, 0);
        valid_moves++;
        int x = -AlphaBeta(height-1, -beta, -al);
        if(score < x)
        {
            score = x;
            local_rowto = 0;
            local_colto = 0;
            local_rowfrom = 0;
            local_colfrom = 0;
            if(height == max_height)
            {
                bestrowto = 0;
                bestcolto = 0;
                bestrowfrom = 0;
                bestcolfrom = 0;
            }
            if(score > al)   al = score;
            /**
            Better move is taken but too much
            means the subtree is useless
            */
            if(score >= beta)
            {
                undo_move();
                betacuts++;
                CBF += (double)valid_moves;
                saveTT(score, 0, 0, 0, 0, height, alpha, beta);

                return score;
            }
        }
        undo_move();
    }
    saveTT(score, local_rowto,local_rowfrom, local_colto, local_colfrom, height, alpha, beta);

    return score;
}

void ataxx_state::Iterative_AlphaBeta()
{
    chrono::duration<double> elapsed_game;
    if(game_time > 1.0)
    {
        ///An estimate of game time remaining per move
        time_limit = (game_time-1.0)/(double)empty_cnt;
    }
    else if(game_time > -1)
    {
        time_limit = 0.2;
    }

    cout<<"Search Depth: "<<height_limit<<" Search Time Limit: "<<time_limit<<endl;
    if(game_time > -1) cout<<"Remaining Time: "<<game_time<<endl;

    cout<<"CTM DDD\tTime"<<setw(12)<<"Calls"<<setw(12)<<"TTQ"<<setw(12)<<"TTF";
    cout<<setw(12)<<"TTC"<<"\tCBF\t"<<"Value"<<endl;
    max_height = 1;
    timeout = false;
    int local_colto=0, local_colfrom=0, local_rowto=0, local_rowfrom=0;
    TTQ = 0; TTF = 0; TTC = 0; betacuts = 0; CBF = 0;

    start = chrono::steady_clock::now();
    while(max_height <= height_limit)
    {
        nodes_evaluated = 0; betacuts = 0;

        if(search_mode==1)  best_score = AlphaBeta(max_height, -MAX_SCORE, MAX_SCORE);
        else
        {
            if(white_cnt==0)
                best_score = AlphaBeta(max_height, black_cnt, black_cnt+empty_cnt);
            else if(black_cnt==0)
                best_score = AlphaBeta(max_height, white_cnt, white_cnt+empty_cnt);
            else
            {
                int low_score = -(white_cnt+black_cnt+empty_cnt);
                int high_score = (white_cnt+black_cnt+empty_cnt);
                best_score = AlphaBeta(max_height, low_score, high_score);
            }
        }

        endt = chrono::steady_clock::now();
        chrono::duration<double> elapsed_seconds = endt-start;

        if(white)   cout<<"WHT ";
        else    cout<<"BLK ";
        cout<<setw(3)<<max_height<<"\t"<<fixed<<setprecision(2)<<elapsed_seconds.count();
        cout<<" "<<setw(12)<<nodes_evaluated;
        cout<<setw(12)<<TTQ<<setw(12)<<TTF<<setw(12)<<TTC<<"\t";
        cout<<fixed<<setprecision(2)<<CBF/(double)betacuts<<"\t"<<best_score<<endl;

        if(timeout)
        {
            if(game_time > 1.0) game_time -= elapsed_seconds.count();
            break;
        }
        /**
        If there is a timeout, use best move of previous search
        */
        local_colfrom = bestcolfrom;
        local_colto = bestcolto;
        local_rowfrom = bestrowfrom;
        local_rowto = bestrowto;
        max_height++;
    }

    ///Reverse Engineered from "move_piece" function
    char move_string[6];
    int idx = 0;
    move_string[idx++] = 'm';

    move_string[idx++] = (char)(local_colfrom+'a');
    move_string[idx++] = (char)('1'-(local_rowfrom-(n_board-1)));
    move_string[idx++] = (char)(local_colto+'a');
    move_string[idx++] = (char)('1'-(local_rowto-(n_board-1)));

    move_string[idx] = '\0';
    cout<<"move: "<<move_string+1<<endl;
    move_piece(move_string);
}

void ataxx_state::saveTT(int score, int rowto, int rowfrom, int colto, int colfrom, int height, int alpha, int beta)
{
//    if(height==1)   cout<<"SAVING: "<<Wstate<<endl;
    unsigned long long int idx;
    if(search_mode==2)  idx = hashValue % (unsigned long long)MAX_TT_SIZE;
    else    idx = hashValue % (unsigned long long)(256000);

    if(TTgc[idx]==gc && TTheight[idx]>height)   return;

    ///Store the states of White and Black pieces
    TTWstate[idx] = Wstate;
    TTBstate[idx] = Bstate;
    TTwhite[idx] = white;
    TTgc[idx] = gc;

    ///Store the other state variables
    TTscore[idx] = score;
    TTMove[idx][0] = (char)(rowfrom | (rowto << 4));
    TTMove[idx][1] = (char)(colfrom | (colto << 4));
    TTheight[idx] = height;

    ///Storing bound according to Alpha-Beta Theorem
    if(score <= alpha)  TTfvalue[idx] = UPPERBOUND;
    else if(score >= beta)  TTfvalue[idx] = LOWERBOUND;
    else    TTfvalue[idx] = EXACT;
}

unsigned long long int ataxx_state::checkTT(int height, int &alpha, int &beta)
{
    TTQ++;
    unsigned long long int idx;
    if(search_mode==2)  idx = hashValue % (unsigned long long)MAX_TT_SIZE;
    else    idx = hashValue % (unsigned long long)(256000);
    if(TTwhite[idx]==white && TTWstate[idx]==Wstate && TTBstate[idx]==Bstate)
    {
        TTF++;
        ///Trusted value, modify search window
        if(TTheight[idx]>=height)
        {
            if(TTfvalue[idx] == EXACT)
            {
                ///Changed the limits here to bring consistency
                alpha = TTscore[idx]-1;
                beta = TTscore[idx]+1;
            }
            else if(TTfvalue[idx] == LOWERBOUND)
                alpha = max(alpha, TTscore[idx]);
            else
                beta = min(beta, TTscore[idx]);
        }
        ///Only use best move for better heuristics
        return idx;
    }
    return -1;
}

void ataxx_state::print_stack()
{
    for(int i=0; i<stack_idx; i++)
    {
        int rowfrom = (int)(move_stack[i][0] & 15);
        int rowto = (int)((move_stack[i][0]>>4) & 15);
        int colfrom = (int)(move_stack[i][1] & 15);
        int colto = (int)((move_stack[i][1]>>4) & 15);
        char move_string[6];
        int idx = 0;
        move_string[idx++] = 'm';

        move_string[idx++] = (char)(colfrom+'a');
        move_string[idx++] = (char)('1'-(rowfrom-(n_board-1)));
        move_string[idx++] = (char)(colto+'a');
        move_string[idx++] = (char)('1'-(rowto-(n_board-1)));

        move_string[idx] = '\0';
        cout<<"DEBUG MOVES: "<<move_string<<endl;
    }
}

unsigned long long int ataxx_state::randomInt()
{
    uniform_int_distribution<unsigned long long int> dist(0, UINT64_MAX);
    return dist(mt);
}

void ataxx_state::set_fixed_height(int height)
{
    height_limit = height;
}

void ataxx_state::set_time_limit(double time)
{
    time_limit = time;
}

void ataxx_state::set_game_time(double time)
{
    game_time = time;
}

void ataxx_state::set_search_mode(int search_mode)
{
    this->search_mode = search_mode;
}

ataxx_state::~ataxx_state()
{
    //dtor
}
