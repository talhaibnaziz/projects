#ifndef SAS_H
#define SAS_H

#include "state.h"
#include <chrono>
#include <string>
#include <iomanip>
#include <exception>
using namespace std;

class SAS
{
    public:
        SAS();

        /**
        Initializes the single agent search
        class - reset variables, states, etc.
        @param input = name of problem being solved
        @return false if invalid input given
        */
        bool init(const string &input);

        /**
        Performs Breadth First Search for testing
        */
        void BFS();

        /**
        Performs Depth First Iterative Deepening
        using Depth First Search (DFS)
        */
        void DFID();

        /**
        Depth First Search using recursion
        @param depth of the search tree
        @return solution length
        */
        int DFS(int depth);

        /**
        Performs Iterative Deepening Astar
        using Depth First Search using fcosts
        @param time_limit maximum time per case
        */
        void IDAstar(int time_limit);

        /**
        Depth First Search using fcosts
        @param depth (and gcost) of the search tree
        @return solution length
        */
        int DFAstar(int depth);

        virtual ~SAS();

    protected:

    private:
        ///The state variable for the puzzle
        state rush_hour;
        ///True if solution is found
        bool found;
        ///Problem Label
        string p_name;

        ///Limit variables
        int depth_limit;
        static const int MAX_MOVES = 1000;
        static const int MOVE_SIZE = 4;

        ///Statistical Variables
        chrono::steady_clock::time_point endt, start;
        chrono::duration<double> elapsed_seconds;
        unsigned long long nodes;
        int CoffMin, CoffMax;
        double CoffAvg, Coffcnt;
        int gc, time_limit;
        double AvgH, AvgHnodes;
};

#endif // SAS_H
