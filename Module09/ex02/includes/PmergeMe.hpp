#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <sstream>

class	PmergeMe 
{
	private:
		/* PRIVATE METHODS AND MEMBERS */
		static std::vector<int>					vec_nums;
		static std::vector<std::vector<int> >	vec_of_vecs;
		static std::deque<int>					deq_nums;
		static const int						threshold = 2; // make it a macro instead

		PmergeMe( const PmergeMe& to_copy );
		PmergeMe( void );
		~PmergeMe( void );
		PmergeMe&	operator=( const PmergeMe& to_copy );
		
		static void	convert_to_ints( int argc, char* argv[], int container_flag );
		static void	merge_insert_vector(int length, std::vector<int> container);
		static void	merge_insert_deque();

	public:
		/* PUBLIC METHODS */
		static void		vector_sort( int argc, char* str_nums[]);
		// static std::vector<std::vector<int> >	vector_sort( int argc, char* str_nums[]);
		
		
		static void		deque_sort( int argc, char* str_nums[]);
		static void		clear_vector( void );//reset for another go?
		static void		clear_deque( void );//reset for another go?
		static bool		check_for_good_input( int argc, char* argv[]);
};

#endif

// check input, all integers, positive
// use merge-insert / Ford-Johnson in two diff containers
// print out the before list
// print out sorted list
