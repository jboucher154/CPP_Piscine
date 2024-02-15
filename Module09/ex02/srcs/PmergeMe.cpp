#include "PmergeMe.hpp"

/* CONSTRUCTORS */

//private
PmergeMe::PmergeMe( void ) { /* default constructor */ }
//private
PmergeMe::PmergeMe( const PmergeMe& to_copy )
{
	*this = to_copy;
}

/*
*	Step 0.0 Constructor that sets up int array to be sorted.
*/
PmergeMe::PmergeMe( int num_to_sort, char* str_num_array[], int container_flag )
: container_flag(container_flag), print_color(COLOR_GREEN)
{
	convert_to_ints(num_to_sort, str_num_array);
}
 
/* DESTRUCTOR */

PmergeMe::~PmergeMe( void ) { /* destructor */ }
 
/* OPERATOR OVERLOADS */

/*
*	private cannot be copied.
*/
PmergeMe&	PmergeMe::operator=( const PmergeMe& to_copy )
{
	if (this != &to_copy) {
		return (*this);
	}
	return (*this);
}

/*! \brief outstream overload prints unsorted and sorted lists
*	
*	@param output_stream @b std::ostreatm& stream to send print to
*	@param to_print @b const @b PmergeMe& object to print
*	@return @b output_stream passed as param
*/
std::ostream&	operator<<( std::ostream& output_stream, const PmergeMe& to_print )
{
	output_stream << COLOR_CYAN << "Before: ";
	if (to_print.get_container_flag() == VECTOR_SORT) {
		for (int num : to_print.get_intial_nums_v()) {
			output_stream << num << " "; 
		}
		output_stream << std::endl;
		output_stream << COLOR_BRIGHT_BLUE << "After:  ";
		for (int num : to_print.get_main_chain_v()) {
			output_stream << num << " "; 
		}
	}
	else {
		for (int num : to_print.get_intial_nums_d()) {
			output_stream << num << " "; 
		}
		output_stream << std::endl;
		output_stream << COLOR_BRIGHT_BLUE << "After:  ";
		for (int num : to_print.get_main_chain_d()) {
			output_stream << num << " "; 
		}
	}
	output_stream << COLOR_RESET << std::endl;
	return output_stream;
}

/* CLASS PUBLIC METHODS */

/*! \brief Driver of the sorting steps
*
*	Step 0.2 - Driver of the steps
*	Will use either vector or deque sorting set of methods.
*	The object print color will be set to red if the final list is not sorted.
*/
void	PmergeMe::sort( void )
{
	if ( this->container_flag == VECTOR_SORT) {
		split_into_pairs_v_();
		sort_pairs_by_highest_in_pair_v_(0, this->pairs_v_.size() - 1);
		move_pair_max_to_final_container();
		insert_pair_mins_into_final_container_v_();
		assert(std::is_sorted(this->main_chain_v_.begin(), this->main_chain_v_.end()) == true);
		if (std::is_sorted(this->main_chain_v_.begin(), this->main_chain_v_.end()) == false)
			this->print_color = COLOR_RED;
	}
	else {
		split_into_pairs_d_();
		sort_pairs_by_highest_in_pair_d_(0, this->pairs_d_.size() - 1);
		move_pair_max_to_final_container();
		insert_pair_mins_into_final_container_d_();
		assert(std::is_sorted(this->main_chain_d_.begin(), this->main_chain_d_.end()) == true);
		if (std::is_sorted(this->main_chain_d_.begin(), this->main_chain_d_.end()) == false)
			this->print_color = COLOR_RED;
	}
}

/*! \brief getter for number of elements sorted
*
*/
int	PmergeMe::get_size_sorted( void ) const
{
	if (this->container_flag == VECTOR_SORT)
		return this->initial_nums_v_.size();
	else
		return this->initial_nums_d_.size();
}

/*! \brief getter for vector of sorted ints
*
*/
const std::vector<int>&	PmergeMe::get_main_chain_v( void ) const
{
	return this->main_chain_v_;
}

