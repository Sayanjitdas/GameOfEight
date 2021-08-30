// GameOfEight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Game of Eight

/*
    important points:
        1. game has 2 players
        2. game starts with the initial number 8 (initial number)
        3. player should always choose between 1 to 3 (chosen number)

        do{
            
            PlayTheGame()
        
        }while(WantToPlayAgain())

        PlayTheGame(){
            
            initialNumber = 8
            playerOne = 0
            playerTwo = 1
            activePlayer = playerOne
            lastChosenNumber = 0

            while(initialNumber <= 0){
                
                choice = UserChoice(lastChosenNumber)
                initialNumber = initialNumber - choice
                if(initialNumber > 0){
                    lastChosenNumber = choice
                    activePlayer = playerTwo if playerone was before and viceversa     
                }
            }

            DisplayWinner(activePlayer,playerOne,playerTwo)

        
        }

        UserChoice(lastChosenNumber){
        
            you have choices lastChosenNumber != 1 , lastchosenNumber != 2 , lastChosenNumber != 3

            return choice
        
        }

        DisplayWinner(activePlayer,initialNumber,playerOne,playerTwo){
            
            if activePlayer == playerOne && initialNumber == 0
                    "Player one is the winner"
            else if activePlayer == playerTwo && initialNumber == 0
                    "Player Two is the winner"
            else if activePlayer == playerOne && initialNumber < 0
                    "Player two is the winner"
            else if activePlayer == playerTwo && initialNumber < 0
                    "Player one is the winner"
        }

        WantToPlayAgain(){
            
            userInput = Y or N
            return input == Y
        }

*/


#include <iostream>
using namespace std;

//function declaration
void PlayTheGame();
int UserChoice(int lastChosenNumber,int activePlayer);
void DisplayWinner(int activePlayer,int initialNumber, int playerOne, int playerTwo);
bool WantToPlayAgain();

//global constants
int IGNORE_CASE_NUMBER = 256;

int main()
{
    do {
        PlayTheGame();
    } while (WantToPlayAgain());

    return 0;
}

void PlayTheGame() {
    
    int initialNumber = 8;
    int playerOne = 0;
    int playerTwo = 1;
    int activePlayer = playerOne;
    int lastChosenNumber = 0;

    cout << "GAME OF EIGHT" << endl;

    while (initialNumber > 0) {
        
        int choice;
        choice = UserChoice(lastChosenNumber,activePlayer);
        initialNumber = initialNumber - choice;
        if (initialNumber > 0) {
            lastChosenNumber = choice;
            if (activePlayer == playerOne)
                activePlayer = playerTwo;
            else
                activePlayer = playerOne;
        }

    }

    DisplayWinner(activePlayer, initialNumber, playerOne, playerTwo);
}

int UserChoice(int lastChosenNumber,int activePlayer) {

    int choice;
    bool failure;

    cout << (activePlayer == 0 ? "Player One" : "Player Two") << endl;
    cout << "Enter your choice between ";
    if (lastChosenNumber != 1)
        cout << 1 << " ";
    if (lastChosenNumber != 2)
        cout << 2 << " ";
    if (lastChosenNumber != 3)
        cout << 3 << " ";
    cout << endl;
    
    do {
        failure = false;
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(IGNORE_CASE_NUMBER, '\n');
            failure = true;
            cout << "Incorrect input" << endl;
        }
    } while (failure);

    return choice;

}

void DisplayWinner(int activePlayer, int initialNumber, int playerOne, int playerTwo) {

    if (activePlayer == playerOne && initialNumber == 0)
        cout << "Player one is the winner" << endl;
    else if (activePlayer == playerTwo && initialNumber == 0)
        cout << "Player Two is the winner" << endl;
    else if (activePlayer == playerOne && initialNumber < 0)
        cout << "Player two is the winner" << endl;
    else if (activePlayer == playerTwo && initialNumber < 0)
        cout << "Player one is the winner" << endl;
}

bool WantToPlayAgain() {

    char choice;
    bool failure;
    
    do {
        failure = false;
        cout << "Want to play again? (y/n)";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(IGNORE_CASE_NUMBER, '\n');
            cout << "Incorrect input" << endl;
            failure = true;
        }
    } while (failure);

    return islower(choice) == 'y';

}