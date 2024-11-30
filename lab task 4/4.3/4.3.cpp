#include <iostream>
#include <stack>
#include <string>

// Function to check if the given expression is properly parenthesized
bool isProperlyParenthesized(const std::string& expression) {
    std::stack<char> s;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return s.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter a mathematical expression: ";
    std::getline(std::cin, expression);

    if (isProperlyParenthesized(expression)) {
        std::cout << "The expression is properly parenthesized." << std::endl;
    } else {
        std::cout << "The expression is not properly parenthesized." << std::endl;
    }

    return 0;
}