/*! \brief getter for vector unsorted ints
*
*/
const std::vector<int>&	PmergeMe::get_intial_nums_v( void ) const
{
	return this->initial_nums_v_;
}

/*! \brief getter for deque of sorted ints
*
*/
const std::deque<int>&	PmergeMe::get_main_chain_d( void ) const
{
	return this->main_chain_d_;
}

/*! \brief getter for deque of unsorted ints
*
*/
const std::deque<int>&	PmergeMe::get_intial_nums_d( void ) const
{
	return this->initial_nums_d_;
}

/*! \brief getter for container flag indicating vector or deque
*
*/
int	PmergeMe::get_container_flag( void ) const
{
	return this->container_flag;
}

/*! \brief getter for print color of object
*
*	Green print color indicates that sorted list is indeed sorted.
*	Red print color indicates that sorted list is NOT actually sorted.
*/
const std::string&		PmergeMe::get_print_color( void ) const
{
	return this->print_color;
}

/* CLASS PRIVATE METHODS */

/*! \brief uses jacobsthal numbers to partition and sort subsections into main chain
*	Step 4.1
*	At end of function all values should be sorted into final sorted vector
*/
void	PmergeMe::insert_pair_mins_into_final_container_v_( void )
{
	std::vector<size_t> jacobsthal_numbers = {0, 1};
	size_t	jacobsthal_index = 3;
	size_t	pairs_index = 1;

	this->main_chain_v_.insert(this->main_chain_v_.begin(), std::get<1>(this->pairs_v_[0]));
	while (pairs_index < this->pairs_v_.size()) {
		size_t end_of_chunk_index = calculate_jacobsthal_number(jacobsthal_numbers, jacobsthal_index) - 1;
		sort_subsection_into_main_chain_v_(pairs_index, end_of_chunk_index);
		jacobsthal_index++;
		pairs_index = end_of_chunk_index + 1;
	}
	assert(this->main_chain_v_.size() == this->initial_nums_v_.size());
}

/*! \brief uses jacobsthal numbers to partition and sort subsections into main chain
*	Step 4.1
*	At end of function all values should be sorted into final sorted deque
*/
void	PmergeMe::insert_pair_mins_into_final_container_d_( void )
{
	std::vector<size_t> jacobsthal_numbers = {0, 1};
	size_t	jacobsthal_index = 3;
	size_t	pairs_index = 1;

	this->main_chain_d_.push_front(std::get<1>(this->pairs_d_[0]));
	while (pairs_index < this->pairs_d_.size()) {
		size_t end_of_chunk_index = calculate_jacobsthal_number(jacobsthal_numbers, jacobsthal_index) - 1;
		sort_subsection_into_main_chain_d_(pairs_index, end_of_chunk_index);
		jacobsthal_index++;
		pairs_index = end_of_chunk_index + 1;
	}
	assert(this->main_chain_d_.size() == this->initial_nums_d_.size());
}

/*! \brief calculates and creates history of jacobsthal numbers in the vector passed
*	Step 4.2
*	generate jacobsthal number using history to improve efficiency
*	History must be seeded with values {0, 1};
*/
size_t	PmergeMe::calculate_jacobsthal_number( std::vector<size_t>& jacobsthal_record, size_t n)
{
	if (n < jacobsthal_record.size()) {
		return jacobsthal_record[n];
	}
	else if (jacobsthal_record.size() - 1 > n - 2) {
		jacobsthal_record.push_back(jacobsthal_record[n - 1] + 2 * jacobsthal_record[n - 2]);
		return jacobsthal_record.back();
	}
	else {
		return calculate_jacobsthal_number(jacobsthal_record, n - 1) + 2 * 
			calculate_jacobsthal_number(jacobsthal_record, n - 2);
	}
}

