#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class Contact{
    public:
        Contact();
        ~Contact();

        void set_info(void);
        void setFirst_name(const std::string& name);
        void setLast_name(const std::string& name);
        void setNickname(const std::string& nickname);
        void setPhone(const std::string& phone);
        void setSecret(const std::string& secret);
    

        std::string getFirst_name(void) const;
        std::string getLast_name(void) const;
        std::string getNickname(void) const;
        std::string getPhone(void) const;
        std::string getSecret(void) const;

        void display_summary(int index) const;
        void display_full(void) const;
        bool isEmpty(void) const;
        
    private:  
        std::string get_info(std::string msg);
        std::string truncate(const std::string& str, size_t width) const;
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};
