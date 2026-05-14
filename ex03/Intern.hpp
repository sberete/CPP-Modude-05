#ifndef INTERN_HPP
    #define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const &);
        ~Intern();

        Intern & operator=(Intern const &);

        AForm * makeForm(std::string const & formName, std::string const & target);

        class UnknownFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif