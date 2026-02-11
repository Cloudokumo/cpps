#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
    try 
    {
        Bureaucrat guy("Important guy", 2);
        Bureaucrat intern("Intern john", 150);
        Form papier("Important Paper", 20, 20);
        Form papier2("Important Paper2", 125, 20);
        
        std::cout << guy << std::endl; 
        std::cout << intern << std::endl;
        std::cout << papier << std::endl; 
        std::cout << papier2 << std::endl;
        
        std::cout << "\n--- Signing Forms ---" << std::endl;
        
        intern.signForm(papier); 
        guy.signForm(papier);
        
        std::cout << papier << std::endl;
        
        papier2.BeSigned(intern);
        papier2.BeSigned(guy);
        
        std::cout << papier2 << std::endl;
    }
    catch(const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}