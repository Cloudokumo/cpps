#include "Harl.hpp"

Harl::Harl(){}
Harl::~Harl(){}

void Harl::debug( void )
{
    std::cout << "DEBUG" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "INFO" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
std::cout << "WARNING" << std::endl;
   std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "ERROR" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complainfilter( std::string level )
{
    void (Harl::*funcs[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    int index = -1;

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            index = i;
            break;
        }
    }
    switch (index)
    {
        case 0:
            (this->*funcs[0])();
            //Fallthrough
        case 1:
            (this->*funcs[1])();
            //Fallthrough
        case 2:
            (this->*funcs[2])();
            //Fallthrough
        case 3:
            (this->*funcs[3])();
            break;    
    default:
            std::cerr << "Unknown level: " << level << std::endl;
    }
}