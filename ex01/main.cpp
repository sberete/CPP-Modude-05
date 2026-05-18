#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "===== VALID CREATION =====" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 42);
		Form		form("Contract", 50, 25);

		std::cout << bob << std::endl;
		std::cout << form << std::endl;

		bob.signForm(form);

		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== SIGN FAIL =====" << std::endl;
	try
	{
		Bureaucrat	john("John", 100);
		Form		form("Secret Form", 50, 25);

		std::cout << john << std::endl;
		std::cout << form << std::endl;

		john.signForm(form);

		std::cout << form << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INVALID BUREAUCRAT =====" << std::endl;
	try
	{
		Bureaucrat	tooHigh("TooHigh", 0);
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat	tooLow("TooLow", 151);
		std::cout << tooLow << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "===== INVALID FORM =====" << std::endl;
	try
	{
		Form	invalidHigh("InvalidHigh", 0, 50);
		std::cout << invalidHigh << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form	invalidLow("InvalidLow", 50, 151);
		std::cout << invalidLow << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
