#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <tuple>
# include <iterator>

# define NO_VALUE -1
class	PmergeMe 
{
	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe& to_copy );
		PmergeMe&	operator=( const PmergeMe& to_copy );

		/* PRIVATE METHODS AND MEMBERS */
		std::vector<int>					initial_nums;
		std::vector<std::tuple<int, int> >	pairs;
		std::vector<std::tuple<int, int> >	sorted_pairs;
		std::vector<int>					main_chain;
		
		void	convert_to_ints( int argc, char* argv[]);
		void	split_into_pairs( void );
		void	sort_pairs_by_highest_in_pair( size_t left_index, size_t right_index );
		void	merge_pairs( size_t left_index, size_t right_index, size_t mid );
		void	move_pair_max_to_final_container( void );
		void	insert_pair_mins_into_final_container( void );
		size_t	calculate_jacobsthal_number( std::vector<size_t>& jacobsthal_record, size_t n);
		void	sort_subsection_into_main_chain( size_t pairs_index, size_t chunk_size );
		void	binary_insert_value_int_main_chain( int to_insert, int upper_bound_value );
	
	public:
		/* PUBLIC METHODS */
		PmergeMe( int argc, char* argv[] );
		~PmergeMe( void );

		void	sort( void );
	
};

#endif

// check input, all integers, positive
// use merge-insert / Ford-Johnson in two diff containers
// print out the before list
// print out sorted list


// /*
// *	Step 1
// */
// void	PmergeMe::split_into_pairs(int length, std::vector<int> container)
// {	
// 	std::vector<int> lhs = {};
// 	std::vector<int> rhs = {};

// 	if (length <= PAIR_LIMIT) { //will always be 2
// 		if (length == 1)
// 			this->pairs.push_back(std::make_tuple(NO_VALUE, container[0]));
// 		else if (container[0] < container[1])
// 			this->pairs.push_back(std::make_tuple(container[1], container[0]));
// 		else
// 			this->pairs.push_back(std::make_tuple(container[1], container[0]));
// 		return ;
// 	}
// 	else {
// 		std::copy(container.begin(),  container.begin() + length / 2, std::back_inserter(lhs));
// 		std::copy(container.begin() + length / 2 , container.end(), std::back_inserter(rhs));
// 		split_into_pairs(lhs.size(), lhs);
// 		split_into_pairs(rhs.size(), rhs);
// 	}
// }