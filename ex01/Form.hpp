#ifndef FORM_HPP
    #define FORM_HPP

#include <string>
#include <iostream>

class Form
{
    public:
        Form();
        Form(Form const &);
        Form(std::string const &, int, int);
        ~Form();
        
        Form & operator=(Form const &);

        std::string const & getName() const;
        bool    isSigned() const;
        int  getGradeToSign() const;
        int  getGradeToExecute() const;

        class GradeTooHighException : public std::exception {};
        class GradeTooLowException : public std::exception {};
        
    private:
        bool _signed;
        std::string const _name;
        int const _gradeToSign;
        int const _gradeToExecute;

};


#endif