#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat high("Alice", 1);    // super grade
    Bureaucrat mid("Bob", 50);      // moyen
    Bureaucrat low("Charlie", 150); // faible grade

    AForm* forms[3];
    forms[0] = new ShrubberyCreationForm("garden");
    forms[1] = new RobotomyRequestForm("Marvin");
    forms[2] = new PresidentialPardonForm("Ford");

    Bureaucrat* bureaucrats[3];
    bureaucrats[0] = &high;
    bureaucrats[1] = &mid;
    bureaucrats[2] = &low;

    for (int i = 0; i < 3; ++i)
    {
        AForm* f = forms[i];
        std::cout << "\n=== Testing " << f->getName() << " ===\n";
        std::cout << *f << "\n";
        for (int j = 0; j < 3; ++j)
        {
            Bureaucrat* b = bureaucrats[j];
            std::cout << "\nTrying to sign with " << b->getName()
                      << " (grade " << b->getGrade() << ")\n";
            try
            {
                f->beSigned(*b);
                std::cout << "Signed successfully: " << *f << "\n";
            }
            catch(const std::exception& e)
            {
                std::cerr << "Cannot sign: " << e.what() << "\n";
            }

            std::cout << "Trying to execute with " << b->getName() << "\n";
            try
            {
                f->execute(*b);
            }
            catch(const std::exception& e)
            {
                std::cerr << "Cannot execute: " << e.what() << "\n";
            }
        }
        delete f;
    }
    std::cout << "\nAll tests finished.\n";
    return 0;
}