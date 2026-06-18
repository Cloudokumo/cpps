#include "BitcoinExchange.hpp"
 
 
BitcoinExchange::BitcoinExchange() 
{}
 
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : _db(other._db) 
{}
 
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}
 
BitcoinExchange::~BitcoinExchange() 
{}

 
std::string BitcoinExchange::trim(const std::string &s) const
{
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return (s.substr(start, end - start + 1));
}
 
bool BitcoinExchange::isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
 
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
 
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return false;
    }
 
    int year  = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day   = atoi(date.substr(8, 2).c_str());
 
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
 
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
        daysInMonth[1] = 29;
 
    if (day > daysInMonth[month - 1])
        return false;
 
    return true;
}
 
double BitcoinExchange::getRate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _db.lower_bound(date);
 
    if (it == _db.end() || it->first != date)
    {
        if (it == _db.begin())
            return -1.0;
        --it;
    }
    return (it->second);
}

 
bool BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;
 
    std::string line;
    std::getline(file, line); 
 
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;
 
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
 
        std::string date  = trim(line.substr(0, comma));
        std::string value = trim(line.substr(comma + 1));
 
        if (!isValidDate(date))
            continue;
 
        double rate = atof(value.c_str());
        _db[date] = rate;
    }
 
    return (!_db.empty());
}
 
void BitcoinExchange::processInput(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
 
    std::string line;
    std::getline(file, line);
 
    while (std::getline(file, line))
    {
        line = trim(line);
        if (line.empty())
            continue;

        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
 
        std::string date     = trim(line.substr(0, sep));
        std::string valueStr = trim(line.substr(sep + 3));
 
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (valueStr.empty())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        bool negative = (valueStr[0] == '-');
 
        char *end;
        double value = strtod(valueStr.c_str(), &end);

        if (end == valueStr.c_str() || *end != '\0')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
 
        if (negative || value < 0.0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
 
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
 

        double rate = getRate(date);
        if (rate < 0.0)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}