#include "Form.hpp"

Form::Form(std::string const & name, int gradeToSign, int gradeToExecute)
    : _name(name),
      _signed(false),
      _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(Form const & src)
    : _name(src._name),
      _signed(src._signed),
      _gradeToSign(src._gradeToSign),
      _gradeToExecute(src._gradeToExecute)
{}

Form::~Form() {}

Form & Form::operator=(Form const & rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Form: grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Form: grade too low";
}

int  Form::getGradeToSign() const
{
    return _gradeToSign;
}

int  Form::getGradeToExecute() const
{
    return _gradeToExecute;
}

std::string const & Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

void Form::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}