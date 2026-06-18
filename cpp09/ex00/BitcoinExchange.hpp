#pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <stdexcept>
# include <cstdlib>
# include <cctype>
 
class BitcoinExchange
{
    private:

    std::map<std::string, double> _db;
 
    bool        isValidDate(const std::string &date) const;
    bool        isLeapYear(int year) const;
    double      getRate(const std::string &date) const;
    std::string trim(const std::string &s) const;

    public:
    
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
 
    bool loadDatabase(const std::string &filename);
    void processInput(const std::string &filename);

};
 
