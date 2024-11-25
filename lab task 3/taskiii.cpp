#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_set>

using namespace std;


const unordered_set<string> keywords = {
    "int", "float", "if", "else", "for", "while", "return", "void", "include", "using", "namespace", "std", "main"
};
const unordered_set<char> operators = { '+', '-', '*', '/', '=', '<', '>', '!' };
const unordered_set<char> delimiters = { '(', ')', '{', '}', '[', ']', ';', ',' };


bool isValidIdentifier(const string &str) {
    if (!isalpha(str[0]) && str[0] != '_')
        return false;
    for (char c : str) {
        if (!isalnum(c) && c != '_')
            return false;
    }
    return true;
}

int main() {
    ifstream file("task.txt");
    if (!file.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    string token;
    char ch;
    while (file.get(ch)) {

        if (isspace(ch)) {
            continue;
        }


        if (operators.count(ch)) {
            cout << "Operator: " << ch << endl;
            continue;
        } else if (delimiters.count(ch)) {
            cout << "Delimiter: " << ch << endl;
            continue;
        }


        token.clear();
        if (isalpha(ch) || ch == '_') {

            token += ch;
            while (file.get(ch) && (isalnum(ch) || ch == '_')) {
                token += ch;
            }
            file.putback(ch);

            if (keywords.count(token)) {
                cout << "Keyword: " << token << endl;
            } else if (isValidIdentifier(token)) {
                cout << "Identifier: " << token << endl;
            } else {
                cout << "Invalid Identifier: " << token << endl;
            }
        } else if (isdigit(ch)) {

            token += ch;
            while (file.get(ch) && isdigit(ch)) {
                token += ch;
            }
            file.putback(ch);
            cout << "Number: " << token << endl;

            cout << "Invalid Token: " << ch << endl;
        }
    }

    file.close();
    return 0;
}
