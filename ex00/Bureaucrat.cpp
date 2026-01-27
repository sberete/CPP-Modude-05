#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, uint8_t grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
            _grade = grade;
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Too high" << '\n';
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Too Low" << '\n';
    }
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

void Bureaucrat::increment()
{
    _grade--;
}

void Bureaucrat::decrement()
{
    _grade++;
}