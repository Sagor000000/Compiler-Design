#include <iostream>
#include <string>
using namespace std;

void findOperators(const string &input) {
    // Define the set of operators
    string operators = "+-*/=";

    int operatorCount = 0;

    // Iterate through the input string and check for operators
    for (size_t i = 0; i < input.length(); ++i) {
        if (operators.find(input[i]) != string::npos) {
            operatorCount++;
            cout << "operator" << operatorCount << ": " << input[i] << endl;
        }
    }

    cout << "number of operators = " << operatorCount << endl;
}

int main() {
    string input;
    cout << "Enter an expression: ";
    getline(cin, input);

    findOperators(input);

    return 0;
}
