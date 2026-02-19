#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    check(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
    _name = rhs._name;
    _grade = rhs._grade;

    check(_grade);
    
    return *this;
}

int const & Bureaucrat::getGrade() const
{
    return _grade;
}

std::string const & Bureaucrat::getName() const
{
    return _name;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: grade too low";
}


void Bureaucrat::check(int const & src)
{
    if (src < 1)
        throw GradeTooHighException(); 
    else if (src > 150)
        throw GradeTooLowException();
}

void Bureaucrat::increment()
{
    check(_grade - 1);
    _grade--;

}

void Bureaucrat::decrement()
{
    check(_grade + 1);

    _grade++;
}