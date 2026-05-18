#ifndef AFORM_HPP
    #define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
    public:
        AForm(std::string const &, int, int);
        AForm(AForm const &);
        virtual ~AForm();

        AForm & operator=(AForm const &);

        std::string const & getName() const;
        bool    isSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;
        void beSigned(Bureaucrat const &);
        void execute(Bureaucrat const & executor) const;

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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw(); 
        };

    protected:
        AForm();
        virtual void executeAction() const = 0;
        std::string const _name;
        bool _signed;
        int const _gradeToSign;
        int const _gradeToExecute;
};

std::ostream & operator<<( std::ostream &, AForm const &);


#endif