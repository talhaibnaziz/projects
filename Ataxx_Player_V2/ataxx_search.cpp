#include "ataxx_search.h"
using namespace std;

ataxx_search::ataxx_search()
{
	///Initialize Transposition Tables for Alpha-Beta
	gc = 1;
	for(int i=0; i<(int)max_tt_size; i++)
	{
		TTWstate.push_back(0ULL);
		TTBstate.push_back(0ULL);
		TTscore.push_back(0);
		TTheight.push_back(0);
		TTmove.push_back(0);
		TTgc.push_back(0);
		TTfvalue.push_back('0');
		if(i%8==0) TTwhite.push_back(0);
	}
	///extra push for remaining entry
	if((int)max_tt_size % 8) TTwhite.push_back(0);
	
	///Initialize node list for MCTS
	node N;
	N.games_played = 0.0; N.games_won = 0.0;
	N.move_played = -1; N.parent = -1;
	for(int i=0; i<(int)max_tt_size; i++)
		node_list.push_back(N);
}

void ataxx_search::MCTS(ataxx_state& state, int max_time)
{
	this->state = &state;
	start = chrono::steady_clock::now();
	timeout = false;
	int iter = 0, score = 0, search_idx = 0, next_node = 0, s_size;
	int rowto, colto, rowfrom, colfrom, dummy = 0, best_successor = 0;
	nodes_evaluated = 0ULL;
	double best_stats = 0.0;
	
	///Clearing the node list and creating first node
	node_idx = 0;
	node_list[node_idx].successors.clear();
	node_list[node_idx].parent = -1;
	node_list[node_idx].games_played = 0.0;
	node_list[node_idx].games_won = 0.0;
	node_list[node_idx].possible_moves = state.check_moves(state.get_white(), !state.get_white());
	node_list[node_idx].successors.clear();
	
	///Until time or memory runs out
	while(!timeout && iter<(int)max_tt_size)
	{
		iter++;
		//~ cout<<"ITERATION START: "<<iter<<endl;
		/**
		 * MCTS Step 1: Selection
		 * Select the best move so far until a node
		 * with unvisited children is reached
		 */
		search_idx = 0;
		///As long as the current node has been fully explored
		//~ int test = 0;
		while((int)node_list[search_idx].successors.size() == node_list[search_idx].possible_moves)
		{
			///Game is over
			if(state.game_over() != INT_MAX)	break;
			///No moves for this player
			if(state.check_moves(state.get_white(), !state.get_white())==0)	break;
			
			best_successor = 0;
			best_stats = -10000.0;
			s_size = node_list[search_idx].successors.size();
			/**
			 * Finding successor with best win probability (exploitation)
			 * while also exploring other nodes (UCB1)
			 */
			for(int i=0; i<s_size; i++)
			{
				next_node = node_list[search_idx].successors[i];
				double stats = node_list[next_node].games_won/node_list[next_node].games_played;
				stats += sqrt( 2.0*log(node_list[search_idx].games_played)/node_list[next_node].games_played );
				//~ cout<<"parent games: "<<node_list[search_idx].games_played<<" log: "<<log(node_list[search_idx].games_played)<<endl;
				//~ cout<<"Successor serial: "<<i<<" Games Played: "<<node_list[next_node].games_played;
				//~ cout<<" Games Won: "<<node_list[next_node].games_won<<" Stats: "<<stats<<endl;
				if(stats > best_stats)
				{
					best_stats = stats;
					best_successor = next_node;
				}
			}
			
			///Selecting best successor and performing required move
			search_idx = best_successor;
			state.decompress_move(node_list[search_idx].move_played, rowto, colto, rowfrom, colfrom, dummy);
			state.do_move(rowfrom, colfrom, rowto, colto);
			//~ cout<<"Best Successor: "<<best_successor<<" Best stats: "<<best_stats;
			//~ cout<<" Best Move: "<<rowfrom<<" "<<colfrom<<" "<<rowto<<" "<<colto<<endl;
		}
		//~ state.show_state();
		
		/**
		 * MCTS Step 2: Expansion
		 * Find the stats for the next random move and
		 * create a new node with the new move
		 */
		int end_score = state.game_over();
		///Creating new node in the tree (if not end of game)
		if(end_score == INT_MAX)
		{
			node_idx++;
			///New node added (but empty)
			node_list[search_idx].successors.push_back(node_idx);
			node_list[node_idx].parent = search_idx;
			node_list[node_idx].games_played = 0.0;
			node_list[node_idx].games_won = 0.0;
			node_list[node_idx].possible_moves = 0;
			node_list[node_idx].successors.clear();
			
			///Adding a new unexplored child (filling New node)
			s_size = node_list[search_idx].successors.size();
			int moves_visited = 0;
			
			for(int i=0; i<state.board_size; i++)
			{
				for(int j=0; j<state.board_size; j++)
				{
					if(state.board[i][j]=='x' || state.board[i][j]=='e') continue;
					for(int ii=0; ii<state.max_moves; ii++)
					{
						rowto = i+state.row_d2[ii];
						colto = j+state.col_d2[ii];
						if(rowto<0 || rowto>=state.board_size || colto<0 || colto>=state.board_size) continue;
						if((state.get_white() && state.board[i][j]=='w') && state.board[rowto][colto]=='e')
							moves_visited++;
						if((!state.get_white() && state.board[i][j]=='b') && state.board[rowto][colto]=='e')
							moves_visited++;
						///This move has not been performed yet
						if(moves_visited == s_size)
						{
							rowfrom = i;
							colfrom = j;
							//~ cout<<"New move: "<<rowfrom<<" "<<colfrom<<" "<<rowto<<" "<<colto<<endl;
							break;
						}
					}
					if(moves_visited == s_size)	break;
				}
				if(moves_visited == s_size) break;
			}
			///No moves left for this player, force a "pass"
			if(s_size > node_list[search_idx].possible_moves)
			{
				rowfrom = 0;
				colfrom = 0;
				rowto = 0;
				colto = 0;
			}
			
			state.compress_move(node_list[node_idx].move_played, rowto, colto, rowfrom, colfrom, dummy);
			state.do_move(rowfrom, colfrom, rowto, colto);
			node_list[node_idx].possible_moves = state.check_moves(state.get_white(), !state.get_white());
			search_idx = node_idx;
			//~ cout<<"Parent moves: "<<s_size<<" New child move: "<<rowfrom<<" "<<colfrom<<" "<<rowto<<" "<<colto<<endl;
		}
		
		/**
		 * MCTS Step 3: Simulation
		 */
		if(end_score == INT_MAX)
			score = mcts_rec(0);
		
		/**
		 * MCTS Step 4: Backpropagation
		 */
		next_node = search_idx;
		search_idx = node_list[search_idx].parent;
		
		///Until ROOT of tree
		while(search_idx != -1)
		{
			/**
			 * Update tree only if game is not over, if game is over
			 * this node is the leaf node and has already been visited
			 * once, updating tree will create duplicate data
			 */
			if(end_score == INT_MAX)
			{
				node_list[next_node].games_played += 1.0;
				/**
				 * As white nodes keep win probability of black nodes
				 * and vice versa, score calculation is done in reverse
				 */
				if((state.get_white() && score < 0) || (!state.get_white() && score > 0))
					node_list[next_node].games_won += 1.0;
				else if(score == 0)	node_list[next_node].games_won += 0.5;
			}
			///Changing state to parent state
			state.undo_move();
			next_node = search_idx;
			search_idx = node_list[search_idx].parent;
		}
		///Extra processing for ROOT
		if(end_score == INT_MAX)
		{
			node_list[next_node].games_played += 1.0;
			if((state.get_white() && score < 0) || (!state.get_white() && score > 0))
				node_list[next_node].games_won += 1.0;
			else if(score == 0)	node_list[next_node].games_won += 0.5;
		}
		
		endt = chrono::steady_clock::now();
		elapsed_seconds = endt - start;
		
		//~ cout<<"ITERATION END: "<<iter<<" Score: "<<score<<" Nodes: "<< nodes_evaluated<<endl;
		if(elapsed_seconds.count() > max_time)	timeout = true;
	}
	
	///Performing the best move
	//~ cout<<"All moves:";
	s_size = node_list[0].successors.size();
	best_stats = -1000.0;
	for(int i=0; i<s_size; i++)
	{
		next_node = node_list[0].successors[i];
		double stats = node_list[next_node].games_won/node_list[next_node].games_played;
		state.decompress_move(node_list[next_node].move_played, best_rowto, best_colto, best_rowfrom, best_colfrom, dummy);
		//~ cout<<"  "<<best_rowfrom<<" "<<best_colfrom<<" "<<best_rowto<<" "<<best_colto;
		//~ if(i%7==0)	cout<<endl;
		if(stats > best_stats)
		{
			best_stats = stats;
			best_successor = next_node;
		}
	}
	cout<<endl;
	state.decompress_move(node_list[best_successor].move_played, best_rowto, best_colto, best_rowfrom, best_colfrom, dummy);
	cout<<"RESULTS:"<<endl;
	cout<<"Iterations: "<<iter<<" Nodes Visited: "<<nodes_evaluated<<endl;
	
	string moveString;
	moveString.push_back((char)(best_colfrom+'a'));
	moveString.push_back((char)('1'-(best_rowfrom-(state.board_size-1))));
	moveString.push_back((char)(best_colto+'a'));
	moveString.push_back((char)('1'-(best_rowto-(state.board_size-1))));
	(state).move_piece("m"+moveString);
	cout<<"move: "<<moveString<<endl;
}

