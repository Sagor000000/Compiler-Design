#include <iostream>
#include <regex>
#include <string>

// Function to check if a variable declaration is valid
bool isValidVariableDeclaration(const std::string &input) {
    // Regular expression to match valid variable declarations
    // Format: (valid type) (valid identifier) (optional initialization) ;
    std::regex varDeclRegex(R"((int|float|double|char|bool|long|short|unsigned|signed)\s+(\w+)(\s*=\s*[\w\d+\-*/]*)?\s*;)");

    // Match the input with the regular expression
    return std::regex_match(input, varDeclRegex);
}

int main() {
    std::string input;

    // Get input from the user
    std::cout << "Enter a variable declaration: ";
    std::getline(std::cin, input);

    // Check if the input is a valid variable declaration
    if (isValidVariableDeclaration(input)) {
        std::cout << "This is a valid variable declaration." << std::endl;
    } else {
        std::cout << "This is not a valid variable declaration." << std::endl;
    }

    return 0;
}
