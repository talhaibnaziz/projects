/* 
 * File:   SAS.cpp
 * Author: talha
 * 
 * Created on March 11, 2021, 11:49 p.m.
 */

#include "SAS.h"
#include <iostream>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <algorithm>
using namespace std;

SAS::SAS() {
	///Initializing the puzzle grid and dual
    for(int i=0; i<MAX_PUZZLE; i++)
    {
        rank_grid.push_back(0);
        dual_grid.push_back(0);
        temp_grid.push_back(0);
    }
}

void SAS::DFID()
{
//    state.take_input();
    int depth = 1;

    while(depth<20)
    {
        nodes = 0;
        cout<<"Solutions Found: "<<DFS(depth)<<endl;
        cout<<"in Depth: "<<depth++<<endl;
        cout<<"Nodes Traversed: "<<nodes<<endl;
    }
}

int SAS::DFS(int height)
{
    ///If goal state achieved, terminate
    if(state.goal_state())
        return 1;
    ///If tree limit reached, terminate
    if(!height) return 0;
//    cout<<"Height: "<<height<<endl;
    state.show_state();
    nodes++;
    int ret = 0;
    for(int i=0; i<4; i++)
    {
        ///Going back to parent state is avoided
        if(state.last_move()!=-1 && abs(i-state.last_move())==2)    continue;

        ///Invalid states are avoided
        if(!state.apply_move(i)) continue;

        ret += DFS(height-1);
        state.undo_move();
    }
    return ret;
}

void SAS::IDAstar()
{
    state.take_input();
    state.show_state();
    fcost_bound = state.manhattan();
    state.set_duals(rank_grid, dual_grid);
    nodes = 0;
    unsigned Rank = ranking(pattern1);
    fcost_bound = max(fcost_bound, (int)PDB1[Rank]);
    Rank = ranking(pattern2);
    fcost_bound = max(fcost_bound, (int)PDB2[Rank]);
    
    result = false;
    cout<<"Bound "<<setw(12)<<"Nodes"<<" "<<setw(12)<<"Time"<<endl;
    start = chrono::steady_clock::now();
    while(!result)
    {
        result = IDAstarDFS(0, fcost_bound);
        cout<<setw(5)<<fcost_bound<<" "<<setw(12)<<nodes;
        endt = chrono::steady_clock::now();
        elapsed_seconds = endt - start;
        cout<<setw(12)<<fixed<<setprecision(5)<<elapsed_seconds.count()<<endl;
        fcost_bound += 2;
        nodes = 0;
    }
}

int SAS::IDAstarDFS(int gcost, int hcost)
{
    ///If goal state achieved, terminate
    if(state.goal_state())
    {
        result = true;
        //state.show_state();
        return 1;
    }

    ///If fcost bound is crossed
    if((gcost + hcost) > fcost_bound)
        return 0;

    nodes++;
    int ret = 0, new_hcost;
    unsigned Rank;
    for(int i=0; i<4 && !result; i++)
    {
        ///Going back to parent state is avoided
        if(state.last_move()!=-1 && abs(i-state.last_move())==2)
        {
//            cout<<"REPETITION"<<endl;
            continue;
        }

        ///Invalid states are avoided
        if(!state.apply_move(i)) continue;
        state.set_duals(rank_grid, dual_grid);
        Rank = ranking(pattern1);
        new_hcost = max((int)PDB1[Rank], state.manhattan());
        Rank = ranking(pattern2);
        new_hcost = max((int)PDB2[Rank], new_hcost);
        ret += IDAstarDFS(gcost + 1, new_hcost);
        state.undo_move();
    }
//    cout<<"Return: "<<ret<<endl;
    return ret;
}

