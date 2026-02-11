#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) 
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
    std::cout << "Bureaucrat parameterized constructor called" << std::endl;
    _grade = grade;
    if (grade <= 0) 
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else if (grade >= 151) 
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) 
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() 
{
    std::cout << "Bureaucrat destructor called"<< std::endl;
}


const std::string& Bureaucrat::getName() const 
{
    return (this->_name);
}

int Bureaucrat::getGrade() const 
{
    return (this->_grade);
}

void Bureaucrat::incrementGrade() 
{
    if (this->_grade - 1 <= 0) 
    {
        throw Bureaucrat::GradeTooHighException();
    }
    else
    {
        _grade--;
        std::cout << _name << " got promoted to grade " << _grade << std::endl;
    }
}


void Bureaucrat::decrementGrade() 
{
    if (this->_grade + 1 >= 151) 
    {
        throw Bureaucrat::GradeTooLowException();
    }
    else
    {
        _grade++;
        std::cout << _name << " got demoted to grade " << _grade << std::endl;
    }

}

const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
    out << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signAForm(AForm& AForm)
{
    try 
    {
        AForm.BeSigned(*this);
        std::cout << _name << " signed " << AForm.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn't sign " << AForm.getName() 
                  << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
