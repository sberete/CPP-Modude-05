#ifndef BUREAUCRAT_HPP
    #define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdint.h>

class Bureaucrat
{
    public:
        Bureaucrat(std::string, uint8_t);
        Bureaucrat(Bureaucrat const &);
        ~Bureaucrat();

        Bureaucrat & operator=(Bureaucrat const &);

        std::string const & getName() const;
        int const & getGrade() const;
        void increment();
        void decrement();

        class GradeTooHighException : public std::exception {};
        class GradeTooLowException : public std::exception {};

    private:
        std::string _name;
        uint8_t _grade;
        Bureaucrat();
};

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif