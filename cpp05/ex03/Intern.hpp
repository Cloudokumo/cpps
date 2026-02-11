#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

class Intern
{
    private:
        AForm* createPresidentialPardonForm(const std::string& target) const;
        AForm* createRobotomyRequestForm(const std::string& target) const;
        AForm* createShrubberyCreationForm(const std::string& target) const;

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();
    AForm* makeForm(const std::string& formName, const std::string& target);
};