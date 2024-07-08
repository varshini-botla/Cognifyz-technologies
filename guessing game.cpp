#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber, guess, numberOfGuesses = 0;

    // Seed the random number generator
    srand(time(0));
    randomNumber = rand() % 100 + 1; // Random number between 1 and 100

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have generated a random number between 1 and 100.\n");
    printf("Can you guess the number?\n");

    // Loop until the user guesses the correct number
    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        numberOfGuesses++;

        if (guess < randomNumber) {
            printf("Higher!\n");
        } else if (guess > randomNumber) {
            printf("Lower!\n");
        } else {
            printf("Congratulations! You guessed the correct number in %d attempts.\n", numberOfGuesses);
        }
    } while (guess != randomNumber);

    return 0;
}

