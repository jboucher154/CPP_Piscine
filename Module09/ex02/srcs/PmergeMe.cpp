
#include "PmergeMe.hpp"

 

/* CONSTRUCTORS */

PmergeMe::PmergeMe( void ) { /* default constructor */ }

PmergeMe::PmergeMe( const PmergeMe& to_copy ) {
	*this = to_copy;
}
 
/* DESTRUCTOR */

PmergeMe::~PmergeMe( void ) { /* destructor */ }
 
/* OPERATOR OVERLOADS */

PmergeMe&	PmergeMe::operator=( const PmergeMe& to_copy ) {
	if (this != &to_copy) {
		return (*this);
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

bool		PmergeMe::check_for_good_input( int argc, char* argv[]) {

	long double entry;

	for (int i = 0; i < argc; i++) {
		std::istringstream ss(argv[i]);
		ss >> entry;
		if (ss.fail() || entry < 0 || entry > std::numeric_limits<int>::max()) {
			return (false); //could print out specific failure message here...
		}
	}
	return (true);
}

void	PmergeMe::clear_vector( void ) { //clear?

	PmergeMe::vec_nums.erase(PmergeMe::vec_nums.begin(), PmergeMe::vec_nums.end());
}

void	PmergeMe::clear_deque( void ) { //clear?

	PmergeMe::deq_nums.erase(PmergeMe::deq_nums.begin(), PmergeMe::deq_nums.end());
}

void	PmergeMe::vector_sort( int argc, char* str_nums[]) {

	PmergeMe::convert_to_ints(argc, str_nums, 1);

}

void	PmergeMe::deque_sort( int argc, char* str_nums[]) {

	PmergeMe::convert_to_ints(argc, str_nums, 0);

}

/* CLASS PRIVATE METHODS */

static void	copy_vector_portion( std::vector<int> copy_to, std::vector<int>::iterator start, std::vector<int>::iterator end) {

	while (start != end) {
		copy_to.push_back(*start);
		start++;
	}
}

static void	copy_deque_portion( std::deque<int> copy_to, std::deque<int>::iterator start, std::deque<int>::iterator end) {

	while (start != end) {
		copy_to.push_back(*start);
		start++;
	}
}

//break into pairs
void	PmergeMe::merge_insert_vector(int length, std::vector<int> container) {
	
	std::vector<int> lhs;
	std::vector<int> rhs;

	if (length <= PmergeMe::threshold) {
		//need to add to a vector all the sets of two... then sort those by the max element
		PmergeMe::vec_of_vecs.push_back(container);
	}
	else {
		copy_vector_portion(lhs, container.begin(), container.begin() + length / 2); //get first half of vec
		copy_vector_portion(rhs, container.begin() + length / 2 , container.end()); //get second shalf of vec
		PmergeMe::merge_insert_vector(lhs.size(), lhs);
		PmergeMe::merge_insert_vector(rhs.size(), rhs);
	}
	//insert rhs into lhs
}

void	PmergeMe::merge_insert_deque() {

}

void	PmergeMe::convert_to_ints( int argc, char* argv[], int container_flag ) {

	int entry;

	for (int i = 0; i < argc; i++) {
		std::istringstream ss(argv[i]);
		ss >> entry;
		if (ss.fail() ) {
			throw ( std::runtime_error("Error converting input to int.")); //could print out specific failure message here...
		}
		if (container_flag == 1) { // macro?
			PmergeMe::vec_nums.push_back(entry);
		} 
		else {
			PmergeMe::deq_nums.push_back(entry);			
		}
	}
}