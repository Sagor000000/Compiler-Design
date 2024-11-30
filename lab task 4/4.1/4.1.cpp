#include <iostream>
#include <string>
#include <cctype>

bool startsWithCapital(const std::string& sentence) {
    return std::isupper(sentence[0]);
}

bool endsWithPunctuation(const std::string& sentence) {
    char lastChar = sentence[sentence.size() - 1];
    return lastChar == '.' || lastChar == '?' || lastChar == '!';
}
bool isGrammarCorrect(const std::string& sentence) {
    if (!startsWithCapital(sentence)) {
        return false;
    }

    if (!endsWithPunctuation(sentence)) {
        return false;
    }

    return true;
}

int main() {
    std::string sentence;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    if (isGrammarCorrect(sentence)) {
        std::cout << "Correct" << std::endl;
    } else {
        std::cout << "Wrong" << std::endl;
    }

    return 0;
}


