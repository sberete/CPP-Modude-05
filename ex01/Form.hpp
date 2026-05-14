#ifndef FORM_HPP
    #define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form(std::string const &, int, int);
        Form(Form const &);
        ~Form();

        Form & operator=(Form const &);

        std::string const & getName() const;
        bool    isSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void beSigned(Bureaucrat const &);

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
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
        Form();

};


#endif