bool SAS::create_pdb1()
{
    start = chrono::steady_clock::now();
    ///Initializing the pattern database 1
    for(unsigned i=0; i<MAX_PDB1; i++)    PDB1.push_back((unsigned char)255);
    endt = chrono::steady_clock::now();
    elapsed_seconds = endt-start;
    cout<<"Time to Initialize PDB1: "<<elapsed_seconds.count();
    cout<<" Size of PDB1: "<<PDB1.size()<<endl;
    
    ///Forming the pattern value set
    int pos0, newPos, i;
    for(i=0; i<MAX_PUZZLE/2; i++)   pattern1.push_back(i);
    unsigned char max_solution = (unsigned char)0;
    
    /**
     * Reading pattern database from file (location: database/PDB2.data)
     * Comment this code section if the pattern database for pattern 2 has
     * not been written to the file yet.
     */
     FILE * rFile;
	 rFile = fopen ("database/PDB1.data", "rb");
	 if(rFile == NULL)
	 {
		 cout<<"ERROR: No file to read data base from!"<<endl;
		 return false;
	 }
	 cout<<"PDB1 Read from file: "<<fread(PDB1.data(), sizeof(char), MAX_PDB1, rFile)<<endl;
	 fclose (rFile);
	 return true;
    
    cout<<"DD "<<setw(12)<<"Q-size"<<" "<<setw(10)<<"Time-D"<<setw(10)<<"Time-T"<<endl;
    queue <int> rankQ;
    unsigned Rank, newRank;
    
    ///For goal state rank is 0
    rankQ.push(0); PDB1[0] = (unsigned char)0;
    while(!rankQ.empty())
    {
        Rank = rankQ.front();
        rankQ.pop();
        unrank(Rank, pattern1);
        //~ cout<<"From Queue:";
        //~ for(int i=0; i<MAX_PUZZLE; i++)	cout<<" "<<rank_grid[i];
        //~ cout<<endl;
        pos0 = dual_grid[0];
        if(max_solution==PDB1[Rank])
        {
            cout<<setw(2)<<(int)max_solution<<" "<<setw(12)<<(int)rankQ.size();
            elapsed_seconds = chrono::steady_clock::now() - endt;
            cout<<" "<<setw(10)<<fixed<<setprecision(6)<<elapsed_seconds.count();
            endt = chrono::steady_clock::now();
            elapsed_seconds = endt - start;
            cout<<" "<<setw(10)<<fixed<<setprecision(5)<<elapsed_seconds.count()<<endl;
            max_solution++;
        }
        for(i=0; i<4; i++)
        {
            if(pos0%4 == 0 && i==LEFT)    continue;
            if(pos0%4 == 3 && i==RIGHT)    continue;
            if(pos0<4 && i==UP)    continue;
            if(pos0>11 && i==DOWN)    continue;
            
            newPos = pos0+dir[i];
            swap(dual_grid[0], dual_grid[ rank_grid[newPos] ]);
            swap(rank_grid[pos0], rank_grid[newPos]);
            newRank = ranking(pattern1);
            ///If new state is not visited yet
            if(PDB1[newRank] == (unsigned char)255)
            {
                PDB1[newRank] = PDB1[Rank] + (unsigned char)1;
                rankQ.push(newRank);
				//~ cout<<"Pushing:";
				//~ for(int i=0; i<MAX_PUZZLE; i++)	cout<<" "<<rank_grid[i];
				//~ cout<<endl;
            }
            swap(dual_grid[0], dual_grid[ rank_grid[pos0] ]);
            swap(rank_grid[pos0], rank_grid[newPos]);
        }
    }
    ///Writing pattern database to file
    FILE * wFile;
	wFile = fopen ("database/PDB1.data", "wb");
	fwrite (PDB1.data() , sizeof(char), MAX_PDB1, wFile);
	fclose (wFile);
	return true;
}

bool SAS::create_pdb2()
{
    start = chrono::steady_clock::now();
    
    ///Initializing the pattern database 2
    for(unsigned i=0; i<MAX_PDB2; i++)    PDB2.push_back((unsigned char)255);
    endt = chrono::steady_clock::now();
    elapsed_seconds = endt-start;
    cout<<"Time to Initialize PDB2: "<<elapsed_seconds.count();
    cout<<" Size of PDB2: "<<PDB2.size()<<endl;
    
    ///Forming the pattern value set
    int pos0, newPos, i;
    pattern2.push_back(0);
    for(i=MAX_PUZZLE/2; i<MAX_PUZZLE; i++)   pattern2.push_back(i);
    unsigned char max_solution = (unsigned char)0;
    
    /**
     * Reading pattern database from file (location: database/PDB2.data)
     * Comment this code section if the pattern database for pattern 2 has
     * not been written to the file yet.
     */
     FILE * rFile;
	 rFile = fopen ("database/PDB2.data", "rb");
	 if(rFile == NULL)
	 {
		 cout<<"ERROR: No file to read data base from!"<<endl;
		 return false;
	 }
	 cout<<"PDB2 Read from file: "<<fread(PDB2.data(), sizeof(char), MAX_PDB2, rFile)<<endl;
	 fclose (rFile);
	 return true;
	
    cout<<"DD "<<setw(12)<<"Q-size"<<" "<<setw(10)<<"Time-D"<<setw(10)<<"Time-T"<<endl;
    queue <unsigned> rankQ;
    unsigned Rank, newRank;
    
    ///For goal state rank is 130,455,927
    rankQ.push(130455927U); PDB2[130455927] = (unsigned char)0;
    while(!rankQ.empty())
    {
        Rank = rankQ.front();
        rankQ.pop();
        unrank(Rank, pattern2);
        //~ cout<<"From Queue:";
        //~ for(int i=0; i<MAX_PUZZLE; i++)	cout<<" "<<rank_grid[i];
        //~ cout<<endl;
        pos0 = dual_grid[0];
        if(max_solution==PDB2[Rank])
        {
            cout<<setw(2)<<(int)max_solution<<" "<<setw(12)<<(int)rankQ.size();
            elapsed_seconds = chrono::steady_clock::now() - endt;
            cout<<" "<<setw(10)<<fixed<<setprecision(6)<<elapsed_seconds.count();
            endt = chrono::steady_clock::now();
            elapsed_seconds = endt - start;
            cout<<" "<<setw(10)<<fixed<<setprecision(5)<<elapsed_seconds.count()<<endl;
            max_solution++;
        }
        for(i=0; i<4; i++)
        {
            if(pos0%4 == 0 && i==LEFT)    continue;
            if(pos0%4 == 3 && i==RIGHT)    continue;
            if(pos0<4 && i==UP)    continue;
            if(pos0>11 && i==DOWN)    continue;
            
            newPos = pos0+dir[i];
            swap(dual_grid[0], dual_grid[ rank_grid[newPos] ]);
            swap(rank_grid[pos0], rank_grid[newPos]);
            newRank = ranking(pattern2);
            
            ///If new state is not visited yet
            if(PDB2[newRank] == (unsigned char)255)
            {
                PDB2[newRank] = PDB2[Rank] + (unsigned char)1;
                rankQ.push(newRank);
				//~ cout<<"Pushing:";
				//~ for(int i=0; i<MAX_PUZZLE; i++)	cout<<" "<<rank_grid[i];
				//~ cout<<endl;
            }
            swap(dual_grid[0], dual_grid[ rank_grid[pos0] ]);
            swap(rank_grid[pos0], rank_grid[newPos]);
        }
    }
    ///Writing pattern database to file
    FILE * wFile;
	wFile = fopen ("database/PDB2.data", "wb");
	fwrite (PDB2.data() , sizeof(char), MAX_PDB2, wFile);
	fclose (wFile);
	return true;
}

