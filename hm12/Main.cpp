#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <map>

void replaceWord(std::string& text, const std::string& oldWord, const std::string& newWord) {
    size_t pos = 0;
    while ((pos = text.find(oldWord, pos)) != std::string::npos) {
        text.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }
}

void capitalizeSentences(std::string& text) {
    bool newSentence = true;
    for (size_t i = 0; i < text.length(); ++i) {
        if (newSentence && isalpha(text[i])) {
            text[i] = toupper(text[i]);
            newSentence = false;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            newSentence = true;
        }
    }
}

void countLetterOccurrences(const std::string& text) {
    std::map<char, int> letterCount;
    for (char ch : text) {
        if (isalpha(ch)) {
            letterCount[tolower(ch)]++;
        }
    }

    std::cout << "Occurrences of each letter:\n";
    for (const auto& pair : letterCount) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}

void countDigitOccurrences(const std::string& text) {
    int digitCount[10] = { 0 };
    for (char ch : text) {
        if (isdigit(ch)) {
            digitCount[ch - '0']++;
        }
    }

    std::cout << "Occurrences of each digit:\n";
    for (int i = 0; i < 10; ++i) {
        std::cout << i << ": " << digitCount[i] << "\n";
    }
}

int main() {
    std::string text;
    std::string oldWord, newWord;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text);

    std::cout << "Enter the word to replace: ";
    std::cin >> oldWord;
    std::cout << "Enter the new word: ";
    std::cin >> newWord;

    replaceWord(text, oldWord, newWord);
    capitalizeSentences(text);

    std::cout << "\nModified text:\n" << text << "\n";

    countLetterOccurrences(text);

    countDigitOccurrences(text);

    return 0;
}
