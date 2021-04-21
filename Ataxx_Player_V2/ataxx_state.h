#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <random>
#include <cmath>

using namespace std;

class ataxx_state
{
    public:
    
        ataxx_state();

        ///Sets the dimensions of the board
        void set_size();
        
        /**
         * Sets the pieces in the
         * board before starting the game
        */
        void set_state();
        
        /**
         * This function prints the contents
         * of the current board state
        */
        void show_state();
        
        /**
         * Evaluate the current state according to
         * a defined evaluation criteria
         * @return evaluated score
         */
        int evaluate_state();
        
        /**
         * Sets the turn to white or black
         * depending on the input parameter
         * @param turn = true for white, o/w false
        */
        void set_turn(bool turn);
        
        /**
        Moves a piece from one square to another
        as long as it is a legal move
        * 
        */
        void move_piece(const string &input);

        /**
        Perform the move according to the row
        and column parameters
        */
        void do_move(int rowfrom, int colfrom, int rowto, int colto);

        /**
        Returns back to the previous state
        VERY OPTIMIZED and cannot work with
        a greater board size
        */
        void undo_move();
        
        /**
        checks if the game is over or not
        only for player moves and if
        GAME OVER: Reset the variables
        @return current score whici is
        white(+ve) or black(-ve) if over
        and INT_MAX if not over
        */
        int game_over();
        
        /**
         * Converts the move information into a compressed
         * form and saves it in the passed integer as follows:
         * right most 8 bits => move to, left 8 bits to it => move from
         * the next 8 bits to the left => capture information
         * @param c_state is the compressed move
         * @param rowto is the final move row
         * @param colto is the final move column
         * @param rowfrom is the initial move row
         * @param colfrom is the initial move column
         * @param capture is the piece capture info
         */
        void compress_move(int &c_state, int &rowto, int &colto, int &rowfrom, int &colfrom, int &capture);

		/**
         * Converts the compressed move information into a decompressed
         * form and saves it in the passed move variables as follows:
         * right most 8 bits => move to, left 8 bits to it => move from
         * the next 8 bits to the left => capture information
         * @param c_state is the compressed move
         * @param rowto is the final move row
         * @param colto is the final move column
         * @param rowfrom is the initial move row
         * @param colfrom is the initial move column
         * @param capture is the piece capture info
         */
        void decompress_move(int &c_state, int &rowto, int &colto, int &rowfrom, int &colfrom, int &capture);

		/**
		 * Check if any move is possible for a piece
		 * @param forWhite check for white pieces
		 * @param forBlack check for black pieces
		 * @return the number of possible moves
		 */
		int check_moves(bool forWhite, bool forBlack);
		
		///A function to generate large random numbers
		unsigned long long int randomInt();
		
		/**
		 * From here on, all the functions are get functions
		 * to access the variables of the class by an outside
		 * class (like ataxx_search)
		 */
		bool get_white();
		unsigned long long get_hash();
		 
		///Storing some values in a Transposition Table
		void TTstore(unsigned long long idx, vector <unsigned char> &TTwhite, vector <unsigned long long> &TTWstate, vector <unsigned long long> &TTBstate);
		
		///Comparing some values in a Transposition Table
		bool TTcompare(unsigned long long idx, vector <unsigned char> &TTwhite, vector <unsigned long long> &TTWstate, vector <unsigned long long> &TTBstate);
		
		///PUBLICLY AVAILABLE CLASS VARIABLES
		///Fixed values
		static const int max_grid = 8;
		static const int min_grid = 4;
		static const int max_moves = 24;
		static const int max_move_stack = 1000;
		
		/**
        Direction matrices for piece capture
        This is also used to store history
        */
        int row_d1[8] = {+1,-1,0,0,+1,-1,+1,-1};
        int col_d1[8] = {0,0,+1,-1,-1,+1,+1,-1};

        ///Direction matrices for both one and two-cell moves
        int row_d2[24] = {+1,-1,0,0,+1,-1,+1,-1, 2,2,2,2,2, 1,0,-1, -2,-2,-2,-2,-2, -1,0,1};
        int col_d2[24] = {0,0,+1,-1,-1,+1,+1,-1, 2,1,0,-1,-2, -2,-2,-2, -2,-1,0,1,2, 2,2,2};
		
		///Board grid values
		string board[max_grid];
		int board_size, jump_moves;
		
        virtual ~ataxx_state();

    protected:

    private:
		
		///Information of board pieces
        int white_cnt, black_cnt, empty_cnt;
        unsigned long long Wstate, Bstate;
		
		///Determines if the board has been setup
        bool setup;
        
        ///Determines who's move it is
        bool white;
        
        ///Game Move History (move locations and piece capture)
        int stack_idx;
        vector <int> move_stack;
        
        ///Zobrist table and hash values
        vector <unsigned long long> zobristTableW[max_grid];
        vector <unsigned long long> zobristTableB[max_grid];
        unsigned long long hashValue;
};
