#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main(void)
{
	try
	{
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 100);

		Form contract("Contract", 50, 25);

		std::cout << boss.getName() << ", bureaucrat grade " << boss.getGrade() << std::endl;
		std::cout << intern.getName() << ", bureaucrat grade " << intern.getGrade() << std::endl;

		boss.signForm(contract);
		intern.signForm(contract);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
