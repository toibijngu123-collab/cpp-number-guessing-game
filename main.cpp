
#include <iostream>
#include <random>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());

    int difficulty, maxNumber, attempts = 0;
    int guess, score = 100;

    cout << "=== NUMBER GUESSING GAME ===\n";
    cout << "1. Easy (1-50)\n";
    cout << "2. Medium (1-100)\n";
    cout << "3. Hard (1-500)\n";
    cout << "Choose difficulty: ";
    cin >> difficulty;

    if (difficulty == 1)
        maxNumber = 50;
    else if (difficulty == 2)
        maxNumber = 100;
    else if (difficulty == 3)
        maxNumber = 500;
    else {
        cout << "Invalid difficulty!\n";
        return 0;
    }

    uniform_int_distribution<> dist(1, maxNumber);
    int secret = dist(gen);

    cout << "\nGuess a number from 1 to "
         << maxNumber << ".\n";

    while (true) {
        cout << "Your guess: ";

        if (!(cin >> guess)) {
            cout << "Invalid input!\n";
            return 0;
        }

        attempts++;

        if (guess == secret) {
            cout << "Correct! You win!\n";
            cout << "Attempts: " << attempts << '\n';
            cout << "Score: "
                 << max(0, score - (attempts - 1) * 10)
                 << '\n';
            break;
        }

        if (guess < secret)
            cout << "Too low!\n";
        else
            cout << "Too high!\n";
    }

    return 0;
}
