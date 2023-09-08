#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

class	RobotomyRequestForm 
{
	public:
		RobotomyRequestForm( void );
		RobotomyRequestForm( /*add parameters*/ );
		RobotomyRequestForm( const RobotomyRequestForm& to_copy );

		~RobotomyRequestForm( void );

		RobotomyRequestForm&	operator=( const RobotomyRequestForm& to_copy );

		/* PUBLIC METHODS */
		
	private:
		/* PRIVATE METHODS AND MEMBERS */
};

#endif
