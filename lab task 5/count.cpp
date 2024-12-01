#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// List of C++ keywords
const unordered_set<string> keywords = {
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool",
    "break", "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class",
    "compl", "const", "consteval", "constexpr", "constinit", "const_cast", "continue",
    "decltype", "default", "delete", "do", "double", "dynamic_cast", "else", "enum",
    "explicit", "export", "extern", "false", "float", "for", "friend", "goto", "if",
    "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq",
    "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register",
    "reinterpret_cast", "requires", "return", "short", "signed", "sizeof", "static",
    "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local",
    "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using",
    "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"
};

// List of data types in C++
const unordered_set<string> data_types = {
    "int", "char", "float", "double", "bool", "void", "wchar_t", "long", "short",
    "signed", "unsigned", "char8_t", "char16_t", "char32_t"
};

int main() {
    // File name to process
    const string filename = "example.cpp";
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the file " << filename << endl;
        return 1;
    }

    string word;
    int keyword_count = 0;
    int data_type_count = 0;

    // Read words from the file
    while (file >> word) {
        // Count keywords
        if (keywords.find(word) != keywords.end()) {
            ++keyword_count;
        }

        // Count data types
        if (data_types.find(word) != data_types.end()) {
            ++data_type_count;
        }
    }

    file.close();

    // Print results
    cout << "Total Keywords Count: " << keyword_count << endl;
    cout << "Total Data Types Count: " << data_type_count << endl;

    return 0;
}
