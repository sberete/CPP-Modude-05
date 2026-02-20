#ifndef PRESIDENTIALPARDONFORM_HPP
    #define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdint.h>
#include "AForm.hpp"

class PresidentialPardonForm : public Aform
{
    public:
        PresidentialPardonForm(std::string, int);
        PresidentialPardonForm(PresidentialPardonForm const &);
        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const &);

        std::string const & getName() const;
        int const & getGrade() const;
        void increment();
        void decrement();
        void signForm(Form &);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };


    private:
        std::string _name;
        int _grade;
        void check(int const &);
        PresidentialPardonForm();
};

std::ostream & operator<<( std::ostream & o, PresidentialPardonForm const & rhs );

#endif