#include "ScalarConv.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		std::cout << "Need a value" << std::endl;
		return (0);
	}
	if (ac > 2)
	{
		std::cout << "Need a single value" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}


// void runTest(const std::string& literal, const std::string& expected) {
//     std::cout << "\033[1;34m[ TESTING: " << literal << " ]\033[0m" << std::endl;
//     std::cout << "\033[1;33m[ EXPECTED ]\033[0m" << std::endl;
//     std::cout << expected << std::endl;
    
//     std::cout << "\033[1;32m[ YOUR OUTPUT ]\033[0m" << std::endl;
//     ScalarConverter::convert(literal);
    
//     std::cout << "------------------------------------------" << std::endl << std::endl;
// }

// int main() {
//     // 1. Char Test
//     runTest("a", 
//         "char: 'a'\nint: 97\nfloat: 97.0f\ndouble: 97.0");

//     // 2. Simple Int
//     runTest("42", 
//         "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0");

//     // 3. Int Max
//     runTest("2147483647", 
//         "char: Non displayable\nint: 2147483647\nfloat: 2147483648.0f\ndouble: 2147483647.0");

//     // 4. Int Overflow
//     runTest("2147483648", 
//         "char: impossible\nint: impossible\nfloat: 2147483648.0f\ndouble: 2147483648.0");

//     // 5. Negative Int Underflow
//     runTest("-2147483649", 
//         "char: impossible\nint: impossible\nfloat: -2147483648.0f\ndouble: -2147483649.0");

//     // 6. Simple Float
//     runTest("42.0f", 
//         "char: '*'\nint: 42\nfloat: 42.0f\ndouble: 42.0");

//     // 7. Float with precision
//     runTest("4.2f", 
//         "char: impossible\nint: 4\nfloat: 4.2f\ndouble: 4.2");

//     // 8. Simple Double
//     runTest("3.14", 
//         "char: impossible\nint: 3\nfloat: 3.14f\ndouble: 3.14");

//     // 9. Pseudo Literals (Float)
//     runTest("-inff", 
//         "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf");

//     // 10. Pseudo Literals (Double)
//     runTest("nan", 
//         "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan");

//     // 11. Non-displayable Char
//     runTest("0", 
//         "char: Non displayable\nint: 0\nfloat: 0.0f\ndouble: 0.0");

//     // 12. Invalid Input (Empty)
//     runTest("", "Error: invalid litteral\n");

//     // 13. Invalid Input (Garbage)
//     runTest("999abc", "Error: invalid litteral\n");
//     return 0;
// }