void SAS::unrank(unsigned Rank, const vector <int> &pattern)
{
    unsigned p_size = pattern.size();
    unsigned base = (MAX_PUZZLE - p_size) + 1U;
    int i, j;
    ///Placing the formed state in dual_grid
    for(i=(int)p_size-1; i>=0; i--)
    {
        dual_grid[ pattern[i] ] = (int)(Rank % base);
        Rank -= (unsigned)dual_grid[ pattern[i] ];
        Rank /= base;
        temp_grid[ pattern[i] ] = dual_grid[ pattern[i] ];
        base++;
    }
    ///Forming the state - rank_grid using dual_grid
    for(i=1; i<(int)p_size; i++)
    {
        for(j=i-1; j>=0; j--)
            if(dual_grid[ pattern[i] ] >= temp_grid[ pattern[j] ])    dual_grid[ pattern[i] ]++;
    }
    for(i=0; i<MAX_PUZZLE; i++) rank_grid[i] = MAX_PUZZLE;
    for(i=0; i<(int)p_size; i++) rank_grid[ dual_grid[ pattern[i] ] ] = pattern[i];
    ///Fix the duals for the dummy values
    if(pattern[1]==8)	p_size = 1;
    for(i=0; i<MAX_PUZZLE; i++)
    {
        if(rank_grid[i] == MAX_PUZZLE)
        {
            dual_grid[p_size] = i;
            rank_grid[i] = (int)p_size;
            p_size++;
        }
    }
    ///Optimized de-ranking from a given Rank value
//    int N = MAX_PUZZLE, idx = MAX_PUZZLE-1, x;
//    for(int i=0; i<N; i++)
//    {
//        rank_grid[i] = i;
//        dual_grid[i] = i;
//    }
//    while(N>1)
//    {
//        x = Rank%N;
//        swap(dual_grid[ rank_grid[idx] ], dual_grid[ rank_grid[x] ]);
//        swap(rank_grid[idx], rank_grid[x]);
//        Rank /= N;
//        N--; idx--;
//    }
}

unsigned SAS::ranking(const vector <int> &pattern)
{
    unsigned base = MAX_PUZZLE, p_size = pattern.size();
    unsigned idx, multiplier, factor, i, j;
    unsigned Rank = 0U;
    for(i=0; i<p_size; i++)
    {
        idx = dual_grid[ pattern[i] ];
        multiplier = base;
        factor = 1;
        while(--multiplier > (MAX_PUZZLE-p_size))  factor *= multiplier;
        for(j=0; j<i; j++) 
            if(dual_grid [ pattern[j] ] < dual_grid [ pattern[i] ])
                idx--;
        Rank += idx * factor;
        base--;
    }
    //Optimized ranking for a state
//    int idx = MAX_PUZZLE-1, pos;
//    int Rank = 0;
//    stack <int> st;
//    while(idx > 0)
//    {
//        pos = dual_grid[idx];
//        st.push(rank_grid[idx]);
//        swap(dual_grid[ rank_grid[idx] ], dual_grid[ rank_grid[pos] ]);
//        swap(rank_grid[idx], rank_grid[pos]);
//        idx--;
//    }
//    int N = MAX_PUZZLE-2;
//    while(true)
//    {
//        Rank += st.top();
//        st.pop();
//        if(st.empty())  break;
//        Rank *= N;
//        N++;
//    }
    return Rank;
}

SAS::~SAS() {
}

