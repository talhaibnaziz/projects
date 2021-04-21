/* 
 * File:   SAS.h
 * Author: talha
 *
 * Created on March 11, 2021, 11:49 p.m.
 */

#ifndef SAS_H
#define SAS_H

#include <vector>
#include <iomanip>
#include <chrono>
#include "stp_state.h"
using namespace std;

class SAS {
public:
    SAS();
    
    /**
    Performs Depth First Iterative Deepening
    and becomes too slow after depth 17 finding
    no solution for the first case after searching
    through 286,942,815 nodes (too many repetitions
    */
    void DFID();

    /**
    The Depth First Search algorithm
    */
    int DFS(int height);

    /**
    This is the driver for the IDAstar algorithm
    */
    void IDAstar();

    /**
    This is the DFS algorithm using a combination
    of actual cost and heuristics
    */
    int IDAstarDFS(int gcost, int hcost);

    /**
    Creates the Pattern Database 1
              0 1 2 3
    Pattern = 4 5 6 7
              * * * *
              * * * *
    @return true if successful
    */
    bool create_pdb1();
    
    /**
    Creates the Pattern Database 2
               0  *  *  *
    Pattern =  *  *  *  *
               8  9 10 11
              12 13 14 15
    @return true if successful
    */
    bool create_pdb2();

    /**
     * de-rank a value and store the dual
     * @param Rank value
     * @param pattern = sorted vector of pattern values
    */
    void unrank(unsigned Rank, const vector <int> &pattern);
    
    /**
     * Convert a grid state into a rank
     * value and return the value
     * @param pattern = sorted vector of pattern values
     * @return rank value
     */
    unsigned ranking(const vector <int> &pattern);

    virtual ~SAS();
private:
    ///The puzzle instance used by the algorithms
    stp_state state;

    ///Number of nodes searched
    int nodes;

    ///The upper bound of search
    int fcost_bound;

    ///Indicator of whether result is found
    bool result;

    ///8-value pattern database variables
    const unsigned MAX_PDB1 = 518918400;
    const unsigned MAX_PDB2 = 4151347200;
    const int MAX_PUZZLE = 16;
    vector <unsigned char> PDB1;
    vector <unsigned char> PDB2;
    
    ///For ranking and de-ranking
    vector <int> rank_grid, dual_grid, temp_grid;
    vector <int> pattern1;
    vector <int> pattern2;
    ///Direction matrix for tiles
    enum {RIGHT=0, LEFT, DOWN, UP};
    int dir[4] = {1,-1,4,-4};
    
    ///Statistical Variables
    chrono::steady_clock::time_point start, endt;
    chrono::duration <double> elapsed_seconds;
};

#endif /* SAS_H */
