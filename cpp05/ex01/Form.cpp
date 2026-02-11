#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _Signed(false), _gradeToSign(150), _gradeToExecute(150) 
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _Signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) 
{
    std::cout << "Form parameterized constructor called" << std::endl;
    if (gradeToSign <= 0 || gradeToExecute <= 0) 
    {
        throw Form::GradeTooHighException();
    }
    else if (gradeToSign >= 151 || gradeToExecute >= 151) 
    {
        throw Form::GradeTooLowException();
    }
}

Form::~Form() 
{
    std::cout << "Form destructor called"<< std::endl;
}

Form::Form(const Form& other) 
    : _name(other._name), _Signed(other._Signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) 
{
    std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) 
{
    std::cout << "Form copy assignment operator called" << std::endl;
    if (this != &other) 
    {
        _Signed = other._Signed;
    }
    return *this;
}

std::string Form::getName() const 
{
    return (this->_name);
}

bool Form::isSigned() const 
{
    return (this->_Signed);
}

int Form::getGradeToSign() const 
{
    return (this->_gradeToSign);
}

int Form::getGradeToExec() const 
{
    return (this->_gradeToExecute);
}

void Form::BeSigned(const Bureaucrat& bureaucrat) 
{
    if (this->_Signed)
    {
        std::cout << "Form " << this->_name << " is already signed" << std::endl;
        return;
    }
    if (bureaucrat.getGrade() > this->_gradeToSign) 
    {
        throw Form::GradeTooLowException();
    }
    this->_Signed = true;
}

const char* Form::GradeTooHighException::what() const throw() 
{
    return "Form Exception: grade too high";
}

const char* Form::GradeTooLowException::what() const throw() 
{
    return "Form Exception: grade too low";
}

std::ostream& operator<<(std::ostream& out, const Form& form) 
{
    out << form.getName() 
        << ", form grade to sign " << form.getGradeToSign() 
        << ", form grade to execute " << form.getGradeToExec();
    return out;
}