/*! \brief sends values from chunk between the indexes passed (inclusive) for binary search insertion
*	Step 4.3
*	insert values from index given through above step to binary insert, 
*	bounded by begining of container and value of <0> element of the pair
*/
void	PmergeMe::sort_subsection_into_main_chain_v_( size_t pairs_index, size_t end_of_chunk_index )
{
	if (end_of_chunk_index >= this->pairs_v_.size())
		end_of_chunk_index = this->pairs_v_.size() - 1;
	for (; end_of_chunk_index >= pairs_index; --end_of_chunk_index) {
		binary_insert_value_int_main_chain_v_(std::get<1>(this->pairs_v_[end_of_chunk_index]), 
			std::get<0>(this->pairs_v_[end_of_chunk_index]));
	}
}

/*! \brief sends values from chunk between the indexes passed (inclusive) for binary search insertion
*	Step 4.3
*	insert values from index given through above step to binary insert, 
*	bounded by begining of container and value of <0> element of the pair
*/
void	PmergeMe::sort_subsection_into_main_chain_d_( size_t pairs_index, size_t end_of_chunk_index )
{
	if (end_of_chunk_index >= this->pairs_d_.size())
		end_of_chunk_index = this->pairs_d_.size() - 1;
	for (; end_of_chunk_index >= pairs_index; --end_of_chunk_index) {
		binary_insert_value_int_main_chain_d_(std::get<1>(this->pairs_d_[end_of_chunk_index]), 
			std::get<0>(this->pairs_d_[end_of_chunk_index]));
	}
}

