# CPP-Module-05

This project is part of the 42 school C++ curriculum. It focuses on exceptions, interfaces, and abstract classes through a bureaucratic form-signing simulation.

## Exercises

- **ex00** — Implements the `Bureaucrat` class with an incremental/decremental grade system, throwing custom exceptions (`GradeTooHighException`, `GradeTooLowException`) when grade limits are violated.
- **ex01** — Introduces the `Form` class, which can be signed by a `Bureaucrat` of sufficient grade, again relying on custom exceptions for invalid operations.
- **ex02** — Turns `Form` into an abstract base class (`AForm`) with concrete subclasses (`ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`), each implementing its own action.
- **ex03** — Adds an `Intern` class that acts as a factory, creating the correct form instance from a string name without direct knowledge of the concrete classes.

- ## Build

- Each exercise has its own Makefile:
- ```
  cd ex00 && make   # builds the ex00 executable
  ```
  Repeat inside `ex01`, `ex02`, and `ex03` as needed. Use `make clean`, `make fclean`, or `make re` to clean/rebuild.

  ## Constraints

  - Follows the 42 Norm
  - Compiles without errors or warnings (`-Wall -Wextra -Werror`)
  - Written in C++98
