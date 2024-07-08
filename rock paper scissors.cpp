#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    // Variables for user and computer choices
    int computerChoice = rand() % 3 + 1; // Random number between 1 and 3
    int userChoice;

    // Prompt user to choose rock (1), paper (2), or scissors (3)
    cout << "Enter your choice:\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cin >> userChoice;

    // Validate user input
    if (userChoice < 1 || userChoice > 3) {
        cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        return 1;
    }

    // Convert computer choice to string
    string computerChoiceStr;
    switch (computerChoice) {
        case 1:
            computerChoiceStr = "Rock";
            break;
        case 2:
            computerChoiceStr = "Paper";
            break;
        case 3:
            computerChoiceStr = "Scissors";
            break;
    }

    // Convert user choice to string
    string userChoiceStr;
    switch (userChoice) {
        case 1:
            userChoiceStr = "Rock";
            break;
        case 2:
            userChoiceStr = "Paper";
            break;
        case 3:
            userChoiceStr = "Scissors";
            break;
    }

    // Determine the winner
    string result;
    if (computerChoice == userChoice) {
        result = "It's a tie!";
    } else if ((userChoice == 1 && computerChoice == 3) ||
               (userChoice == 2 && computerChoice == 1) ||
               (userChoice == 3 && computerChoice == 2)) {
        result = "You win!";
    } else {
        result = "Computer wins!";
    }

    // Display choices and result
    cout << "You chose: " << userChoiceStr << endl;
    cout << "Computer chose: " << computerChoiceStr << endl;
    cout << result << endl;

    return 0;
}