int ataxx_search::mcts_rec(int depth)
{
	nodes_evaluated++;
	///If end of game is reached, return score
	int score = (*state).game_over();
	if(score != INT_MAX)
	{
		///Always return (white_cnt - black_cnt)
		if((*state).get_white()) return score;
		else return -score;
	}
	
	///All possible move generation
	moves.clear();
	int i, j, ii, rowto, colto, c_move, dummy = 0;
	int clone_limit = -1;
	for(i=0; i<(*state).board_size; i++)
	{
		for(j=0; j<(*state).board_size; j++)
		{
			if(((*state).get_white() && (*state).board[i][j]=='w') || (!(*state).get_white() && (*state).board[i][j]=='b'))
			{
				for(ii=0; ii<(*state).max_moves; ii++)
				{
					rowto = i+(*state).row_d2[ii];
					colto = j+(*state).col_d2[ii];

					if(rowto<0 || rowto>=(*state).board_size || colto<0 || colto>=(*state).board_size)
						continue;
					if((*state).board[rowto][colto]=='e')
					{
						if(clone_limit == -1 && ii>=8)	clone_limit = moves.size();
						(*state).compress_move(c_move, rowto, colto, i, j, dummy);
						moves.push_back(c_move);
					}
				}
			}
		}
	}
	///Selecting random move from available moves
	if(moves.size())
	{
		///3/4 probability of choosing a clone move (if possible)
		if(clone_limit > 0 && rand()%r_p)	ii = rand() % clone_limit;
		else    ii = rand() % (int)moves.size();
		(*state).decompress_move(moves[ii], rowto, colto, i, j, dummy);
	}
	else
	{
		i = 0; j = 0;
		rowto = 0; colto = 0;
	}
	(*state).do_move(i, j, rowto, colto);
	score = mcts_rec(depth+1);
	(*state).undo_move();
	
	return score;
}

