#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;

    cout << "I'm thinking of a number between 1 and 100. Can you guess it?" << endl;

    while (true)
    {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess < number)
        {
            cout << "Too low! Try again." << endl;
        }
        else if (guess > number)
        {
            cout << "Too high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You guessed the number." << endl;
            break;
        }
    }

    return 0;
}
