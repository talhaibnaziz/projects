#ifndef ATAXX_STATE_H
#define ATAXX_STATE_H

#define MAX_SCORE 70
#define MAX_DEPTH 1000
#define MAX_TIME 1000
#define MAX_TT_SIZE 6000119
#define UPPERBOUND 1
#define EXACT 2
#define LOWERBOUND 3

#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <iomanip>
#include <random>

using namespace std;

class ataxx_state
{
    public:

        /**
        Initializes the board demand variables
        and the statements in this constructor
        must be repeated each time a game ends
        */
        ataxx_state();

        /**
        This function prints the contents
        of the current board state
        */
        void show_state();

        ///Sets the dimensions of the board
        void set_size();

        /**
        Command to set the pieces in the
        board before starting the game
        */
        void set_state();

        /**
        Sets the turn to white or black
        depending on the input parameter
        @param turn true for white o/w false
        */
        void set_turn(bool turn);

        /**
        Moves a piece from one square to another
        as long as it is a legal move
        */
        void move_piece(char *input);

        /**
        Perform the move according to the row
        and column parameters
        */
        void do_move(int rowfrom, int colfrom, int rowto, int colto);

        /**
        Returns back to the previous state
        VERY OPTIMIZED and cannot work with
        a greater boar size
        @param realtime true if called by main
        */
        void undo_move(bool realtime);

        /**
        Modifies NegaMax to prune search
        tree without losing optimality
        @param depth of the search tree
        @param alpha lower limit of score
        @param beta upper limit of score
        @return score of plater to move
        */
        int AlphaBeta(int height, int alpha, int beta);

        /**
        checks if the game is over or not
        only for player moves and if
        GAME OVER: Reset the variables
        @return current score whici is
        white(+ve) or black(-ve) if over
        and MAX_SCORE if not over
        */
        int game_over();

        /**
        Uses Alpha-Beta Search to Iteratively
        traverse the search tree
        */
        void Iterative_AlphaBeta();

        /**
        Save the passed state into the
        Transposition table using hashValue
        @param score of the state
        @param rowto which row the piece moved to
        @param rowfrom which row the piece moved from
        @param colto which column the piece moved to
        @param colfrom which column the piece moved from
        @param height of the tree
        @param alpha bound of the search window
        @param beta bound of the search window
        */
        void saveTT(int score, int rowto, int rowfrom, int colto, int colfrom, int height, int alpha, int beta);

        /**
        Check if the passed state is in
        the transposition table and take
        the necessary actions
        @param height of the search tree
        @param &alpha reference of search
        @param &beta reference of search
        @return index value of the state
        */
        unsigned long long int checkTT(int height, int &alpha, int &beta);

        /**
        Set the search mode of the player

        */
        void set_search_mode(int search_mode);

        /**
        Set a fixed height/depth for the
        iterative search algorithms
        @param height is the height limit
        */
        void set_fixed_height(int height);

        /**
        Set a fixed time for each move
        @param time is the move time limit
        */
        void set_time_limit(double time);

        /**
        Set a fixed time for the entire
        iterative search algorithms
        @param time is the game time
        */
        void set_game_time(double time);

        /**
        Save the principal variation of the search
        @param height of the tree
        @param rowto new row position of piece
        @param colto new column position of piece
        @param rowfrom old row position of piece
        @param colfrom old column position of piece
        */
        void save_pvar(int height, int rowto, int colto, int rowfrom, int colfrom);

        /**
        Print all the moves leading to this
        state - for debugging purposes
        */
        void print_stack();

        unsigned long long int randomInt();

        virtual ~ataxx_state();

    protected:

    private:
        ///Determines who's move it is
        bool white;

        ///size of the current board (4-8)
        int n_board;

        ///information of board pieces
        char board[8][9];
        unsigned long long Wstate;
        unsigned long long Bstate;

        ///Determines if the board has been setup
        bool setup;

        /**
        Direction matrices for piece capture
        This is also used to store history
        */
        int row_d1[8] = {+1,-1,0,0,+1,-1,+1,-1};
        int col_d1[8] = {0,0,+1,-1,-1,+1,+1,-1};

        ///Direction matrices for both one and two-cell moves
        int row_d2[24] = {+1,-1,0,0,+1,-1,+1,-1, 2,2,2,2,2, 1,0,-1, -2,-2,-2,-2,-2, -1,0,1};
        int col_d2[24] = {0,0,+1,-1,-1,+1,+1,-1, 2,1,0,-1,-2, -2,-2,-2, -2,-1,0,1,2, 2,2,2};

        ///Number of pieces on the board
        int white_cnt;
        int black_cnt;
        int empty_cnt;

        ///Game Move History including current board
        int stack_idx;
        char move_stack[4000][3];

        ///Terminating Variables
        int jump_moves;
        int current_score;
        int nodes_evaluated;

        ///Alpha-Beta Search Result Parameters
        int max_height;
        int best_score;
        char PVar[3][2];
        char PVar1[2][2];
        char PVar2[2];
        double betacuts, CBF;

        ///Search Control Parameters
        double time_limit, game_time;
        bool timeout;
        chrono::steady_clock::time_point start, endt, game_start;
        int height_limit;
        int search_mode;
};

#endif // ATAXX_STATE_H
