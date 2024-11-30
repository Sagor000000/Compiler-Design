#include <iostream>
#include <regex>
#include <string>

// Function to check if a function declaration is valid
bool isValidFunctionDeclaration(const std::string &input) {
    // Regular expression to match valid function declarations
    // Format: (return type) (function name) (parameter list) ;
    std::regex funcDeclRegex(R"((int|float|double|char|bool|void)\s+(\w+)\s*\(([\w\s,]*)\)\s*;)");

    // Match the input with the regular expression
    return std::regex_match(input, funcDeclRegex);
}

int main() {
    std::string input;

    // Get input from the user
    std::cout << "Enter a function declaration: ";
    std::getline(std::cin, input);

    // Check if the input is a valid function declaration
    if (isValidFunctionDeclaration(input)) {
        std::cout << "This is a valid function declaration." << std::endl;
    } else {
        std::cout << "This is not a valid function declaration." << std::endl;
    }

    return 0;
}
