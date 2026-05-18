#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("Pierre", 3);
        a.increment();
        std::cout << a << std::endl;
        a.increment();
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat a("Pierre", 800);
        a.increment();
        std::cout << a << std::endl;
        a.increment();
        std::cout << a << std::endl;
        a.increment();
        std::cout << a << std::endl;

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}