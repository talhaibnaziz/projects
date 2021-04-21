/* 
 * File:   stp_state.h
 * Author: talha
 *
 * Created on March 11, 2021, 11:46 p.m.
 */

#ifndef STP_STATE_H
#define STP_STATE_H

#include <vector>
using namespace std;

class stp_state {
public:
    stp_state();
    /**
    Takes input directly from the console
    */
    void take_input();

    /**
    Prints the current state of the puzzle
    on the console directly
    */
    void show_state();

    /**
    Checks whether goal state is reached
    @return true if reached, else false
    */
    bool goal_state();

    /**
    Undo the state to previous tile positions
    using the optimized move stack
    @return false if reached end of stack
    */
    bool undo_move();

    /**
    Apply the move to the blank tile
    according to the index passed and
    the direction array for both axis
    @param idx can only range from 0 to 3
    @return -1 if move is invalid, else
    return change in heuristics
    */
    bool apply_move(int idx);

    ///Return last move from the stack
    int last_move();

    /**
    Calculate and return the addition
    of the Manhattan distance of all the
    nodes from the current to goal positions
    @return the distance value
    */
    int manhattan();

    ///Calculates Manhattan Distance incrementally
    int manhattan_change();
    
    ///Store the grid variables in SAS class
    void set_duals(vector <int> &rank_grid, vector <int> &dual_grid);

    virtual ~stp_state();
    
private:
    ///Puzzle tile location data
    int grid[4][4];
    int row0, col0;

    ///Direction arrays for applying operator
    int dirR[4] = {+1, 0, -1, 0};
    int dirC[4] = {0, +1, 0, -1};

    /**
    Move stack for undoing moves efficiently
    stored the move as character for less memory
    */
    char move_stack[10000];
    int stack_idx;
};

#endif /* STP_STATE_H */
