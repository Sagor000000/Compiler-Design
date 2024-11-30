#include <iostream>
#include <string>

// Function to check if a function name is valid
bool isValidFunctionName(const std::string& name) {
    if (name.empty() || !isalpha(name[0])) {
        return false;
    }
    for (char c : name) {
        if (!isalnum(c) && c != '_') {
            return false;
        }
    }
    return true;
}

// Function to check if the return type is valid
bool isValidReturnType(const std::string& returnType) {
    std::string validTypes[] = {"void", "int", "float", "double", "char", "bool"};
    for (const std::string& type : validTypes) {
        if (returnType == type) {
            return true;
        }
    }
    return false;
}

// Function to analyze a function definition
void analyzeFunctionDefinition(const std::string& returnType, const std::string& functionName) {
    if (isValidReturnType(returnType)) {
        std::cout << "Valid return type: " << returnType << std::endl;
    } else {
        std::cout << "Invalid return type: " << returnType << std::endl;
    }

    if (isValidFunctionName(functionName)) {
        std::cout << "Valid function name: " << functionName << std::endl;
    } else {
        std::cout << "Invalid function name: " << functionName << std::endl;
    }
}

int main() {
    std::string returnType, functionName;

    // Take input for return type and function name
    std::cout << "Enter the return type of the function: ";
    std::cin >> returnType;
    std::cout << "Enter the function name: ";
    std::cin >> functionName;

    // Analyze the function definition
    analyzeFunctionDefinition(returnType, functionName);

    return 0;
}
