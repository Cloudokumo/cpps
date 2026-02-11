#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    typedef AForm* (Intern::*FormCreator)(const std::string&) const;
    FormCreator formCreators[3] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    
    std::cout << "Intern cannot create " << formName << " form" << std::endl;
    return NULL;
}

AForm *Intern::createPresidentialPardonForm(const std::string &target)const
{
    return new PresidentialPardonForm(target);
}
AForm *Intern::createRobotomyRequestForm(const std::string &target)const
{
    return new RobotomyRequestForm(target);
}
AForm *Intern::createShrubberyCreationForm(const std::string &target)const
{
    return new ShrubberyCreationForm(target);
}