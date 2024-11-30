#include <iostream>
#include <stack>
#include <cctype>
#include <string>

// Function to check if the parentheses are balanced
bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> s;
    for (char ch : expression) {
        if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            if (s.empty()) {
                return false; // Closing parenthesis without matching opening one
            }
            s.pop();
        }
    }
    return s.empty(); // True if no unmatched opening parenthesis
}

// Function to check if a character is a valid operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

// Function to check if the expression is valid
bool isExpressionValid(const std::string& expression) {
    if (expression.empty()) {
        return false; // Empty expression is invalid
    }

    // Check parentheses balance
    if (!areParenthesesBalanced(expression)) {
        return false;
    }

    // Check if the first and last characters are valid
    if (isOperator(expression[0]) || isOperator(expression[expression.length() - 1])) {
        return false; // Cannot start or end with an operator
    }

    // Traverse through the expression and validate
    for (std::size_t i = 0; i < expression.length(); ++i) {
        char ch = expression[i];

        // Allow digits, operators, parentheses, and variables (like x, y)
        if (std::isdigit(ch) || ch == '(' || ch == ')' || isalpha(ch)) {
            continue;
        } else if (isOperator(ch)) {
            // Check for consecutive operators (invalid)
            if (i > 0 && isOperator(expression[i - 1])) {
                return false;
            }
        } else {
            // Invalid character found
            return false;
        }
    }

    return true;
}

int main() {
    std::string expression;

    // Take input for the mathematical expression
    std::cout << "Enter a mathematical expression: ";
    std::getline(std::cin, expression);

    // Check if the expression is valid
    if (isExpressionValid(expression)) {
        std::cout << "The mathematical expression is valid." << std::endl;
    } else {
        std::cout << "The mathematical expression is invalid." << std::endl;
    }

    return 0;
}

