#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "===== BUREAUCRATS =====\n";

    Bureaucrat high("Alice", 1);
    Bureaucrat mid("Bob", 50);
    Bureaucrat low("Charlie", 150);

    std::cout << high << std::endl;
    std::cout << mid << std::endl;
    std::cout << low << std::endl;

    std::cout << "\n===== INTERN TEST =====\n";

    Intern someRandomIntern;

    AForm* forms[4];

    forms[0] = someRandomIntern.makeForm("shrubbery creation", "garden");
    forms[1] = someRandomIntern.makeForm("robotomy request", "Marvin");
    forms[2] = someRandomIntern.makeForm("presidential pardon", "Ford");

    // test erreur volontaire
    try
    {
        forms[3] = someRandomIntern.makeForm("unknown form", "FAIL");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Intern error caught: " << e.what() << std::endl;
        forms[3] = NULL;
    }

    Bureaucrat* bureaucrats[] = { &high, &mid, &low };

    for (int i = 0; i < 3; i++)
    {
        AForm* f = forms[i];

        std::cout << "\n============================\n";
        std::cout << "TEST FORM: " << f->getName() << std::endl;
        std::cout << *f << std::endl;

        for (int j = 0; j < 3; j++)
        {
            Bureaucrat* b = bureaucrats[j];

            std::cout << "\n--- " << b->getName()
                      << " (grade " << b->getGrade() << ") ---\n";

            try
            {
                b->signForm(*f);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Sign error: " << e.what() << std::endl;
            }

            try
            {
                b->executeForm(*f);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Exec error: " << e.what() << std::endl;
            }
        }

        delete f;
    }

    std::cout << "\n===== END TESTS =====\n";

    return 0;
}