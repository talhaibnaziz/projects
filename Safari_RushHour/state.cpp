#include "state.h"
using namespace std;

mt19937 mt(01234567);

state::state()
{
    //ctor
    ///Initialize vectors
    for(int i=0; i<MAX_PIECE; i++)
    {
        pieceC.push_back(0);
        pieceR.push_back(0);
        pieceT.push_back(0);
    }
    for(int i=0; i<MAX_MOVES; i++)
        moveStack.push_back(0UL);

    ///Initialize Zobrist Table
    for(int i=0; i<MAX_GRID; i++)
        for(int j=0; j<MAX_GRID+2; j++)
            for(int k=0; k<6; k++)
                zobristTable[i][j][k] = randomULLInt();
    ///Should work for all puzzles
    for(int i=0; i<MAX_TT_SIZE; i++)
    {
        TTh.push_back(0L);
        TTm.push_back(0ULL);
        TTl.push_back(0ULL);
        TTgcost.push_back(0);
        TThcost.push_back(0);
        TTgc.push_back(-1);
    }
}

bool state::set_state()
{
    int seq;

    ///Initializing all information
    for(int i=0; i<MAX_PIECE; i++)   pieceT[i] = 0;
    stack_idx = 0;  pieces.clear(); hashValue = 0ULL;
    highbit = 0U; midbit = 0ULL; lowbit = 0ULL;
    for(int i=0; i<MAX_GRID; i++)
    {
        cin>>grid[i];
        if(i==2 || i==3)
        {
            if((int)grid[i].size() > MAX_GRID+1)    return false;
            grid[i][MAX_GRID]='.';
            grid[i].push_back('.');
        }
        else if((int)grid[i].size() > MAX_GRID)    return false;
        for(int j=0; j<MAX_GRID; j++)
        {
            if(grid[i][j]=='.') continue;

            seq = grid[i][j];
            seq -= 'a';
            ///If piece is not saved yet
            if(!pieceT[seq])
            {
                pieces.push_back(grid[i][j]);
                pieceR[seq] = i;
                pieceC[seq] = j;
                ///Different pieces (and orientation) info stored
                if(grid[i][j]=='x') pieceT[seq] = TYPE_x;
                else if(grid[i][j]=='u' || grid[i][j]=='v')
                    pieceT[seq] = TYPE_uv;
                else if(grid[i][j]=='o' || grid[i][j]=='q' || grid[i][j]=='s' || grid[i][j]=='p' || grid[i][j]=='r')
                {
                    if(j<MAX_GRID-1 && grid[i][j]==grid[i][j+1])
                        pieceT[seq] = TYPE_1x3;
                    else    pieceT[seq] = TYPE_3x1;
                }
                else
                {
                    if(j<MAX_GRID-1 && grid[i][j]==grid[i][j+1])
                        pieceT[seq] = TYPE_1x2;
                    else    pieceT[seq] = TYPE_2x1;
                }
                ///Transposition Table Processing
                change_state(seq, i, j, true);
                hashValue ^= zobristTable[i][j][pieceT[seq]-1];
            }
        }
    }
    return true;
}

void state::show_state()
{
    for(int i=0; i<MAX_GRID; i++)
        cout<<grid[i]<<endl;
    cout<<endl;
//    for(int i=0; i<(int)pieces.size(); i++)
//    {
//        cout<<"For piece: "<<pieces[i];
//        cout<<" LEFT: "<<move_range(pieces[i]-'a', LEFT);
//        cout<<" RIGHT: "<<move_range(pieces[i]-'a', RIGHT);
//        cout<<" UP: "<<move_range(pieces[i]-'a', UP);
//        cout<<" DOWN: "<<move_range(pieces[i]-'a', DOWN)<<endl;
//    }
}

