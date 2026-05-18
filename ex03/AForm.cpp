#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const & src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & rhs)
{
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form not signed";
}

int  AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int  AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

std::string const & AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

void AForm::beSigned(Bureaucrat const & b)
{
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
    o << rhs.getName() << ", signed: " << rhs.isSigned() << ", grade to sign: " << rhs.getGradeToSign() << ", grade to execute: " << rhs.getGradeToExecute();
    return o;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
    executeAction();
}