/*! \brief use binary search to insert value into the main chain
*	Step 4.4
*	Uses the max value paired with the value to insert as the upper bound within the main_chain
*	A value paired with NO_VALUE as its max will have upper bound set as last element
*/
void	PmergeMe::binary_insert_value_int_main_chain_v_( int to_insert, int upper_bound_value )
{
	auto upper_bound_it = std::find(this->main_chain_v_.begin(), this->main_chain_v_.end(), upper_bound_value);
	size_t upper_bound_index;
	size_t midpoint_index = 0;
	size_t lower_bound_index = 0;
	
	upper_bound_it == this->main_chain_v_.end() ? upper_bound_index = this->main_chain_v_.size() - 1 : 
		upper_bound_index = upper_bound_it - this->main_chain_v_.begin();

	if (this->main_chain_v_[upper_bound_index] < to_insert) {
		this->main_chain_v_.push_back(to_insert);
		return;
	}
	while (true) {
		midpoint_index = lower_bound_index + (upper_bound_index - lower_bound_index) / 2;
		int value_at_midpoint = this->main_chain_v_[midpoint_index];
		if (lower_bound_index == midpoint_index || value_at_midpoint == to_insert) {
			if (to_insert > this->main_chain_v_[lower_bound_index])
				midpoint_index++;
			this->main_chain_v_.insert(this->main_chain_v_.begin() + midpoint_index, to_insert);
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

/*! \brief uses binary search to insert value into sorted deque
*
*	Step 4.4
*	Uses the max value paired with the value to insert as the upper bound within the main_chain
*	A value paired with NO_VALUE as its max will have upper bound set as last element
*
*/
void	PmergeMe::binary_insert_value_int_main_chain_d_( int to_insert, int upper_bound_value )
{
	auto upper_bound_it = std::find(this->main_chain_d_.begin(), this->main_chain_d_.end(), upper_bound_value);
	size_t upper_bound_index;
	size_t midpoint_index = 0;
	size_t lower_bound_index = 0;
	
	upper_bound_it == this->main_chain_d_.end() ? upper_bound_index = this->main_chain_d_.size() - 1 : 
		upper_bound_index = upper_bound_it - this->main_chain_d_.begin();

	if (this->main_chain_d_[upper_bound_index] < to_insert) {
		this->main_chain_d_.push_back(to_insert);
		return;
	}
	while (true) {
		midpoint_index = lower_bound_index + (upper_bound_index - lower_bound_index) / 2;
		int value_at_midpoint = this->main_chain_d_[midpoint_index];
		if (lower_bound_index == midpoint_index || value_at_midpoint == to_insert) {
			if (to_insert > this->main_chain_d_[lower_bound_index])
				midpoint_index++;
			this->main_chain_d_.insert(this->main_chain_d_.begin() + midpoint_index, to_insert);
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

/*! \brief moves max between pairs to main_chain of appropriate container
*	Step 3
*	Moves max of pairs, excluding any NO_VALUE entries
*/
void	PmergeMe::move_pair_max_to_final_container( void )
{
	if (this->container_flag == VECTOR_SORT) {
		for (std::tuple<int, int> pair : this->pairs_v_) {
			if (std::get<0>(pair) != NO_VALUE)
				this->main_chain_v_.push_back(std::get<0>(pair));
		}
	}
	else {
		for (std::tuple<int, int> pair : this->pairs_d_) {
			if (std::get<0>(pair) != NO_VALUE)
				this->main_chain_d_.push_back(std::get<0>(pair));
		}
	}
}

/*! \brief recursively splits the pairs and send to merge function
*	Step 2.1
*	Recursively split then merge once left index is == to right then end of 
*	splitting is reached, down to size 1 size is 1 or less will skip the if 
*	statment, okay as size of one is already sorted.
*/
void	PmergeMe::sort_pairs_by_highest_in_pair_v_( size_t left_index, size_t right_index )
{
	if (left_index < right_index) {
		size_t split_point = left_index + (right_index - left_index) / 2;
		sort_pairs_by_highest_in_pair_v_(left_index, split_point);
		sort_pairs_by_highest_in_pair_v_(split_point + 1, right_index);
		merge_pairs_v_(left_index, right_index, split_point);
	}
}

/*! \brief recursively splits the pairs and send to merge function
*	Step 2.1
*	Recursively split then merge once left index is == to right then end of 
*	splitting is reached, down to size 1 size is 1 or less will skip the if 
*	statment, okay as size of one is already sorted.
*/
void	PmergeMe::sort_pairs_by_highest_in_pair_d_( size_t left_index, size_t right_index )
{
	if (left_index < right_index) {
		size_t split_point = left_index + (right_index - left_index) / 2;
		sort_pairs_by_highest_in_pair_d_(left_index, split_point);
		sort_pairs_by_highest_in_pair_d_(split_point + 1, right_index);
		merge_pairs_d_(left_index, right_index, split_point);
	}
}

/*! \brief merges left and right subsection values then overwrites that section of the pairs vector
*	Step 2.2
*	Uses left, right and mid point to manage the areas for sorting, refencing the origional vector.
*	Left and right subsections are already sorted within themselves.
*	Tuples from each subsection are pushed to the temp vector in sorted order.
*	Once one subsection is exhauseted, the other will have its remaining values pushed to the temp vector.
*	Temp vector is copied the pairs vector, overwriting the previous values
*/
void	PmergeMe::merge_pairs_v_( size_t left_index, size_t right_index, size_t mid )
{
	std::vector<std::tuple<int, int> > temp;
	size_t left_lead = left_index;
	size_t right_lead = mid + 1;
	size_t right_bound = right_index;

	while (right_lead <= right_bound && left_lead <= mid) {
		if (static_cast<unsigned int>(std::get<0>(this->pairs_v_[left_lead])) < static_cast<unsigned int>(std::get<0>(this->pairs_v_[right_lead]))){
			temp.push_back(this->pairs_v_[left_lead]);
			left_lead++;
		}
		else {
			temp.push_back(this->pairs_v_[right_lead]);
			right_lead++;
		}
	}
	while (right_lead <= right_bound) {
		temp.push_back(this->pairs_v_[right_lead]);
		right_lead++;
	}
	while (left_lead <= mid) {
		temp.push_back(this->pairs_v_[left_lead]);
		left_lead++;
	}
	std::copy(temp.begin(), temp.end(), this->pairs_v_.begin() + left_index);
}

/*! \brief merges left and right subsection values then overwrites that section of the pairs deque
*	Step 2.2
*	Uses left, right and mid point to manage the areas for sorting, refencing the origional deque.
*	Left and right subsections are already sorted within themselves.
*	Tuples from each subsection are pushed to the temp deque in sorted order.
*	Once one subsection is exhauseted, the other will have its remaining values pushed to the temp deque.
*	Temp deque is copied the pairs deque, overwriting the previous values
*/
void	PmergeMe::merge_pairs_d_( size_t left_index, size_t right_index, size_t mid )
{
	std::deque<std::tuple<int, int> > temp;
	size_t left_lead = left_index;
	size_t right_lead = mid + 1;
	size_t right_bound = right_index;

	while (right_lead <= right_bound && left_lead <= mid) {
		if (static_cast<unsigned int>(std::get<0>(this->pairs_d_[left_lead])) < static_cast<unsigned int>(std::get<0>(this->pairs_d_[right_lead]))){
			temp.push_back(this->pairs_d_[left_lead]);
			left_lead++;
		}
		else {
			temp.push_back(this->pairs_d_[right_lead]);
			right_lead++;
		}
	}
	while (right_lead <= right_bound) {
		temp.push_back(this->pairs_d_[right_lead]);
		right_lead++;
	}
	while (left_lead <= mid) {
		temp.push_back(this->pairs_d_[left_lead]);
		left_lead++;
	}
	std::copy(temp.begin(), temp.end(), this->pairs_d_.begin() + left_index);
}

/*! \brief creates tuple pairs from intial vector of ints
*	
*	Step 1
* 	Creates tuples from neigboring pairs, placing the max value in location <0>,
*	and min value in location <1>. The last value in odd number of ints
*	is given NO_VALUE (-1) in the max position.
*/
void	PmergeMe::split_into_pairs_v_( void )
{	
	size_t container_index = 0;
	size_t container_size = this->initial_nums_v_.size();

	while (container_index < container_size) {
		if (container_index + 1 == container_size)
			this->pairs_v_.push_back(std::make_tuple(NO_VALUE, this->initial_nums_v_[container_index]));
		else if (this->initial_nums_v_[container_index] < this->initial_nums_v_[container_index + 1])
			this->pairs_v_.push_back(std::make_tuple(this->initial_nums_v_[container_index + 1], this->initial_nums_v_[container_index]));
		else
			this->pairs_v_.push_back(std::make_tuple(this->initial_nums_v_[container_index], this->initial_nums_v_[container_index + 1]));
		container_index += 2;
	}
}
/*! \brief creates tuple pairs from intial deque of ints
*	
*	Step 1
* 	Creates tuples from neigboring pairs, placing the max value in location <0>,
*	and min value in location <1>. The last value in odd number of ints
*	is given NO_VALUE (-1) in the max position.
*/
void	PmergeMe::split_into_pairs_d_( void )
{
	size_t container_index = 0;
	size_t container_size = this->initial_nums_d_.size();

	while (container_index < container_size) {
		if (container_index + 1 == container_size)
			this->pairs_d_.push_back(std::make_tuple(NO_VALUE, this->initial_nums_d_[container_index]));
		else if (this->initial_nums_d_[container_index] < this->initial_nums_d_[container_index + 1])
			this->pairs_d_.push_back(std::make_tuple(this->initial_nums_d_[container_index + 1], this->initial_nums_d_[container_index]));
		else
			this->pairs_d_.push_back(std::make_tuple(this->initial_nums_d_[container_index], this->initial_nums_d_[container_index + 1]));
		container_index += 2;
	}
}

/*! \brief converts strings to ints and adds to correct container
*	Step 0.1
*	Called by constructor, sets up intial container of ints to be sorted.
*/
void	PmergeMe::convert_to_ints( int argc, char* argv[])
{
	std::string	str_entry;
	int entry;

	for (int i = 0; i < argc; i++) {
		std::istringstream ss(argv[i]);
		if (ss.fail() ) {
			throw ( std::runtime_error("stringstream error converting input to int."));
		}
		while (std::getline(ss, str_entry, ' ')) {
			entry = std::stoi(str_entry);
			if (this->container_flag == VECTOR_SORT)
				this->initial_nums_v_.push_back(entry);
			else
				this->initial_nums_d_.push_back(entry);
		}
	}
}
