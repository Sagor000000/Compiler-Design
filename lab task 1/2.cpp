#include <iostream>
#include <string>

int main() {
    std::string firstName, lastName, fullName;
    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    
    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    
    fullName = firstName + " " + lastName;
    
    std::cout << "Full name: " << fullName << std::endl;

    return 0;
}
