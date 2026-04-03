#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
    if (this != &rhs)
        _target = rhs._target;
    return *this;
}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());

    file <<
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\\\\n";
}