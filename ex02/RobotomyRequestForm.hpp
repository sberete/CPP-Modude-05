#ifndef ROBOTOMYREQUESTFORM_HPP
    #define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const &);

        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(RobotomyRequestForm const &);

    protected:
        void executeAction() const;

    private:
        std::string _target;
};

#endif