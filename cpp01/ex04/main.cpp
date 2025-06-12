#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;

    if (argc == 4)
    {
        filename = argv[1];
        s1 = argv[2];
        s2 = argv[3];
        std::ifstream file(filename);
        if (!file.is_open())
        {
            std::cerr << "Error: CAN'T Open" << std::endl;
            return 1;
        }
    }
}