#pragma once

#include <string>
#include <iostream>

class Contact{
    public:
        Contact();
        ~Contact();
        void set_info(void);
        void setFirst_name(void);
        void setlast_name(void);
        void setnickname(void);
        void setphone(void);
        void setsecret(void);
        
    private:  
        std::string get_info(std::string msg);
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone;
        std::string _secret;
};
