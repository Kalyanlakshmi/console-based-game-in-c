#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayMenu();
void displayStats(int *ptr);
void playGame(int maxAttempts, int *ptr);

int generateRandomNumber(int difficulty) {
    switch(difficulty) {
        case 1:
            return rand() % 100 + 1;
        case 2:
            return rand() % 500 + 1;
        case 3:
            return rand() % 1000 + 1;
        default:
            return printf("Enter valid difficulty level\n");
    }
}

int main() {
    srand(time(NULL));
    int attempts = 0;
    int maxAttempts = 5, score = 0;
    int *ptr = &score;
    ptr = &score;
    printf("Welcome to the Guess the Number Game!\n");

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Game Start
                playGame(maxAttempts, ptr);
                break;

            case 2:
                // Display Stats
                displayStats(ptr);
                break;

            case 3:
                // Exit
                printf("Exiting the game. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}

void displayMenu() {
    printf("\n--- Menu ---\n");
    printf("1. Start Game\n");
    printf("2. Display Stats\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void displayStats(int *ptr) {
    printf("\n--- Stats ---\n");
    printf("score: %d\n", *ptr);
}

void playGame(int maxAttempts, int *ptr) {
    int difficulty;

    printf("\nChoose Difficulty Level:\n");
    printf("1. Easy (1-100)\n");
    printf("2. Medium (1-500)\n");
    printf("3. Hard (1-1000)\n");
    printf("Enter your difficulty Level: ");
    scanf("%d", &difficulty);

    if (difficulty >= 1 && difficulty <= 3) {
        int randomNumber = generateRandomNumber(difficulty);

        for (int attempts = 1; attempts <= maxAttempts; attempts++) {
            int userGuess;
            printf("Attempt %d: Enter your guess: ", attempts);
            scanf("%d", &userGuess);

            if (userGuess == randomNumber) {
                (*ptr)++;
                printf("Congratulations! You guessed the correct number: %d\n", randomNumber);
                break;
            } else if (userGuess < randomNumber) {
                printf("Too low. ");
            } else {
                printf("Too high. ");
            }

            // Provide a hint after three unsuccessful attempts
            if (attempts == 3) {
                if (randomNumber % 2 == 0) {
                    printf("Hint: The correct number is even.\n");
                } else {
                    printf("Hint: The correct number is odd.\n");
                }
            }

            // If all attempts are used and the correct number is not guessed
            if (attempts == maxAttempts) {
                printf("Sorry, you ran out of attempts. The correct number was: %d\n", randomNumber);
            }
        }
    } else {
        printf("Invalid difficulty level.\n");
    }
}
