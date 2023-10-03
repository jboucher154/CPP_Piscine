
#include "RPN.hpp"

std::stack<double>	RPN::rpn_stack_;

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
bool	RPN::validateInput( std::string input ) {
	if (input.find_first_not_of("0123456789 +-/*") != std::string::npos) {
		return (false);
	}
	return (true);
}

double	RPN::caculate( std::string input ) {
	std::istringstream	ss(input);
	char				to_eval; //if handle negative, then this needs to be a string
	try { //is it better to split the string to an array of chars?
		while (!ss.eof()) {
			ss >> to_eval;
			if (std::isdigit(to_eval)) {
				addToStack_(to_eval);
			}
			else {
				if (RPN::rpn_stack_.size() < 2 ) {
					std::cout << "Error: stack too small for op" << std::endl;
					break ;
					// throw(std::runtime_error("Invalid input"));
				}
				doOperation(to_eval);
			}
			ss >> to_eval;
			if (to_eval != ' ') {
				std::cout << "Error: no space" << std::endl;
				break ;
			}
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

/* CLASS PRIVATE METHODS */

void	RPN::addToStack_(char to_eval) {
	std::istringstream	ss(to_eval);
	double					num;

	ss >> num;
	if (ss.fail()) {
		throw (std::runtime_error("Error: string stream failed to convert argument."));
	}
	RPN::rpn_stack_.push(num);
}

double	RPN::return_popped( void ) {
	double ret_value = RPN::rpn_stack_.top();
	RPN::rpn_stack_.pop();
	return (ret_value);
}

void	RPN::doOperation(char operand) {
	double rhs = return_popped();
	double lhs = return_popped();
	double result;
	switch (operand) {
		case '+':
			result = RPN::add_(lhs, rhs);
			// RPN::rpn_stack_.push(result);
			break ;
		case '-':
			result = RPN::subtract_(lhs, rhs);
			// RPN::rpn_stack_.push(result);
			break ;
		case '/':
			result = RPN::divide_(lhs, rhs);
			// RPN::rpn_stack_.push(result);
			break ;
		case '*':
			result = RPN::multiply_(lhs, rhs);
			// RPN::rpn_stack_.push(result);
			break ;
		default :
			throw (std::runtime_error("Error: invalid operand found."));
			break ;
	}
	RPN::rpn_stack_.push(result);
}

double	RPN::divide_(double lhs, double rhs) {
	if (rhs == 0) {
		throw (std::runtime_error("Error: cannot divide by zero."));
	}
	return (lhs / rhs);
}

//check for overflows in the operations

double	RPN::multiply_(double lhs, double rhs) {
	return (lhs * rhs);
}

double	RPN::add_(double lhs, double rhs) {
	return (lhs + rhs);
}

double	RPN::subtract_(double lhs, double rhs) {
	return (lhs - rhs);
}