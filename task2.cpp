// TASK 2: SIMPLE CALCULATOR

#include <iostream>
using namespace std;

int main() {
    double a, b;
    char optr;
    char loopBreaker = 'y'; // To keep the calculator working in a loop

    cout << "\t\tNashwah's Calculator\n\n";

    while (loopBreaker == 'y') {
        cout << "Enter the first number: ";
        cin >> a;

        cout << "Enter the second number: ";
        cin >> b;

        cout << "Choose an operator (+, -, *, /): ";
        cin >> optr;

        double result;

        switch (optr) {
            case '+':
                result = a + b;
                cout << "Result: " << result << endl;
                break;
            case '-':
                result = a - b;
                cout << "Result: " << result << endl;
                break;
            case '*':
                result = a * b;
                cout << "Result: " << result << endl;
                break;
            case '/':
                if (b != 0) { // Dealing with division by zero
                    result = a / b;
                    cout << "Result: " << result << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Invalid operation." << endl;
                break;
        }

        cout << "Do you want to continue? (y / n): ";
        cin >> loopBreaker;
    }

    return 0;
}
