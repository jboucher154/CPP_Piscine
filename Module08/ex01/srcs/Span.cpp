
#include "Span.hpp"
#include <iostream>//

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

long int		Span::shortestSpan( void ) throw(std::length_error) {
	if (this->numbers_.size() < 2) {
		throw(std::length_error("Not enough data points to determine valid span."));
	}
	sort(this->numbers_.begin(), this->numbers_.end());
	long int	min_span = std::abs(static_cast<long int>(*(this->numbers_.begin() + 1)) - static_cast<long int>(*this->numbers_.begin()));
	std::cout << "INITIAL MIN " << min_span << std::endl;
	for (std::vector<int>::iterator iter = this->numbers_.begin() + 1; iter != this->numbers_.end() - 1; iter++) {
		long int span  = std::abs(static_cast<long int>(*(iter + 1)) - static_cast<long int>(*iter));
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

long int		Span::longestSpan( void ) throw(std::length_error) {
	if (this->numbers_.size() < 2) {
		throw(std::length_error("Not enough data points to determine valid span."));
	}
	long int max = *max_element(this->numbers_.begin(), this->numbers_.end());
	long int min = *min_element(this->numbers_.begin(), this->numbers_.end());
	return (max - min);
}

void	Span::addManyNumbers(int to_add[], size_t size) throw(std::length_error) {
	if (this->numbers_.size() + size > this->max_) {
		throw(std::length_error("Adding passed array will exceed max length allowed."));
	}
	this->numbers_.insert(this->numbers_.begin()  + this->numbers_.size(), to_add, to_add + size );
}

/* CLASS PRIVATE METHODS */