int state::move_range(int seq, int dir)
{
    int row = pieceR[seq], col = pieceC[seq];
    int range = 0;

    ///Horizontal pieces cannot move up/down
    if((pieceT[seq]==TYPE_1x2 || pieceT[seq]==TYPE_1x3) && (dir==UP || dir==DOWN))
        return 0;
    ///Vertical pieces cannot move left/right
    if((pieceT[seq]==TYPE_2x1 || pieceT[seq]==TYPE_3x1) && (dir==LEFT || dir==RIGHT))
        return 0;
    ///Calculate possible move range in specified direction
    if(pieceT[seq]==TYPE_1x2 || pieceT[seq]==TYPE_1x3)
    {
        if(dir==LEFT)
        {
            while(col-1 >= 0 && grid[row][col-1]=='.') {   col--; range++; }
        }
        else if(dir==RIGHT)
        {
            ///For moving to the right
            col = col+pieceT[seq]/2;
            while(col < MAX_GRID && grid[row][col]=='.') {   col++; range++; }
        }
        return range;
    }
    if(pieceT[seq]==TYPE_2x1 || pieceT[seq]==TYPE_3x1)
    {
        if(dir==UP)
        {
            while(row-1 >= 0 && grid[row-1][col]=='.') {   row--; range++; }
        }
        ///For moving to the bottom
        else if(dir==DOWN)
        {
            row = row+pieceT[seq];
            while(row < MAX_GRID && grid[row][col]=='.') {   row++; range++; }
        }
        return range;
    }
    ///For the rover and termite mounds
    if(dir==LEFT)
        while(col-1 >= 0 && grid[row][col-1]=='.' && grid[row+1][col-1]=='.') {   col--; range++; }
    else if(dir==UP)
        while(row-1 >= 0 && grid[row-1][col]=='.' && grid[row-1][col+1]=='.') {   row--; range++; }
    else if(dir==RIGHT)
    {
        ///Special Case for the rover
        if(pieceT[seq]==TYPE_x)
            while(col+2 < MAX_GRID+2 && grid[row][col+2]=='.' && grid[row+1][col+2]=='.') {   col++; range++; }
        else    while(col+2 < MAX_GRID && grid[row][col+2]=='.' && grid[row+1][col+2]=='.') {   col++; range++; }
    }
    else
        while(row+2 < MAX_GRID && grid[row+2][col]=='.' && grid[row+2][col+1]=='.') {   row++; range++; }

    return range;
}

void state::movePiece(int seq, int dir, int range)
{
    int newR = pieceR[seq], newC = pieceC[seq];

    if(dir == LEFT)   newC -= range;
    else if(dir == UP)    newR -= range;
    else if(dir == RIGHT) newC += range;
    else newR += range;

    ///Calculate the shape of the piece
    int rlim, clim;
    if(pieceT[seq]==TYPE_x || pieceT[seq]==TYPE_uv)
    {
        rlim = 2; clim = 2;
    }
    else if(pieceT[seq]==TYPE_1x2 || pieceT[seq]==TYPE_1x3)
    {
        rlim = 1;
        clim = pieceT[seq]/2;
    }
    else
    {
        rlim = pieceT[seq];
        clim = 1;
    }

    ///Apply the move successfully (remove piece)
    for(int i=pieceR[seq]; i<(pieceR[seq]+rlim); i++)
        for(int j=pieceC[seq]; j<(pieceC[seq]+clim); j++)
            grid[i][j] = '.';

    ///Apply the move successfully (add piece)
    for(int i=newR; i<(newR+rlim); i++)
        for(int j=newC; j<(newC+clim); j++)
            grid[i][j] = 'a'+seq;

    ///Transposition Table Processing
    change_state(seq, pieceR[seq], pieceC[seq], false);
    hashValue ^= zobristTable[pieceR[seq]][pieceC[seq]][pieceT[seq]-1];

    change_state(seq, newR, newC, true);
    hashValue ^= zobristTable[newR][newC][pieceT[seq]-1];

    pieceR[seq] = newR; pieceC[seq] = newC;
    ///Adding move to Move History
    moveStack[stack_idx] = 0UL;
    moveStack[stack_idx] |= (unsigned long)range;
    moveStack[stack_idx] |= (unsigned long)(dir<<4);
    moveStack[stack_idx] |= (unsigned long)(seq<<6);
    stack_idx++;
}

void state::undoMove(int seq, int dir, int range)
{
    int oldR = pieceR[seq], oldC = pieceC[seq];
    if(dir == RIGHT)  oldC -= range;
    else if(dir == DOWN)  oldR -= range;
    else if(dir == LEFT)  oldC += range;
    else oldR += range;

    ///Calculate the shape of the piece
    int rlim, clim;
    if(pieceT[seq]==TYPE_x || pieceT[seq]==TYPE_uv)
    {
        rlim = 2; clim = 2;
    }
    else if(pieceT[seq]==TYPE_1x2 || pieceT[seq]==TYPE_1x3)
    {
        rlim = 1;
        clim = pieceT[seq]/2;
    }
    else
    {
        rlim = pieceT[seq];
        clim = 1;
    }
    ///Undo the move (remove piece)
    for(int i=pieceR[seq]; i<(pieceR[seq]+rlim); i++)
        for(int j=pieceC[seq]; j<(pieceC[seq]+clim); j++)
            grid[i][j] = '.';

    ///Undo the move (add piece)
    for(int i=oldR; i<(oldR+rlim); i++)
        for(int j=oldC; j<(oldC+clim); j++)
            grid[i][j] = 'a'+seq;

    ///Transposition Table Processing
    change_state(seq, pieceR[seq], pieceC[seq], false);
    hashValue ^= zobristTable[pieceR[seq]][pieceC[seq]][pieceT[seq]-1];

    change_state(seq, oldR, oldC, true);
    hashValue ^= zobristTable[oldR][oldC][pieceT[seq]-1];

    pieceR[seq] = oldR; pieceC[seq] = oldC;
    stack_idx--;
}