void ataxx_search::Iterative_AlphaBeta(ataxx_state& state, int max_height, int max_time)
{
	bool pass; timeout = false;
	this->state = &state; search_height = 1;
	max_height = 100;
	
	if(state.get_white()) pass = state.check_moves(true, false)?false:true;
	else pass = state.check_moves(false, true)?false:true;
	start = chrono::steady_clock::now();
	time_limit = max_time;
	string moveString;
	best_rowto=0, best_colto=0, best_rowfrom=0, best_colfrom=0;
	
	cout<<"DDD "<<"Time "<<setw(12)<<"Nodes"<<" "<<setw(12)<<"TTQ"<<" ";
	cout<<setw(12)<<"TTF"<<" Val"<<endl;
	if(pass)	cout<<"No Moves Available!"<<endl;
	while(!pass && search_height <= max_height)
	{
		nodes_evaluated = 0LL; TTQ = 0LL; TTF = 0LL;
		best_score = AlphaBeta(search_height, -max_score, max_score);
		
		if(timeout)	break;
		cout<<setw(3)<<search_height<<" ";
		endt = chrono::steady_clock::now();
		elapsed_seconds = endt - start;
		cout<<setw(4)<<fixed<<setprecision(1)<<elapsed_seconds.count()<<" ";
		cout<<setw(12)<<nodes_evaluated;
		cout<<" "<<setw(12)<<TTQ<<" "<<setw(12)<<TTF<<" "<<setw(3)<<best_score<<endl;
		search_height++;
		//(state).show_state();
	}
	gc++; ///Generation counter for automatic TT clearance
	moveString.push_back((char)(best_colfrom+'a'));
	moveString.push_back((char)('1'-(best_rowfrom-(state.board_size-1))));
	moveString.push_back((char)(best_colto+'a'));
	moveString.push_back((char)('1'-(best_rowto-(state.board_size-1))));
	(state).move_piece("m"+moveString);
	cout<<"move: "<<moveString<<endl;
}

