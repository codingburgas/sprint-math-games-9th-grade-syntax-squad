#include <iostream>
#include <cstdlib> // For rand()


void Game() {
    // Function to print the game name and menu options
    std::cout << " /$$      /$$                           /$$ /$$          " << std::endl;
    std::cout << "| $$  /$ | $$                          | $$| $$          " << std::endl;
    std::cout << "| $$ /$$$| $$  /$$$$$$   /$$$$$$   /$$$$$$$| $$  /$$$$$$ " << std::endl;
    std::cout << "| $$/$$ $$ $$ /$$__  $$ /$$__  $$ /$$__  $$| $$ /$$__  $$" << std::endl;
    std::cout << "| $$$$_  $$$$| $$  | $$| $$  |__/| $$  | $$| $$| $$$$$$$$" << std::endl;
    std::cout << "| $$$/ |  $$$| $$  | $$| $$      | $$  | $$| $$| $$_____/ " << std::endl;
    std::cout << "| $$/   |  $$|  $$$$$$/| $$      |  $$$$$$$| $$|  $$$$$$$ " << std::endl;
    std::cout << "|__/     |__/ \\______/ |__/       |_______/|__/ |_______/ " << std::endl;

    int choice;
    int choiceDifficult;

    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "   1. Play\n   2. How To Play\n   3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        std::cout << "Choose difficulty:\n"; // Choose difficulty
        std::cout << "\033[32m" << "1.Easy" << std::endl;
        std::cout << "\033[33m" << "2.Medium" << std::endl;
        std::cout << "\033[31m" << "3.Hard" << std::endl;

        std::cin >> choiceDifficult;

        switch (choice) {
        case 1: {
            // Play the game


            switch (choiceDifficult) {

            case 1: {
                //Easy level
                const char words[][140] = { "apple", "mango", "pearl", "lemon", "grape", "peach" "about", "other", "which", "their", "there", "would", "could", "these", "every", "after",
        "think", "being", "those", "never", "where", "shall", "world", "under", "still", "great",
        "right", "place", "again", "small", "found", "given", "white", "state", "house", "might",
        "night", "often", "water", "since", "early", "until", "among", "later", "sense", "began",
        "least", "human", "power", "point", "asked", "money", "study", "young", "known", "times",
        "heart", "group", "whole", "words", "means", "above", "light", "white", "order", "class",
        "bring", "today", "large", "story", "among", "music", "field", "worth", "works", "below",
        "black", "happy", "words", "lives", "terms", "makes", "month", "clear", "truth", "quite",
        "court", "mind", "heard", "learn", "south", "north", "build", "trade", "peace", "shows",
        "helps", "check", "claim", "dream", "based", "reach", "event", "style", "wrong", "force",
        "focus", "local", "stage", "broke", "wrote", "calls" };
                
                const char* word = words[rand() % 130]; // Choose a random word
                char guess[6];               // The player's guess
                const int maxTries = 6;      // Number of attempts allowed

                std::cout << "\nWelcome to Wordle! You have " << maxTries << " attempts to guess the word.\n";
                std::cout << "Hints: '*' means correct letter and position, '+' means correct letter but wrong position.\n";
                std::cout << "Hint for the word: This is a fruit and the word starts with a capital letter.\n";

                bool won = false;

                for (int attempt = 1; attempt <= maxTries; ++attempt) {
                    std::cout << "\nAttempt " << attempt << " - Enter your 5-letter word: " << std::endl;

                    std::cout << "+------+" << std::endl;
                    std::cin >> guess;
                    std::cout << "+------+" << std::endl;

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
                        std::cout << "Please enter a valid 5-letter word.\n";
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

                    std::cout << "Feedback: ";
                    for (int i = 0; i < 5; ++i) {
                        if (feedback[i] == '*')
                            std::cout << "\033[1;32m" << guess[i] << "\033[0m"; // Green for correct
                        else if (feedback[i] == '+')
                            std::cout << "\033[1;33m" << guess[i] << "\033[0m"; // Yellow for misplaced
                        else
                            std::cout << "\033[1;31m" << guess[i] << "\033[0m"; // Red for incorrect
                    }
                    std::cout << std::endl;

                    if (correct) {
                        std::cout << "Congratulations! You've guessed the word: " << word << "!\n";
                        won = true;
                        break;
                    }
                }

                if (!won) {
                    std::cout << "Sorry! You've used all your attempts. The word was: " << word << ". Better luck next time!\n";
                }

                static int wins = 0, losses = 0;
                if (won) {
                    ++wins;
                }
                else {
                    ++losses;
                }

                std::cout << "\nYour score: " << wins << " Wins, " << losses << " Losses\n";
                // Adds scoring


                break;
            }

            case 2: {
                // Medium level
                const char words[][140] = { "angle", "basic", "begin", "brick", "brown", "charm", "clean", "cloud", "coast", "dance",
"earth", "eagle", "flash", "glory", "happy", "humor", "image", "joint", "magic", "march",
"metal", "music", "olive", "organ", "party", "plant", "quiet", "river", "scope", "shelf",
"smart", "sound", "space", "stone", "sweet", "table", "taste", "tower", "trust", "union",
"value", "verse", "voice", "worth", "about", "above", "among", "build", "cause", "claim",
"close", "could", "dream", "early", "every", "field", "force", "found", "great", "house",
"human", "least", "light", "never", "north", "other", "peace", "place", "point", "power",
"right", "sense", "shall", "small", "south", "stage", "still", "style", "think", "times",
"under", "water", "white", "world", "young", "above", "break", "check", "court", "dream",
"fault", "glory", "heart", "ideal", "learn", "money", "shine", "words", "bring", "today",
"large", "story", "music", "field", "worth", "works", "below", "black", "happy", "lives",
"terms", "makes", "month", "clear", "truth", "quite", "court", "mind", "heard", "south",
"north", "build", "trade", "peace", "shows", "helps", "check", "claim", "based", "reach",
"event", "style", "wrong", "force", "focus", "local", "stage", "broke", "wrote", "calls" };
                
                const char* word = words[rand() % 130]; // Choose a random word
                char guess[6];               // The player's guess
                const int maxTries = 6;      // Number of attempts allowed

                std::cout << "\nWelcome to Wordle! You have " << maxTries << " attempts to guess the word.\n";
                std::cout << "Hints: '*' means correct letter and position, '+' means correct letter but wrong position.\n";
                std::cout << "Hint for the word: This is a fruit and the word starts with a capital letter.\n";

                bool won = false;

                for (int attempt = 1; attempt <= maxTries; ++attempt) {
                    std::cout << "\nAttempt " << attempt << " - Enter your 5-letter word: " << std::endl;

                    std::cout << "+------+" << std::endl;
                    std::cin >> guess;
                    std::cout << "+------+" << std::endl;

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
                        std::cout << "Please enter a valid 5-letter word.\n";
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

                    std::cout << "Feedback: ";
                    for (int i = 0; i < 5; ++i) {
                        if (feedback[i] == '*')
                            std::cout << "\033[1;32m" << guess[i] << "\033[0m"; // Green for correct
                        else if (feedback[i] == '+')
                            std::cout << "\033[1;33m" << guess[i] << "\033[0m"; // Yellow for misplaced
                        else
                            std::cout << "\033[1;31m" << guess[i] << "\033[0m"; // Red for incorrect
                    }
                    std::cout << std::endl;

                    if (correct) {
                        std::cout << "Congratulations! You've guessed the word: " << word << "!\n";
                        won = true;
                        break;
                    }
                }

                if (!won) {
                    std::cout << "Sorry! You've used all your attempts. The word was: " << word << ". Better luck next time!\n";
                }

                static int wins = 0, losses = 0;
                if (won) {
                    ++wins;
                }
                else {
                    ++losses;
                }

                std::cout << "\nYour score: " << wins << " Wins, " << losses << " Losses\n";
                // Adds scoring
                break;
            }

            case 3: {
                // Hardest level
                const char words[][140] = { "axiom", "fjord", "zephyr", "quirk", "crypt", "myths", "vapid", "gnome", "epoch", "lapse",
"plume", "shard", "chasm", "drear", "niche", "scorn", "brisk", "glint", "braid", "vital",
"rivet", "spurn", "tacit", "flint", "amend", "blitz", "abyss", "throb", "siege", "pivot",
"quell", "aloft", "ember", "guise", "hover", "joust", "prone", "smirk", "stoic", "grasp",
"crave", "bluff", "sworn", "wrung", "knack", "gleam", "cling", "bleak", "sting", "wharf",
"heist", "crisp", "girth", "mirth", "realm", "siren", "strum", "wield", "lurid", "tryst",
"aphid", "blurb", "covet", "wince", "flair", "infer", "latch", "mossy", "quash", "squib",
"taunt", "trove", "uncut", "whelp", "zonal", "brash", "hymen", "slink", "snare", "tweak",
"vista", "spurt", "prowl", "thorn", "frisk", "brine", "guise", "haunt", "quilt", "vault",
"wryly", "brood", "froth", "scowl", "vouch", "pluck", "shove", "twang", "cling", "lofty",
"slant", "blaze", "spurn", "witty", "grunt", "quash", "brawn", "brunt", "glare", "surge",
"relic", "vexed", "wrath", "swirl", "crest", "chant", "gruff", "grove", "gaunt", "spine",
"whirl", "flock", "brave", "clang", "froze", "gorge", "lurch", "pique", "shard", "verve" };
                
                const char* word = words[rand() % 130]; // Choose a random word
                char guess[6];               // The player's guess
                const int maxTries = 6;      // Number of attempts allowed

                std::cout << "\nWelcome to Wordle! You have " << maxTries << " attempts to guess the word.\n";
                std::cout << "Hints: '*' means correct letter and position, '+' means correct letter but wrong position.\n";
                std::cout << "Hint for the word: This is a fruit and the word starts with a capital letter.\n";

                bool won = false;

                for (int attempt = 1; attempt <= maxTries; ++attempt) {
                    std::cout << "\nAttempt " << attempt << " - Enter your 5-letter word: " << std::endl;


                    std::cin >> guess;


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
                        std::cout << "Please enter a valid 5-letter word.\n";
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

                    std::cout << "Feedback: ";
                    for (int i = 0; i < 5; ++i) {
                        if (feedback[i] == '*')
                            std::cout << "\033[1;32m" << guess[i] << "\033[0m"; // Green for correct
                        else if (feedback[i] == '+')
                            std::cout << "\033[1;33m" << guess[i] << "\033[0m"; // Yellow for misplaced
                        else
                            std::cout << "\033[1;31m" << guess[i] << "\033[0m"; // Red for incorrect
                    }
                    std::cout << std::endl;

                    if (correct) {
                        std::cout << "Congratulations! You've guessed the word: " << word << "!\n";
                        won = true;
                        break;
                    }
                }

                if (!won) {
                    std::cout << "Sorry! You've used all your attempts. The word was: " << word << ". Better luck next time!\n";
                }

                static int wins = 0, losses = 0;
                if (won) {
                    ++wins;
                }
                else {
                    ++losses;
                }

                std::cout << "\nYour score: " << wins << " Wins, " << losses << " Losses\n";
                // Adds scoring
                break;

                break;
            }


            }
            break;
        }

        case 2:
            // Tutorial on how to play
            std::cout << "\nHow to Play:\n";
            std::cout << "1. Start with a Guess: Enter any valid 5-letter word to gather clues about the hidden word.\n";
            std::cout << "2. Check the Feedback: '*' = correct position, '+' = correct letter but wrong position, '-' = not in the word.\n";
            std::cout << "3. Refine Your Guesses: Use feedback to make smarter guesses; avoid repeating incorrect letters.\n";
            std::cout << "4. Win or Lose: Guess the word in 6 tries to win; otherwise, the hidden word is revealed.\n";
            break;

        case 3:
            // Exit the game
            std::cout << "Goodbye! Thanks for playing.\n";
            return; // Exit the menu
            break;

        default:
            std::cout << "Invalid option. Please choose 1, 2, or 3.\n";
            break;
        }
    } while (choice != 3);
}

int main() {
    do { // Replay option
        Game();
        std::cout << "\nDo you want to play again? (y/n): ";
        char replay;
        std::cin >> replay;
        if (replay != 'y' && replay != 'Y') {
            break;
        }
    } while (true);
    return 0;
}
