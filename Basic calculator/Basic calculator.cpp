#include <iostream>
using namespace std;

// Functions

void Addition() {
    double num, sum = 0;
    cout << "Enter numbers to add (enter any non-numeric character to stop):" << endl;

    while (cin >> num) {
        sum += num;
    }

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "The result is: " << sum << endl;
}

void Subtraction() {
    double num, result = 0;
    cout << "Enter first number: " << endl;
    cin >> num;
    result = num;

    cout << "Enter numbers to subtract (enter any non-numeric character to stop):" << endl;

    while (cin >> num) {
        result = result - num;
    }

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "The result is: " << result << endl;
}

void Multiplication() {
    double num, sum = 1;
    cout << "Enter numbers to multiply (enter any non-numeric character to stop):" << endl;

    while (cin >> num) {
        sum = sum * num;
    }

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "The result is: " << sum << endl;
}

void Division() {
    double num, result = 0;
    cout << "Enter first number: " << endl;
    cin >> num;
    result = num;

    cout << "Enter numbers to subtract (enter any non-numeric character to stop):" << endl;

    while (cin >> num) {
        if (num == 0) {
            cout << "Error: Division by zero is not allowed." << endl;
            return;
        }
        result = result / num;
    }

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "The result is: " << result << endl;
}

int main() {
    int choice;
    do {
        cout << endl;
        cout << "W E L C O M E   T O   O U R   C A L C U L A T O R   P R O G R A M" << endl;
        cout << endl;
        cout << " _____________________\n"
                "|  _________________  |\n"
                "| |              0. | |\n"
                "| |_________________| |\n"
                "|  ___ ___ ___   ___  |\n"
                "| | 7 | 8 | 9 | | / | |\n"
                "| |___|___|___| |___| |\n"
                "| | 4 | 5 | 6 | | * | |\n"
                "| |___|___|___| |___| |\n"
                "| | 1 | 2 | 3 | | - | |\n"
                "| |___|___|___| |___| |\n"
                "| | . | 0 | = | | + | |\n"
                "| |___|___|___| |___| |\n"
                "|_____________________|" << endl;
        cout << "Select Operation:" << endl;
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose your option: " << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                Addition();
                break;
            }
            case 2: {
                Subtraction();
                break;
            }
            case 3: {
                Multiplication();
                break;
            }
            case 4: {
                Division();
                break;
            }
            case 5: {
                cout << "Exiting" << endl;
                break;
            }
            default:
                cout << "Invalid choice !!!" << endl;
        }
    } while (choice != 5);
    return 0;
}