int ataxx_search::AlphaBeta(int height, int alpha, int beta)
{
	nodes_evaluated++;
	int score = (*state).game_over();
	if(score!=INT_MAX)	return score;
	
	if(nodes_evaluated % 1000 == 0)
	{
		endt = chrono::steady_clock::now();
		elapsed_seconds = endt - start;
		if(!timeout && elapsed_seconds.count() > time_limit)
		{
			timeout = true;
			cout<<"TIMEOUT"<<endl;
		}
	}
	
	///Evaluation Function is set as piece difference
	if(!height || timeout)	return (*state).evaluate_state();
	
	///Check Transposition Table Entries
	unsigned long long idx = -1ULL;
	idx = checkTT(height, alpha, beta);
	if(idx!=-1ULL && alpha >= beta)	return TTscore[idx];
	
	///Normal case handling
	int rowto, colto, i, j, x, al = alpha;
	int dummy;
	score = -max_score;
	bool pass = true;
	int local_colto=0, local_colfrom=0, local_rowto=0, local_rowfrom=0;
	int test_rowto=0, test_rowfrom=0, test_colto=0, test_colfrom=0;
	///Move with best heuristic according to TT
	if(idx != -1ULL)
	{
		(*state).decompress_move(TTmove[idx], rowto, colto, i, j, dummy);
		pass = false;
		(*state).do_move(i, j, rowto, colto);
		x = -AlphaBeta(height-1, -beta, -al);
		if(score < x)
		{
			score = x;
			local_rowto = rowto;
			local_colto = colto;
			local_rowfrom = i;
			local_colfrom = j;
			if(score > al)	al = score;
			///Beta bound check
			if(score >= beta)
			{
				(*state).undo_move();
				saveTT(score, local_rowto, local_rowfrom, local_colto, local_colfrom, height, alpha, beta);
				return score;
			}
		}
		(*state).undo_move();
		test_rowto = rowto; test_colto = colto; test_rowfrom = i; test_colfrom = j;
	}
	///All possible move generation and best move selection
	for(i=0; i<(*state).board_size; i++)
	{
		for(j=0; j<(*state).board_size; j++)
		{
			if(((*state).get_white() && (*state).board[i][j]=='w') || (!(*state).get_white() && (*state).board[i][j]=='b'))
			{
				for(int ii=0; ii<(*state).max_moves; ii++)
				{
					if(timeout)	return score;
					rowto = i+(*state).row_d2[ii];
					colto = j+(*state).col_d2[ii];
    
					if(rowto<0 || rowto>=(*state).board_size || colto<0 || colto>=(*state).board_size)
						continue;
					if(idx != -1ULL && i==test_rowfrom && j==test_colfrom && rowto==test_rowto && colto==test_colto)
						continue;
					if((*state).board[rowto][colto]=='e')
					{
						pass = false;
						(*state).do_move(i, j, rowto, colto);
						x = -AlphaBeta(height-1, -beta, -al);
						if(score < x)
						{
							score = x;
							local_rowto = rowto;
							local_colto = colto;
							local_rowfrom = i;
							local_colfrom = j;
							if(score > al) al = score;
							///Beta bound check
							if(score >= beta)
							{
								(*state).undo_move();
								saveTT(score, local_rowto, local_rowfrom, local_colto, local_colfrom, height, alpha, beta);
								return score;
							}
						}
						(*state).undo_move();
					}
				}
			}
		}
	}
	if(pass)
	{
		(*state).do_move(0, 0, 0, 0);
		x = -AlphaBeta(height-1, -beta, -al);
		if(score < x)
		{
			score = x;
			local_rowto = 0;
			local_colto = 0;
			local_rowfrom = 0;
			local_colfrom = 0;
			if(score > al) al = score;
			///Beta bound check
			if(score >= beta)
			{
				(*state).undo_move();
				saveTT(score, 0, 0, 0, 0, height, alpha, beta);
				return score;
			}
		}
		(*state).undo_move();
	}
	if(height==search_height)
	{
		best_rowto = local_rowto;
		best_colto = local_colto;
		best_rowfrom = local_rowfrom;
		best_colfrom = local_colfrom;
	}
    
    saveTT(score, local_rowto, local_rowfrom, local_colto, local_colfrom, height, alpha, beta);
	return score;
}

