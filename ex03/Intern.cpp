#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src)
{
    *this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs)
{
    (void)rhs;
    return *this;
}

const char* Intern::UnknownFormException::what() const throw()
{
    return "Intern cannot create unknown form";
}
static AForm *createShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm *createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target)
{
    struct FormPair
    {
        std::string name;
        AForm *(*func)(const std::string &);
    };

    static FormPair forms[] = {
        {"shrubbery creation", &createShrubbery},
        {"robotomy request", &createRobotomy},
        {"presidential pardon", &createPardon}
    };

    for (int i = 0; i < 3; i++)
    {
        if (forms[i].name == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].func(target);
        }
    }

    std::cout << "Error: form name '" << formName << "' does not exist" << std::endl;
    throw Intern::UnknownFormException();
}