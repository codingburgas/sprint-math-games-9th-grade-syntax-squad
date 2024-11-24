#include <iostream>

using namespace std;

void Menu() {
    // Function to print the game name and menu options
    cout << " /$$      /$$                           /$$ /$$          " << endl;
    cout << "| $$  /$ | $$                          | $$| $$          " << endl;
    cout << "| $$ /$$$| $$  /$$$$$$   /$$$$$$   /$$$$$$$| $$  /$$$$$$ " << endl;
    cout << "| $$/$$ $$ $$ /$$__  $$ /$$__  $$ /$$__  $$| $$ /$$__  $$" << endl;
    cout << "| $$$$_  $$$$| $$  | $$| $$  |__/| $$  | $$| $$| $$$$$$$$" << endl;
    cout << "| $$$/ |  $$$| $$  | $$| $$      | $$  | $$| $$| $$_____/ " << endl;
    cout << "| $$/   |  $$|  $$$$$$/| $$      |  $$$$$$$| $$|  $$$$$$$ " << endl;
    cout << "|__/     |__/ \\______/ |__/       |_______/|__/ |_______/ " << endl;

    int choice;

    do {
        cout << "\nMain Menu:\n";
        cout << "   1. Play\n   2. How To Play\n   3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Play the game
            const char word[6] = "Apple"; // The hidden word
            char guess[6];               // The player's guess
            const int maxTries = 6;      // Number of attempts allowed

            cout << "\nWelcome to Wordle! You have " << maxTries << " attempts to guess the word.\n";
            cout << "Hints: '*' means correct letter and position, '+' means correct letter but wrong position.\n";
            cout << "Hint for the word: This is a fruit and the word starts with a capital letter.\n";

            bool won = false;

            for (int attempt = 1; attempt <= maxTries; ++attempt) {
                cout << "\nAttempt " << attempt << " - Enter your 5-letter word: ";
                cin >> guess;

                // Manual length check
                int length = 0;
                for (int i = 0; i < 6; ++i) {
                    if (guess[i] == '\0') {
                        break;
                    }
                    length++;
                }

                // Validate input length
                if (length != 5) {
                    cout << "Please enter a valid 5-letter word.\n";
                    --attempt; // Don't count invalid input as an attempt
                    continue;
                }

                char feedback[6]; // Store feedback for this attempt
                feedback[5] = '\0'; // Null-terminate the feedback string
                bool correct = true;

                // Generate feedback
                for (int i = 0; i < 5; ++i) {
                    if (guess[i] == word[i]) {
                        feedback[i] = '*'; // Correct letter in correct position
                    }
                    else {
                        bool found = false;
                        for (int j = 0; j < 5; ++j) {
                            if (guess[i] == word[j] && i != j) {
                                found = true;
                                break;
                            }
                        }
                        feedback[i] = found ? '+' : '-'; // Correct letter in wrong position or not in word
                        if (feedback[i] != '*') {
                            correct = false; // The guess is not entirely correct
                        }
                    }
                }

                cout << "Feedback: " << feedback << endl;

                if (correct) {
                    cout << "Congratulations! You've guessed the word: " << word << "!\n";
                    won = true;
                    break;
                }
            }

            if (!won) {
                cout << "Sorry! You've used all your attempts. The word was: " << word << ". Better luck next time!\n";
            }

            break;
        }

        case 2:
            // Tutorial on how to play
            cout << "\nHow to Play:\n";
            cout << "1. Start with a Guess: Enter any valid 5-letter word to gather clues about the hidden word.\n";
            cout << "2. Check the Feedback: '*' = correct position, '+' = correct letter but wrong position, '-' = not in the word.\n";
            cout << "3. Refine Your Guesses: Use feedback to make smarter guesses; avoid repeating incorrect letters.\n";
            cout << "4. Win or Lose: Guess the word in 6 tries to win; otherwise, the hidden word is revealed.\n";
            break;

        case 3:
            // Exit the game
            cout << "Goodbye! Thanks for playing.\n";
            return; // Exit the menu
            break;

        default:
            cout << "Invalid option. Please choose 1, 2, or 3.\n";
            break;
        }
    } while (choice != 3);
}

int main() {
    Menu();
    return 0;
}