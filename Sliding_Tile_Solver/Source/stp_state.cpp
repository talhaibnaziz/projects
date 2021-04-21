/* 
 * File:   stp_state.cpp
 * Author: talha
 * 
 * Created on March 11, 2021, 11:46 p.m.
 */

#include "stp_state.h"
#include <iostream>

using namespace std;

stp_state::stp_state() {
}

void stp_state::take_input()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin>>grid[i][j];
            if(grid[i][j] == 0)
            {
                row0 = i;
                col0 = j;
            }
        }
    }
    stack_idx = 0;
}

void stp_state::show_state()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<"\t"<<grid[i][j];
        cout<<endl;
    }
}

bool stp_state::goal_state()
{
    int tile = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(grid[i][j] != tile++)
                return false;
        }
    }
    return true;
}

bool stp_state::apply_move(int idx)
{
    int newR = dirR[idx] + row0;
    int newC = dirC[idx] + col0;

    if(newR<0 || newR==4 || newC<0 || newC==4)
        return false;

    ///Saving as character for future debugging
    move_stack[stack_idx++] = (char)(idx+'0');
    grid[row0][col0] = grid[newR][newC];
    grid[newR][newC] = 0;
    row0 = newR; col0 = newC;

    return true;
}

bool stp_state::undo_move()
{
    if(!stack_idx)
    {
        cout<<"No more moves to undo!"<<endl;
        return false;
    }
    stack_idx--;
    int oldR = -dirR[ move_stack[stack_idx]-'0' ] + row0;
    int oldC = -dirC[ move_stack[stack_idx]-'0' ] + col0;

    grid[row0][col0] = grid[oldR][oldC];
    grid[oldR][oldC] = 0;
    row0 = oldR; col0 = oldC;

    return true;
}

int stp_state::last_move()
{
    if(stack_idx > 0)   return (move_stack[stack_idx-1]-'0');
    else    return -1;
}

int stp_state::manhattan()
{
    int row, col;
    int heuristic = 0;
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(grid[i][j]==0)    continue;
            row = grid[i][j] / 4;
            col = grid[i][j] % 4;
            heuristic += abs(row-i) + abs(col-j);
        }
    }
    return heuristic;
}

int stp_state::manhattan_change()
{
    int newR = -dirR[ move_stack[stack_idx-1]-'0' ] + row0;
    int newC = -dirC[ move_stack[stack_idx-1]-'0' ] + col0;
    int goalR = grid[newR][newC] / 4;
    int goalC = grid[newR][newC] % 4;

    ///returning -OLD_Manhattan +NEW_Manhattan
    return ( -(abs(goalR-row0) + abs(goalC-col0)) +(abs(goalR-newR) + abs(goalC-newC)));
}

void stp_state::set_duals(vector <int> &rank_grid, vector <int> &dual_grid)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            rank_grid[i*4+j] = grid[i][j];
            dual_grid[ rank_grid[i*4+j] ] = i*4+j;
        }
    }
}

stp_state::~stp_state() {
}

