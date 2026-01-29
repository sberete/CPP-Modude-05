#include "Bureaucrat.hpp"

int Bureaucrat::check(int const & src)
{
    try
    {
        if (src < 1)
            throw GradeTooHighException(); 
        else if (src > 150)
            throw GradeTooLowException();
    }
    catch(const Bureaucrat::GradeTooHighException& e)
    {
        std::cerr << "Too high" << '\n';
        return 1;
    }
    catch(const Bureaucrat::GradeTooLowException& e)
    {
        std::cerr << "Too Low" << '\n';
        return 1;
    }
    return 0;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (check(grade))
        return ;
    _grade = grade;
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
    int tmp = _grade - 1;
    
    if (!check(tmp))
        _grade = tmp;

}

void Bureaucrat::decrement()
{
    int tmp = _grade + 1;

    if (!check(tmp))
        _grade = tmp;

}