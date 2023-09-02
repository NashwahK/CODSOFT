// TASK 1: NUMBER GUESSING GAME

#include <iostream>
#include <cstdlib> // Used for random number generation
#include <ctime> // Used for unique seeding
using namespace std;

int main() {
    /* Seeding with time to generate a unique number.
    This method of number generation ensures increased 
    diversity in results, since the seed is different each time.
    This method uses time elapsed since epoch (1/1/70). */ 
    srand(static_cast<unsigned int>(time(nullptr)));

    // Converting the number within the range of 0-100
    int secretNum = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to NumberGenie!\n";
    cout << "The genie is thinking of a number between 1 and 100. Try to guess it!\n\n";

    do {
        cout << "What's your guess?: ";
        cin >> guess;
        attempts++;

        if (guess < secretNum) {
            cout << "Not quite right. Try higher!\n\n";
        } else if (guess > secretNum) {
            cout << "Not quite right. Try lower!\n\n";
        } 
        else {
            cout << "Congratulations! You guessed the number " << secretNum << 
            " in " << attempts << " attempts.\n";
        }
    } while (guess != secretNum);

    return 0;
}

