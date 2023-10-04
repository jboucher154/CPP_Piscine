
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

bool	RPN::validateInput( std::string input ) {
	if (input.find_first_not_of("0123456789 +-/*") != std::string::npos) {
		return (false);
	}
	return (true);
}

bool	RPN::calculate( std::string input ) {

	std::istringstream	ss(input);
	char				to_eval;

	ss >> to_eval;
	while (!ss.eof() && !ss.fail()) {
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
/* destructive stack printing */
// std::cout << "stack contents" << std::endl;//
// for (int i = RPN::rpn_stack_.size(); i > 0; i--) {//
// 	std::cout << RPN::rpn_stack_.top() << std::endl;
// 	RPN::rpn_stack_.pop();
// }
// std::cout << "'" << to_eval << "'" << std::endl;

double	RPN::getResult( void ) {
	return (RPN::result_);
}

/* CLASS PRIVATE METHODS */

void	RPN::addToStack_(std::string to_eval) {
	std::istringstream	ss(to_eval);
	double					num;

	ss >> num;
	if (ss.fail()) {
		throw (std::runtime_error("string stream failed to convert argument."));
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

double	RPN::divide_(double lhs, double rhs) {
	// std::cout << "hi from divide " << std::endl;
	if (rhs == 0) {
		throw (std::runtime_error("cannot divide by zero."));
	}
	return (lhs / rhs);
}

//check for overflows in the operations

double	RPN::multiply_(double lhs, double rhs) {
	// std::cout << "hi from multiply " << std::endl;
	long double product = lhs * rhs;
	if (product > std::numeric_limits<double>::max() || product < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs * rhs);
}

double	RPN::add_(double lhs, double rhs) {
	// std::cout << "hi from add " << std::endl;
	long double sum = lhs + rhs;
	if (sum > std::numeric_limits<double>::max() || sum < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs + rhs);
}

double	RPN::subtract_(double lhs, double rhs) {
	// std::cout << "hi from subtract " << std::endl;
	long double difference = lhs - rhs;
	if (difference > std::numeric_limits<double>::max() || difference < -std::numeric_limits<double>::max()) {
		throw (std::runtime_error("overflowed double data type"));
	}
	return (lhs - rhs);
}