#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string input;
    cout << "Enter a word or phrase: ";
    getline(cin, input);

    // Remove spaces and punctuation and convert to lowercase
    string cleanInput;
    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];
        if (isalpha(c)) {
            cleanInput += tolower(c);
        }
    }

    // Check if cleanInput is a palindrome
    bool isPalindrome = true;
    int left = 0;
    int right = cleanInput.length() - 1;

    while (left < right) {
        if (cleanInput[left] != cleanInput[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    // Output result
    if (isPalindrome) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}

