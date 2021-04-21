#include "SAS.h"
using namespace std;

SAS::SAS()
{
    //ctor
}

bool SAS::init(const string &input)
{
    if(!rush_hour.set_state())  return false;
    cout<<"New Puzzle Grid: "<<endl;
    rush_hour.show_state();
    this->p_name = input;
    return true;
}

void SAS::BFS()
{
    //priority_queue <pair< unsigned, pair<unsigned long long, unsigned long long> > PQ;
}

void SAS::DFID()
{
    depth_limit = 0; found = false;
    while(!found)
    {
        nodes = 0ULL;
        DFS(0);
        cout<<"Max Depth: "<<depth_limit<<" Nodes: "<<nodes<<endl;
        depth_limit++;
    }
}

int SAS::DFS(int depth)
{
    if(found || depth > depth_limit) return MAX_MOVES;
    nodes++;

    if(!rush_hour.manhattan())
    {
        found = true;
        cout<<"Solution: ";
        rush_hour.printMoves();
        return 0;
    }

    int i, seq, j, range, k, ret = MAX_MOVES;
    for(i=0; i<(int)rush_hour.pieces.size() && !found; i++)
    {
        seq = rush_hour.pieces[i]-'a';
        for(j=0; j<MOVE_SIZE && !found; j++)
        {
            range = rush_hour.move_range(seq, j);
            for(k=1; k<=range && !found; k++)
            {
                rush_hour.movePiece(seq, j, k);
                ret = min(ret, 1+DFS(depth+1));
                rush_hour.undoMove(seq, j, k);
            }
        }
    }

    return ret;
}

void SAS::IDAstar(int time_limit)
{
    this->time_limit = time_limit;
    depth_limit = rush_hour.mixed_heuristic();
    found = false;  gc = 0;
    int hcost = -1;
    start = chrono::steady_clock::now();
    cout<<"DDD "<<setw(12)<<"Nodes"<<" "<<setw(10)<<"Time";
    cout<<" CMin"<<"  CAvg"<<" CMax"<<" AvgHc"<<endl;
    while(!found)
    {
        nodes = 0ULL; Coffcnt = 0.0; AvgH = 0.0; AvgHnodes = 0.0;
        CoffAvg = 0.0; CoffMax = -MAX_MOVES; CoffMin = MAX_MOVES;
        ///Adjust depth limit if better heuristic available
        hcost = rush_hour.checkTT(gc, 0);
        depth_limit = max(hcost, depth_limit);
        ///Exception catching for timeouts
        try{
            DFAstar(0);
        }
        catch(bool timeout)
        {
            if(timeout) cout<<"TIMEOUT: "<<elapsed_seconds.count()<<endl;
            return;
        }
        gc++;
        cout<<setw(3)<<depth_limit<<" "<<setw(12)<<nodes;
        endt = chrono::steady_clock::now();
        elapsed_seconds = endt - start;
        cout<<" "<<setw(10)<<fixed<<setprecision(6)<<elapsed_seconds.count()<<" ";
        cout<<setw(4)<<CoffMin<<" "<<setw(5)<<fixed<<setprecision(2)<<CoffAvg/Coffcnt;
        cout<<" "<<setw(4)<<CoffMax<<" "<<setw(5)<<fixed<<setprecision(2)<<AvgH/AvgHnodes<<endl;
        //cout<<" TTQ: "<<TTQ<<" TTF: "<<TTF<<" TTC: "<<TTC<<endl;
        depth_limit++;
    }
}

int SAS::DFAstar(int depth)
{
    if(found || ((depth + rush_hour.mixed_heuristic()) > depth_limit))
    {
        if(!found)
        {
            CoffMin = min(depth, CoffMin);
            CoffMax = max(depth, CoffMax);
            CoffAvg += (double) depth;
            Coffcnt += 1.0;
        }
        return rush_hour.mixed_heuristic();
    }
    nodes++;

    /**
    Check every 10,000 nodes for TIMEOUTS instead of
    checking every node (DFAstar call). Assuming that
    time change for such is negligible (compared to 1 second)
    */
    if(nodes % 10000ULL == 0)
    {
        endt = chrono::steady_clock::now();
        elapsed_seconds = endt - start;
        if(elapsed_seconds.count() > (double)time_limit)
            throw true;
    }

    if(!rush_hour.manhattan())
    {
        found = true;
        cout<<"solution "<<p_name<<" ";
        cout<<elapsed_seconds.count()<<" "<<depth;
        rush_hour.printMoves();
        return 0;
    }

    int TTvalue = rush_hour.checkTT(gc, depth);

    ///Check bound with TT heuristic
    if(TTvalue != -1 && ((depth + TTvalue) > depth_limit))
    {
        CoffMin = min(depth, CoffMin);
        CoffMax = max(depth, CoffMax);
        CoffAvg += (double) depth;
        Coffcnt += 1.0;
        return TTvalue;
    }

    /**
    Entry found in same DFS call with less depth
    No need to search further (repetition)
    */
    if(TTvalue == -2) return MAX_MOVES;
    ///Save state for repetition check
    rush_hour.saveTT(gc, depth, rush_hour.mixed_heuristic());

    ///Calculate previous move variables
    int i, seq, j, range, k, ret = MAX_MOVES;
    unsigned long prev_move = rush_hour.get_prev_move();
    int prev_seq = -1, prev_dir = -1;
    if(prev_move != 0UL)
    {
        prev_dir = (signed)((prev_move>>4) % 4ULL);
        prev_seq = (signed)(prev_move>>6);
    }

    for(i=0; i<(int)rush_hour.pieces.size() && !found; i++)
    {
        seq = rush_hour.pieces[i]-'a';
        for(j=0; j<MOVE_SIZE && !found; j++)
        {
            ///Ignore bad/repetitive moves of previous iteration
            if(prev_move != 0UL && seq==prev_seq && (j==prev_dir || j==((MOVE_SIZE-1)-prev_dir)))
                continue;

            range = rush_hour.move_range(seq, j);
//            cout<<"DEPTH: "<<depth<<" RANGE "<<(char)(seq+'a')<<": "<<j<<" "<<range<<endl;
            for(k=1; k<=range && !found; k++)
            {
                rush_hour.movePiece(seq, j, k);
                ret = min(ret, 1+DFAstar(depth+1));
                rush_hour.undoMove(seq, j, k);
            }
        }
    }

    ///Save state with updated (valid) heuristic value
    if(ret < MAX_MOVES)
    {
        AvgH += (double)ret;
        AvgHnodes += 1.0;
        rush_hour.saveTT(gc, depth, ret);
    }

    return ret;
}

SAS::~SAS()
{
    //dtor
}