void ataxx_search::saveTT(int score, int rowto, int rowfrom, int colto, int colfrom, int height, int alpha, int beta)
{
	unsigned long long idx;
	int dummy = 0;
	idx = (*state).get_hash() % max_tt_size;
	/**
	 * The same state can be reached with lesser moves, so ignore
	 * the search sub-tree under the selected state (TT state is better)
	 */
	if(TTgc[idx]==gc && TTheight[idx]>height) return;
	
	TTscore[idx] = score;
	(*state).compress_move(TTmove[idx], rowto, colto, rowfrom, colfrom, dummy);
	TTheight[idx] = height;
	TTgc[idx] = gc;
	
	///Storing state variables
	(*state).TTstore(idx, TTwhite, TTWstate, TTBstate);
	
	///Storing bound according to Alpha-Beta Theorem
	if(score <= alpha) TTfvalue[idx] = UPPERBOUND;
	else if(score >= beta) TTfvalue[idx] = LOWERBOUND;
	else TTfvalue[idx] = EXACT;
}

unsigned long long int ataxx_search::checkTT(int height, int &alpha, int &beta)
{
	unsigned long long idx;
    idx = (*state).get_hash() % max_tt_size;
    TTQ++;
    if(TTgc[idx]==gc && (*state).TTcompare(idx, TTwhite, TTWstate, TTBstate))
	{
		TTF++;
		///Trusted value, modify search window
		if(TTheight[idx]>=height)
		{
			if(TTfvalue[idx] == EXACT)
			{
				alpha = TTscore[idx];
				beta = TTscore[idx]+1;
			}
			else if(TTfvalue[idx] == LOWERBOUND) alpha = max(alpha, TTscore[idx]);
			else if(TTfvalue[idx] == UPPERBOUND) beta = min(beta, TTscore[idx]);
		}
		///Regardless of whether value is trusted, send idx for best heuristic
		return idx;
	}
	return -1ULL;
}


ataxx_search::~ataxx_search()
{

}
