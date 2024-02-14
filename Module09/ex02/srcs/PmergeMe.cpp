#include "PmergeMe.hpp"

/* CONSTRUCTORS */
//private
PmergeMe::PmergeMe( void ) { /* default constructor */ }
//private
PmergeMe::PmergeMe( const PmergeMe& to_copy )
{
	*this = to_copy;
}

PmergeMe::PmergeMe( int argc, char* argv[] )
{
	convert_to_ints(argc, argv);
}
 
/* DESTRUCTOR */

PmergeMe::~PmergeMe( void ) { /* destructor */ }
 
/* OPERATOR OVERLOADS */
//private
PmergeMe&	PmergeMe::operator=( const PmergeMe& to_copy )
{
	if (this != &to_copy) {
		return (*this);
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

/*
*	Step 0.2 - Driver of the steps
*/
void	PmergeMe::sort( void )
{
	split_into_pairs();
	std::cout << "PAIRS HAVE BEEN CREATED: " << std::endl;
	for (std::tuple<int, int> pair : this->pairs) {
		std::cout << "pair: " << std::get<0>(pair) << ", " << std::get<1>(pair) << std::endl; 
	}
	sort_pairs_by_highest_in_pair(0, this->pairs.size() - 1);
	std::cout << "PAIRS SHOULD BE SORTED BY HIGHEST VALUE: " << std::endl;
	for (std::tuple<int, int> pair : this->pairs) {
		std::cout << "pair: " << std::get<0>(pair) << ", " << std::get<1>(pair) << std::endl; 
	}
	move_pair_max_to_final_container();
	std::cout << "Highest values from pairs should be in sorted order in main chain: " << std::endl;
	for (int num : this->main_chain) {
		std::cout << num << " "; 
	}
	std::cout << std::endl;
	// //sort <1> elements into main_chain using binary search, chunking with jacobsthal numbers
	insert_pair_mins_into_final_container();
	std::cout << "All entries should be sorted into main chain except -1: " << std::endl;
	for (int num : this->main_chain) {
		std::cout << num << " "; 
	}
	std::cout << std::endl;
}

/* CLASS PRIVATE METHODS */

/*
*	Step 4.1
*/
void	PmergeMe::insert_pair_mins_into_final_container( void )
{
	std::vector<size_t> jacobsthal_numbers = {0, 1};
	size_t	jacobsthal_index = 1;
	size_t	pairs_index = 1;
	//push the 0 pair to front of container main chain
	this->main_chain.insert(this->main_chain.begin(), std::get<1>(this->pairs[0]));
	//move through rest of pairs using jacobsthal numbers as index
	while (pairs_index < this->pairs.size()) { //<=??
		//calculate needed jacobsthal
		int chunk_size = calculate_jacobsthal_number(jacobsthal_numbers, jacobsthal_index);
		sort_subsection_into_main_chain(pairs_index, chunk_size);
		jacobsthal_index++;
		pairs_index += chunk_size;
	}
}

/*
*	Step 4.2
*	generate jacobsthal number using history to improve efficiency
*/
size_t	PmergeMe::calculate_jacobsthal_number( std::vector<size_t>& jacobsthal_record, size_t n)
{
	if (n < jacobsthal_record.size()) {
		return jacobsthal_record[n];
	}
	else if (jacobsthal_record.size() >= n - 2) {
		jacobsthal_record.push_back(jacobsthal_record[n -1] + 2 * jacobsthal_record[n - 2]);
		return jacobsthal_record.back();
	}
	else {
		return calculate_jacobsthal_number(jacobsthal_record, n - 1) + 2 * 
			calculate_jacobsthal_number(jacobsthal_record, n - 2);
	}
}

/*
*	Step 4.3
*	insert values from index given through above step to binary insert, 
*	bounded by begining of container and value of <0> element of hte pair
*/
void	PmergeMe::sort_subsection_into_main_chain( size_t pairs_index, size_t chunk_size )
{
	size_t end_of_chunk_index = chunk_size - 1 + pairs_index;

	if (end_of_chunk_index >= this->pairs.size())
		end_of_chunk_index = this->pairs.size() - 1;
	for (; end_of_chunk_index >= pairs_index; --end_of_chunk_index) {
		binary_insert_value_int_main_chain(std::get<1>(this->pairs[end_of_chunk_index]), 
			std::get<0>(this->pairs[end_of_chunk_index]));
	}
}

/*
*	Step 4.4
*	use binary search to insert value into the main chain
*/
void	PmergeMe::binary_insert_value_int_main_chain( int to_insert, int upper_bound_value )
{
	auto upper_bound_it = std::find(this->main_chain.begin(), this->main_chain.end(), upper_bound_value);
	size_t upper_bound_index;
	size_t midpoint_index = 0;
	size_t lower_bound_index = 0;
	
	upper_bound_it == this->main_chain.end() ? upper_bound_index = this->main_chain.size() - 1 : 
		upper_bound_index = upper_bound_it - this->main_chain.begin();

	if (this->main_chain[upper_bound_index] < to_insert) {
		this->main_chain.push_back(to_insert);
		return;
	}
	while (true) {
		midpoint_index = lower_bound_index + (upper_bound_index - lower_bound_index) / 2;
		int value_at_midpoint = this->main_chain[midpoint_index];
		if (lower_bound_index == midpoint_index || value_at_midpoint == to_insert) {
			if (to_insert > this->main_chain[lower_bound_index])
				midpoint_index++;
			this->main_chain.insert(this->main_chain.begin() + midpoint_index, to_insert);
			break ;
		}
		else if (to_insert < value_at_midpoint) {
			upper_bound_index = midpoint_index;
		}
		else if (to_insert > value_at_midpoint) {
			lower_bound_index = midpoint_index;
		}
	}
}

/*
*	Step 3
*/
void	PmergeMe::move_pair_max_to_final_container( void )
{
	for (std::tuple<int, int> pair : this->pairs) {
		if (std::get<0>(pair) != NO_VALUE)
			this->main_chain.push_back(std::get<0>(pair));
	}
}

/*
*	Step 2.1
*	split until min size, then merge
*	once left index is == to right then end of splitting is reached, down to size 1
*	size is 1 or less will skip the if statment, okay as size of one is already sorted.
*/
void	PmergeMe::sort_pairs_by_highest_in_pair( size_t left_index, size_t right_index )
{
	if (left_index < right_index) {
		size_t split_point = left_index + (right_index - left_index) / 2;
		sort_pairs_by_highest_in_pair(left_index, split_point);
		sort_pairs_by_highest_in_pair(split_point + 1, right_index);
		merge_pairs(left_index, right_index, split_point);
	}
}

/*
	Step 2.2
	use left, right and split point to manage the areas for sorting
	left to split needs one iterator
	split +1 to right needs another
	merge right into left until gone
	left and right sides are already sorted within themselves.
	go intull iterator for right side reaches the right index.
	- temp container to store sorted pairs, copy to overwrite the section in the pairs container
*/
void	PmergeMe::merge_pairs( size_t left_index, size_t right_index, size_t mid )
{
	std::vector<std::tuple<int, int> > temp;
	size_t left_lead = left_index;
	size_t right_lead = mid + 1;
	size_t right_bound = right_index;

	while (right_lead <= right_bound && left_lead <= mid) {
		if (static_cast<unsigned int>(std::get<0>(this->pairs[left_lead])) < static_cast<unsigned int>(std::get<0>(this->pairs[right_lead]))){
			temp.push_back(this->pairs[left_lead]);
			left_lead++;
		}
		else {
			temp.push_back(this->pairs[right_lead]);
			right_lead++;
		}
	}
	while (right_lead < right_bound) { //< only?
		temp.push_back(this->pairs[right_lead]);
		right_lead++;
	}
	while (left_lead <= mid) { //<=
		temp.push_back(this->pairs[left_lead]);
		left_lead++;
	}
	std::copy(temp.begin(), temp.end(), this->pairs.begin() + left_index);
}

/*
*	Step 1
*/
void	PmergeMe::split_into_pairs( void )
{	
	size_t container_index = 0;
	size_t container_size = this->initial_nums.size();

	while (container_index < container_size) {
		if (container_index + 1 == container_size)
			this->pairs.push_back(std::make_tuple(NO_VALUE, this->initial_nums[container_index]));
		else if (this->initial_nums[container_index] < this->initial_nums[container_index + 1])
			this->pairs.push_back(std::make_tuple(this->initial_nums[container_index + 1], this->initial_nums[container_index]));
		else
			this->pairs.push_back(std::make_tuple(this->initial_nums[container_index], this->initial_nums[container_index + 1]));
		container_index += 2;
	}
}

/*
*	Step 0.1
*	Called by constructor, sets up intial vector of ints to be sorted.
*/
void	PmergeMe::convert_to_ints( int argc, char* argv[])
{
	int entry;

	for (int i = 0; i < argc; i++) {
		std::istringstream ss(argv[i]);
		ss >> entry;
		if (ss.fail() ) {
			throw ( std::runtime_error("Error converting input to int."));
		}
		this->initial_nums.push_back(entry);
	}
}
