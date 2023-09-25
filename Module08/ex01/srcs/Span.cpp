
#include "Span.hpp"


/* CONSTRUCTORS */

Span::Span( void ) { /* default constructor */ }

Span::Span( unsigned int N)
: numbers_(), max_(N)
{ }
Span::Span( const Span& to_copy )
{
	*this = to_copy;
}

/* DESTRUCTOR */

Span::~Span( void )
{ /* destructor */ }

/* OPERATOR OVERLOADS */

Span&	Span::operator=( const Span& to_copy )
{
	if (this != &to_copy)
	{
		this->max_ = to_copy.max_;
		this->numbers_ = to_copy.numbers_; //creates deep copy
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

void	Span::addNumber( int to_add ) throw(std::length_error) {
	if (this->numbers_.size() == this->max_){
		throw(std::length_error("Max length of numbers vector is already met."));
	}
	this->numbers_.push_back(to_add);
}

int		Span::shortestSpan( void ) throw(std::length_error) {
	if (this->numbers_.size() < 2) {
		throw(std::length_error("Not enough data points to determine valid span."));
	}
	sort(this->numbers_.begin(), this->numbers_.end());
	int	min_span = *(this->numbers_.begin() + 1) - *this->numbers_.begin();
	for (std::vector<int>::iterator iter = this->numbers_.begin() + 1; iter != this->numbers_.end() - 1; iter++) {
		int span  =  *(iter + 1) - *iter;
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

int		Span::longestSpan( void ) throw(std::length_error) {
	if (this->numbers_.size() < 2) {
		throw(std::length_error("Not enough data points to determine valid span."));
	}
	int max = *max_element(this->numbers_.begin(), this->numbers_.end());
	int min = *min_element(this->numbers_.begin(), this->numbers_.end());
	return (max - min);
}

void	Span::addManyNumbers(int to_add[], size_t size) throw(std::length_error) {
	if (this->numbers_.size() + size > this->max_) {
		throw(std::length_error("Adding passed array will exceed max length allowed."));
	}
	this->numbers_.insert(this->numbers_.begin(), to_add, to_add + size );
}

/* CLASS PRIVATE METHODS */
