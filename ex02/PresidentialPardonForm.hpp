#ifndef PRESIDENTIALPARDONFORM_HPP
    #define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const &);

        ~PresidentialPardonForm();

        PresidentialPardonForm & operator=(PresidentialPardonForm const &);

    protected:
        void executeAction() const;

    private:
        std::string _target;
};

#endif