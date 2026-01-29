#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat pn = Bureaucrat("Pierre", 3);

    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;
    pn.decrement();
    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;
    pn.increment();
    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;

    pn.increment();
    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;

    pn.increment();
    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;

    pn.increment();
    std::cout << pn.getName() << ", bureaucrat grade " << pn.getGrade() << std::endl;

}