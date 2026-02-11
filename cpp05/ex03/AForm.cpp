#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _Signed(false), _gradeToSign(150), _gradeToExecute(150) 
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _Signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign <= 0 || gradeToExecute <= 0) 
    {
        throw AForm::GradeTooHighException();
    }
    else if (gradeToSign >= 151 || gradeToExecute >= 151) 
    {
        throw AForm::GradeTooLowException();
    }
}

AForm::~AForm() 
{
    std::cout << "AForm destructor called"<< std::endl;
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _Signed(other._Signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) 
{
    std::cout << "AForm copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _Signed = other._Signed;
    }
    return *this;
}

std::string AForm::getName() const 
{
    return (this->_name);
}

bool AForm::isSigned() const 
{
    return (this->_Signed);
}

int AForm::getGradeToSign() const 
{
    return (this->_gradeToSign);
}

int AForm::getGradeToExec() const 
{
    return (this->_gradeToExecute);
}

void AForm::BeSigned(const Bureaucrat& bureaucrat) 
{
    if (this->_Signed)
    {
        std::cout << "AForm " << this->_name << " is already signed" << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > this->_gradeToSign) 
    {
        throw AForm::GradeTooLowException();
    }
    std::cout << "Form " << this->_name << " has been signed by " << bureaucrat.getName() << std::endl;
    this->_Signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() 
{
    return "AForm Exception: grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() 
{
    return "AForm Exception: grade too low";
}

std::ostream& operator<<(std::ostream& out, const AForm& AForm) 
{
    out << AForm.getName() 
        << ", AForm grade to sign " << AForm.getGradeToSign() 
        << ", AForm grade to execute " << AForm.getGradeToExec();
    return out;
}

const char* AForm::FormNotSignedException::what() const throw() 
{
    return "Form is not signed";
}