void state::printMoves()
{
    for(int i=0; i<stack_idx; i++)
    {
        cout<<" "<<(char)((moveStack[i] >> 6)+'a');
        if(((moveStack[i] >> 4) % 4UL)==LEFT)   cout<<"l";
        else if(((moveStack[i] >> 4) % 4UL)==RIGHT)   cout<<"r";
        else if(((moveStack[i] >> 4) % 4UL)==UP)   cout<<"u";
        else   cout<<"d";
        cout<<(moveStack[i]%16UL);
    }
    cout<<endl;
}

void state::change_state(int seq, int row, int col, bool add_remove)
{
    /**
    No need to work with goal state and break formation
    This skipping only works if movePiece and undoMove
    is executed one after the other and the game does not
    proceed further after the goal state is reached
    */
    if(col == MAX_GRID) return;

    unsigned long long linear_d = row*MAX_GRID + col;
    if(add_remove)
    {
        if(linear_d < 21ULL)   lowbit |= ((unsigned long long)pieceT[seq]<<(linear_d*3ULL));
        else if(linear_d <42ULL)   midbit |= ((unsigned long long)pieceT[seq]<<((linear_d%21ULL)*3ULL));
        else    highbit |= ((unsigned)pieceT[seq]<<((linear_d%42ULL)*3ULL));
    }
    else
    {
        if(linear_d < 21ULL)   lowbit -= ((unsigned long long)pieceT[seq]<<(linear_d*3ULL));
        else if(linear_d <42ULL)   midbit -= ((unsigned long long)pieceT[seq]<<((linear_d%21ULL)*3ULL));
        else    highbit -= ((unsigned)pieceT[seq]<<((linear_d%42ULL)*3ULL));
    }
}

void state::saveTT(int gc, int gcost, int hcost)
{
    int idx = hashValue % MAX_TT_SIZE;

    TTgc[idx] = gc;
    TTgcost[idx] = gcost;
    ///Save the most accurate heuristic value for the same state
    if(TTh[idx]==highbit && TTm[idx]==midbit && TTl[idx]==lowbit)
    {
        TThcost[idx] = max(hcost, TThcost[idx]);
        return;
    }
    else    TThcost[idx] = hcost;
    TTh[idx] = highbit;
    TTm[idx] = midbit;
    TTl[idx] = lowbit;
}

int state::checkTT(int gc, int gcost)
{
    int idx = hashValue % MAX_TT_SIZE;
    ///State match found
    if(TTh[idx]==highbit && TTm[idx]==midbit && TTl[idx]==lowbit)
    {
        /**
        TT Entry of same DFS call with less/equal depth
        No need to search further (repetition)
        */
        if(TTgc[idx]==gc && gcost >= TTgcost[idx])
        {
            return -2;
        }
        /**
        TT Entry of another DFS call or same DFS with
        more depth, needs to be updated
        */
        if(TTgc[idx] != -1)
            return TThcost[idx];
    }
    ///No entry found
    return -1;
}

int state::manhattan()
{
    int hcost = 0;
    if(pieceR['x'-'a']-2)   hcost++;
    if(pieceC['x'-'a']-7)   hcost++;
    return hcost;
}

int state::obstacles()
{
    int row = pieceR['x'-'a'], col = pieceC['x'-'a'];
    int obs = 0;
    while(row > 2)
    {
        row--;
        if(!obs && (grid[row][col]!='.' || grid[row][col+1]!='.'))
            obs = 1;
    }
    while(row < 2)
    {
        row++;
        if(!obs && (grid[row+1][col]!='.' || grid[row+1][col+1]!='.'))
            obs = 1;
    }
    while(col < 5)
    {
        col++;
        if(!obs && (grid[row][col+1]!='.' || grid[row+1][col+1]!='.'))
            obs = 1;
    }
    return obs;
}

int state::mixed_heuristic()
{
    //return manhattan();
    return manhattan()+obstacles();
}

unsigned long state::get_prev_move()
{
    /**
    There should be no move with range = 0
    So, move_int should not equal to 0
    */
    unsigned long move_int = 0UL;
    if(stack_idx > 0)   move_int = moveStack[stack_idx-1];
    return move_int;
}

unsigned long long int state::randomULLInt()
{
    uniform_int_distribution<unsigned long long int> dist(0, UINT64_MAX);
    return dist(mt);
}

state::~state()
{
    //dtor
}
