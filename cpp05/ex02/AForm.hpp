#pragma once 

#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _Signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute); 
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        std::string getName() const;
        bool        isSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExec() const;

        void BeSigned(const Bureaucrat& bureaucrat);

         class GradeTooHighException : public std::exception 
        {
        public:
            virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
        public:
            virtual const char* what() const throw();
        };
        virtual void execute(Bureaucrat const & executor) const = 0;
        class FormNotSignedException : public std::exception 
        {
        public:
            virtual const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);