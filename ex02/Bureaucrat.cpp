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
    // if (_grade - 1 < 1)
    //     throw GradeTooHighException(); 
    // else if (_grade - 1 > 150)
    //     throw GradeTooLowException();
    check(_grade - 1);
    _grade--;

}

void Bureaucrat::decrement()
{
    if (_grade + 1 < 1)
        throw GradeTooHighException(); 
    else if (_grade + 1 > 150)
        throw GradeTooLowException();

    _grade++;
}

void Bureaucrat::signForm(AForm & f)
{
    try
    {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    
}