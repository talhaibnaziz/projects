#include "ataxx_state.h"
#include <iomanip>
#include <chrono>
#include <stdlib.h>

class ataxx_search
{
	public:
		
		ataxx_search();

		/**
		 * Uses UCB1 variation of Monte Carlo Tree Search to
		 * calculate the best move so far (as per allowed time)
		 * @param state of the board to be modified
		 * @param max_time time limit of the search
		 */
		void MCTS(ataxx_state &state, int max_time);
		
		/**
		 * Recursive MCTS function which randomly selects a move
		 * in each step and backpropagates the result when the end
		 * of the game is reached (updating each node)
		 * @param depth of the tree so far
		 * @return the score of the game of current run
		 */
		int mcts_rec(int depth);
		
		/**
        Uses Alpha-Beta Search to Iteratively
        traverse the search tree
        * @param state of the board to search
        * @param max_height the maximum search depth
        * @param max_time the maximum time for a move
        */
        void Iterative_AlphaBeta(ataxx_state &state, int max_height, int max_time);
		
		/**
        Modifies NegaMax to prune the search
        tree without losing optimality
        @param height of the search tree
        @param alpha lower limit of score
        @param beta upper limit of score
        @return score of plater to move
        */
        int AlphaBeta(int height, int alpha, int beta);

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
	
        virtual ~ataxx_search();
	
	private:
		///The ataxx_state object used to perform all operations
		ataxx_state *state;
		
		///Fixed variables for search
		static const unsigned long long max_tt_size = 5000011;
		static const int max_score = 70;
		static const int r_p = 7; ///Determines randomness of MCTS
		
		///Search Parameters
		int best_score, search_height, best_rowto, best_colto, best_rowfrom, best_colfrom;
		long long nodes_evaluated, TTQ, TTF;
		double time_limit, game_limit;
		bool timeout;
		chrono::steady_clock::time_point start, endt;
		chrono::duration<double> elapsed_seconds;
		
		///MCTS Simulation state variables
		vector <int> moves;
		
		///MCTS node structure
		struct node{
			int move_played;
			///Black nodes keep win probability of white nodes
			double games_played;
			double games_won;
			int parent;
			int possible_moves;
			vector <int> successors;
		};
		///The container for all the nodes of the MCTS search tree
		vector <node> node_list;
		///Index of the last node in node_list
		int node_idx;
		
		///Transposition Table variables
		vector <unsigned long long> TTWstate, TTBstate;
		vector <int> TTscore, TTheight, TTmove, TTgc;
		vector <char> TTfvalue;
		vector <unsigned char> TTwhite;
		int gc;
		enum FLAG{UPPERBOUND = 1, EXACT = 2, LOWERBOUND = 3};
};
