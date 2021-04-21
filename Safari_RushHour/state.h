#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>

class state
{
    public:
        state();

        /**
        Set the variables to store the
        puzzle grid information
        @return false if input is invalid
        */
        bool set_state();

        /**
        Show the current condition of the
        puzzle grid
        */
        void show_state();

        /**
        Check the possible move range in a
        specific direction for a specific piece
        @param seq sequence number of piece
        @param dir move direction
        @return possible range in mentioned direction
        */
        int move_range(int seq, int dir);

        /**
        Move a selected piece to a definite
        new location in the grid (must be valid)
        @param seq sequence number of piece
        @param dir is the direction of move
        @param range is the number of cells/steps
        */
        void movePiece(int seq, int dir, int range);

        /**
        Undo move and retrieve previous state
        Assumed to be always successful
        @param seq sequence number of piece
        @param dir is the direction of move
        @param range is the number of cells/steps
        */
        void undoMove(int seq, int dir, int range);

        /**
        Prints the move sequence from stack
        */
        void printMoves();

        /**
        Change the compressed state representation
        @param seq sequence of the piece to change
        @param row piece position row number
        @param col piece position column number
        @param add_remove true if add piece, false
        if piece needs to be removed
        */
        void change_state(int seq, int row, int col, bool add_remove);

        /**
        Save the generated state in a Transposition
        Table for future reference (check presence)
        @param gc generation counter (search track)
        @param gcost absolute path cost to this state
        @param hcost heuristic from this state to goal
        */
        void saveTT(int gc, int gcost, int hcost);

        /**
        Check for the presence of the generated state
        @param gc generation counter
        @param gcost absolute path cost to this state
        @return -1 for no match, -2 for better result
        of same call, otherwise return heuristic value
        */
        int checkTT(int gc, int gcost);

        /**
        Returns the Manhattan distance of the
        rover from the gate (in current grid)
        @return Manhattan Distance
        */
        int manhattan();

        /**
        Calculates a heuristic value based on
        the obstacles in the path
        @return heuristic value
        */
        int obstacles();

        /**
        Uses a combination of admissible heuristics
        to calculate a strong heuristic value
        @return heuristic value
        */
        int mixed_heuristic();

        ///Get the previous move
        unsigned long get_prev_move();

        ///Random number generation function
        unsigned long long int randomULLInt();

        ///Public Puzzle Grid information
        std::string pieces;

        virtual ~state();

    protected:

    private:
        ///Fixed Variables
        static const int MAX_GRID = 7;
        static const int MAX_PIECE = 26;
        static const int MAX_MOVES = 100;
        static const int MAX_TT_SIZE = 6100013;

        ///Puzzle Grid information
        std::string grid[MAX_GRID];
        unsigned int highbit;
        long long unsigned midbit, lowbit;
        ///Tactfully named (indexed) for easy calculation
        enum PIECE { TYPE_EMP=0, TYPE_x, TYPE_2x1, TYPE_3x1, TYPE_1x2, TYPE_uv, TYPE_1x3 };

        /**
        Piece information for row, column
        and type. The location always corresponds
        to left and topmost position of the piece.
        Type indicates piece shape, presence,
        and orientation (7 possible values).
        */
        std::vector <int> pieceR;
        std::vector <int> pieceC;
        std::vector <int> pieceT;

        /**
        Puzzle movement variables
        Opposite moves have complimentary relation
        */
        enum MOVE {LEFT=0, UP, DOWN, RIGHT};

        ///Move History (used vector for easy iteration)
        std::vector <unsigned long> moveStack;
        int stack_idx;

        ///Transposition and Zobrist Table Variables
        unsigned long long zobristTable[MAX_GRID][MAX_GRID+2][6];
        unsigned long long hashValue;

        std::vector <unsigned int> TTh;
        std::vector <unsigned long long> TTm, TTl;
        std::vector <int> TTgc, TTgcost, TThcost;
};

#endif // STATE_H
