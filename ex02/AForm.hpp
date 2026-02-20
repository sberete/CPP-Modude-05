#ifndef AFORM_HPP
    #define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const &, int, int);
        AForm(AForm const &);
        ~AForm();

        AForm & operator=(AForm const &);

        std::string const & getName() const;
        bool    isSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void beSigned(Bureaucrat const &);

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()  = 0; 
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()  = 0;
        };

    protected:
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
        
    private:    
        AForm();

};


#endif