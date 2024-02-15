
#include "RPN.hpp"

std::stack<double>	RPN::rpn_stack_;
double				RPN::result_ = 0;

/* CONSTRUCTORS */

RPN::RPN( void ) { /* default constructor */ }

RPN::RPN( const RPN& to_copy ) { *this = to_copy; }
 
/* DESTRUCTOR */

RPN::~RPN( void ) { /* destructor */ }
 
/* OPERATOR OVERLOADS */

RPN&	RPN::operator=( const RPN& to_copy )
{
	if (this != &to_copy) {
		return (*this);
	}
	return (*this);
}

/* CLASS PUBLIC METHODS */

/*
*	Call to validate input characters before attempting calculation
*/
bool	RPN::validateInput( std::string input ) {
	if (input.find_first_not_of("0123456789 +-/*") != std::string::npos) {
		return (false);
	}
	return (true);
}

/*
*	calulates using a stack to manage values and operands.
*	If calculation overflows a double or has incorrect number of digits or operands
*	to preform the calculation an error will be printed or thrown.
*/
bool	RPN::calculate( std::string input ) {

	std::istringstream	ss(input);
	char				to_eval;

	ss >> to_eval;
	while (!ss.eof()) {
		if (ss.fail()) {
			throw (std::runtime_error("string stream failed to convert argument."));
		}
		if (std::isdigit(to_eval)) {
			addToStack_(std::string(1, to_eval));
		}
		else {
			if (RPN::rpn_stack_.size() < 2 ) {
				std::cout << "Error: stack too small for operation" << std::endl;
				return (false);
			}
			doOperation(to_eval);
		}
		ss >> to_eval;
	}
	if (RPN::rpn_stack_.size() != 1) {
		std::cout << "Error: missing operator" << RPN::rpn_stack_.size() << std::endl;
		return (false);
	}
	RPN::result_ = RPN::rpn_stack_.top();
	return (true);
}

double	RPN::getResult( void ) {
	return (RPN::result_);
}

/* CLASS PRIVATE METHODS */

/*
*	converts entry to number and adds to stack
*/
void	RPN::addToStack_(std::string to_eval) {
	std::istringstream	ss(to_eval);
	double					num;

	ss >> num;
	if (ss.fail()) {
		throw (std::runtime_error("string stream failed to convert argument."));
	}
	RPN::rpn_stack_.push(num);
}

/*
*	return value removed from stack
*/
double	RPN::return_popped( void ) {
	double ret_value = RPN::rpn_stack_.top();
	RPN::rpn_stack_.pop();
	return (ret_value);
}

/*
*	uses switch case to call correct operation.
*	pushes result of operation onto stack
*/
void	RPN::doOperation(char operand) {
	double rhs = return_popped();
	double lhs = return_popped();
	double result;
	switch (operand) {
		case '+':
			result = RPN::add_(lhs, rhs);
			break ;
		case '-':
			result = RPN::subtract_(lhs, rhs);
			break ;
		case '/':
			result = RPN::divide_(lhs, rhs);
			break ;
		case '*':
			result = RPN::multiply_(lhs, rhs);
			break ;
		default :
			throw (std::runtime_error("invalid operand found."));
			break ;
	}
	RPN::rpn_stack_.push(result);
}

/*
*	divide checks for zero before performing the operation.
*	Also check for double overflow/ underflow of operation.
*/
double	RPN::divide_(double lhs, double rhs) {
	
	if (rhs == 0) {
		throw (std::runtime_error("cannot divide by zero."));
	}
	long double result = lhs / rhs;
	if (result > std::numeric_limits<double>::max() || result < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs / rhs);
}

/*
*	checks if multiplication will overflow/ underflow a double
*/
double	RPN::multiply_(double lhs, double rhs) {
	
	long double product = lhs * rhs;
	if (product > std::numeric_limits<double>::max() || product < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs * rhs);
}

/*
*	checks for overflow/ underflow of of operation
*/
double	RPN::add_(double lhs, double rhs) {
	
	long double sum = lhs + rhs;
	if (sum > std::numeric_limits<double>::max() || sum < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs + rhs);
}

/*
*	checks for overflow/ underflow of of operation
*/
double	RPN::subtract_(double lhs, double rhs) {
	
	long double difference = lhs - rhs;
	if (difference > std::numeric_limits<double>::max() || difference < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs - rhs);
}
