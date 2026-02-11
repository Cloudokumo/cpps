#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    std::cout << "\n=== Test 1: Valid form ===" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form)
    {
        boss.signAForm(*form);
        form->execute(boss);
        delete form;
    }

    std::cout << "\n=== Test 2: Another valid form ===" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "garden");
    if (form)
    {
        boss.signAForm(*form);
        form->execute(boss);
        delete form;
    }

    std::cout << "\n=== Test 3: Invalid form ===" << std::endl;
    form = someRandomIntern.makeForm("coffee request", "kitchen");
    if (!form)
        std::cout << "Form was not created" << std::endl;

    return 0;
}