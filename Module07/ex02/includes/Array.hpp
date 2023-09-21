#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class	Array 
{
	private:
		/* PRIVATE METHODS AND MEMBERS */
		T	*array_;
		int	size_;

	public:
		Array( void ) : array_(NULL), size_(0) {};

		Array( int n ) { 
			this->array_ = new T[n];
			size_ = n;
		};

		Array( const Array& to_copy ) { 
			this->array_ = NULL;
			*this = to_copy;
		};

		~Array( void ) {
			delete [] this->array_;
		};

		class IndexOutOfBounds : public std::exception {
			public:
				virtual const char*	what( void ) const throw() {
					return ("Index is out of bounds.");
				};
		};

		Array&	operator=( const Array& to_copy ) {
			if (this  != &to_copy) {
				if (this->array_ != NULL)
					delete [] this->array_;
				this->array_ = new T[to_copy.size()];
				this->size_ = to_copy.size();
				for (int i = 0; i < to_copy.size_; i++) {
					this->array_[i] = to_copy.array_[i];
				}
			}
			return (*this);
		};

		T&	operator[]( int index ) const {
			if (index < 0 || index >= this->size_) {
				throw(IndexOutOfBounds());
			}
			return (this->array_[index]);
		};

		int	size( void ) const {
			return (this->size_);
		};
		/* PUBLIC METHODS */
};


#endif
