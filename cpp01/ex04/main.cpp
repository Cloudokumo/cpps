#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    std::string filename;
    std::string s1;
    std::string s2;
    std::string content;
    std::string line;

    if (argc != 4)
        return 1;
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "empty s1" << std::endl;
        return 1;
    }
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Cannot open file " << filename << std::endl;
        return 1;
    }

    while (std::getline(file, line))
    {
        content += line;
        if (!file.eof())
            content += "\n";
    }
    file.close();

    std::string result;
    size_t pos = 0;
    size_t found = 0;

    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    
    std::string outFilename = filename + ".replace";
    std::ofstream outFile(outFilename.c_str());
    if (!outFile.is_open())
        return 1;
    outFile << result;
    outFile.close();
    return 0;
}