#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <sstream>
# include <tuple>
# include <iterator>
# include "Color.hpp"
# include <deque>
# include <cassert>

# define NO_VALUE -1
# define VECTOR_SORT 0
# define DEQUE_SORT 1
class	PmergeMe 
{
	private:
		PmergeMe( void );
		PmergeMe( const PmergeMe& to_copy );
		PmergeMe&	operator=( const PmergeMe& to_copy );

		/* PRIVATE METHODS AND MEMBERS */
		int									container_flag;
		std::string							print_color;
		std::vector<int>					initial_nums_v_;
		std::vector<std::tuple<int, int> >	pairs_v_;
		std::vector<int>					main_chain_v_;

		std::deque<int>						initial_nums_d_;
		std::deque<std::tuple<int, int> >	pairs_d_;
		std::deque<int>						main_chain_d_;
		
		void	convert_to_ints( int argc, char* argv[]);
		void	split_into_pairs_v_( void );
		void	split_into_pairs_d_( void );
		void	sort_pairs_by_highest_in_pair_v_( size_t left_index, size_t right_index );
		void	sort_pairs_by_highest_in_pair_d_( size_t left_index, size_t right_index );
		void	merge_pairs_v_( size_t left_index, size_t right_index, size_t mid );
		void	merge_pairs_d_( size_t left_index, size_t right_index, size_t mid );
		void	move_pair_max_to_final_container( void );
		void	insert_pair_mins_into_final_container_v_( void );
		void	insert_pair_mins_into_final_container_d_( void );
		size_t	calculate_jacobsthal_number( std::vector<size_t>& jacobsthal_record, size_t n);
		void	sort_subsection_into_main_chain_v_( size_t pairs_index, size_t chunk_size );
		void	sort_subsection_into_main_chain_d_( size_t pairs_index, size_t chunk_size );
		void	binary_insert_value_int_main_chain_v_( int to_insert, int upper_bound_value );
		void	binary_insert_value_int_main_chain_d_( int to_insert, int upper_bound_value );
	
	public:
		/* PUBLIC METHODS */
		PmergeMe( int num_to_sort, char* str_num_array[], int container_flag );
		~PmergeMe( void );

		void					sort( void );
		const std::vector<int>&	get_main_chain_v( void ) const;
		const std::vector<int>&	get_intial_nums_v( void ) const;
		const std::deque<int>&	get_main_chain_d( void ) const;
		const std::deque<int>&	get_intial_nums_d( void ) const;
		int						get_container_flag( void ) const;
		const std::string&		get_print_color( void ) const;
		int						get_size_sorted( void ) const;
	
};

std::ostream&	operator<<( std::ostream& output_stream, const PmergeMe& to_print );

#endif



// check input, all integers, positive
// use merge-insert / Ford-Johnson in two diff containers
// print out the before list
// print out sorted list


// /*
// *	Step 1
// */
// void	PmergeMe::split_into_pairs_v_(int length, std::vector<int> container)
// {	
// 	std::vector<int> lhs = {};
// 	std::vector<int> rhs = {};

// 	if (length <= PAIR_LIMIT) { //will always be 2
// 		if (length == 1)
// 			this->pairs_v.push_back(std::make_tuple(NO_VALUE, container[0]));
// 		else if (container[0] < container[1])
// 			this->pairs_v.push_back(std::make_tuple(container[1], container[0]));
// 		else
// 			this->pairs_v.push_back(std::make_tuple(container[1], container[0]));
// 		return ;
// 	}
// 	else {
// 		std::copy(container.begin(),  container.begin() + length / 2, std::back_inserter(lhs));
// 		std::copy(container.begin() + length / 2 , container.end(), std::back_inserter(rhs));
// 		split_into_pairs_v_(lhs.size(), lhs);
// 		split_into_pairs_v_(rhs.size(), rhs);
// 	}
// }