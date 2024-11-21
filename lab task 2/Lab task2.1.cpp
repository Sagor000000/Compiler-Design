#include <iostream>
#include <string>
using namespace std;

void checkComment(const string &input) {
    string result = (input.substr(0, 2) == "//") ? "This is a single line comment."
                   : (input.substr(0, 2) == "/*" && input.substr(input.length() - 2) == "*/") ? "This is a multi line comment."
                   : "This is not a comment.";

    cout << result << endl;
}

int main() {
    string input;

    cout << "Enter the comment: ";
    getline(cin, input);

    checkComment(input);

    return 0;
}
