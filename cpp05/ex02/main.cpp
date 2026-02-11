#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat john("John", 1);
        Bureaucrat bob("Bob", 150);
        
        std::cout << bob << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << "\n--- Testing Shrubbery ---" << std::endl;
        john.signAForm(shrub);
        shrub.execute(john);
        
        std::cout << "\n--- Testing Robotomy ---" << std::endl;
        john.signAForm(robot);
        robot.execute(john);
        
        std::cout << "\n--- Testing Presidential ---" << std::endl;
        john.signAForm(pardon);
        pardon.execute(john);
        
        std::cout << "\n--- Testing with low grade ---" << std::endl;
        ShrubberyCreationForm shrub2("garden");
        bob.signAForm(shrub2); // Should fail
    
        
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}