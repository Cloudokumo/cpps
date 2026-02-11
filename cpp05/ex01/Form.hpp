#pragma once 

#include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
    private:
        const std::string _name;
        bool _Signed;
        const int _gradeToSign;
        const int _gradeToExecute;
    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToExecute); 
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

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
};

std::ostream& operator<<(std::ostream& out, const Form& Form);