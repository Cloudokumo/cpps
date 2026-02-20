#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 151);
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
    try {
        Bureaucrat dave("Dave", 2);
        std::cout << dave << std::endl;
        dave.incrementGrade();
        std::cout << dave << std::endl;
        dave.incrementGrade();  // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
    try {
        Bureaucrat eve("Eve", 149);
        std::cout << eve << std::endl;
        eve.decrementGrade();
        std::cout << eve << std::endl;
        eve.decrementGrade();  // Should throw exception
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
    try {
        Bureaucrat frank("Frank", 75);
        Bureaucrat frankCopy(frank);
        std::cout << "Original: " << frank << std::endl;
        std::cout << "Copy: " << frankCopy << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== End of tests ===" << std::endl;
    return 0;
}