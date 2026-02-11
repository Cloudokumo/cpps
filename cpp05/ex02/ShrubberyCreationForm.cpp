#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "ShrubberyCreationForm constructor called for target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: Could not create file" << std::endl;
        return;
    }
    
file << "        ccee88oo\n";
file << "    C8O8O8Q8PoOb o8oo\n";
file << "  dOB69QO8PdUOpugoO9bD\n";
file << " CgggbU8OU qOp qOdoUOdcb\n";
file << "     6OuU  /p u gcoUodpP\n";
file << "       \\\\\\//  /douUP\n";
file << "         \\\\\\////\n";
file << "          |||/\\\n";
file << "          |||\\/\n";
file << "          |||||\n";
file << "    .....//||||\\....\n";

    file.close();
    std::cout << executor.getName() << " executed " << this->getName() << " on " << _target << std::endl;
}