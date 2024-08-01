#include <iostream>
#include <random>

using namespace std;

void NumberGuessingGame(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    int numberToGuess = dis(gen);
    int userGuess = 0;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I'm thinking of a number between 1 to 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;
        double attempts;
        attempts++;

        if (userGuess > numberToGuess){
            cout << "Too high! Try again." << endl;
        }else if (userGuess < numberToGuess){
            cout << "Too low! Try again." << endl;
        }else{
            cout << "Congratulations! You guessed the number in " << attempts << " attempts. " << endl;
        }

    } while (userGuess != numberToGuess);
}

int main(){
    char playAgain;
    do{
        NumberGuessingGame();
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}