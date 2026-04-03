#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void RobotomyRequestForm::executeAction() const
{
    static int counter = 0;
    counter++;

    std::cout << "BZZZZZZZZ DRILLING NOISES..." << std::endl;

    if (counter % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << std::endl;

}