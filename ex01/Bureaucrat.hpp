#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdint.h>
#include "Form.hpp"
class Form;

class Bureaucrat
{
    public:
        Bureaucrat(std::string, int);
        Bureaucrat(Bureaucrat const &);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const &);

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
        Bureaucrat();
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif