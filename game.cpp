/*Written by Steve Nwachukwu and Nick Larkin*/

#include "game.hpp"

Game::Game(){
    int diceOptions;
    getNewPlayer();
    cout << "Which one of the dices do you want to choose?" << endl;
    cout << "\nOption 1: Regular Dice    Option 2: CantStopDice     Option 3: FakeDice" << endl;
    cin >> diceOptions;
    if (diceOptions == 1) {
        dices = new Dice (4);
    }
    else if (diceOptions == 2) {
        dices = new CantStopDice();
    }
    else if (diceOptions == 3) {
        dices = new FakeDice();
        inputFile2.open("FakeRoll.txt");
        if (!inputFile2.is_open()) {
            fatal("Error: Failed to open FakeRoll");
        }
    }
    else {
        cout << "Sorry I couldn't validate your input!" << endl;
    }
} //constructor for game

Game::~Game() {delete dices;} //destructor for game

void Game::getNewPlayer() {
    string playerName;
    char color;
    cout << "Enter in the player's name:\n" << endl;
    cin >> playerName;
    cout << "Which available color do you want? (Please enter the first letter)" << endl;
    cout << "\nOptions: White, Orange, Yellow, Green, Blue" << endl;
    cin >> color;
    int index = 0;
    for (int k = 0; k < 1; k++) {
        string availChar = "WOYGB";
        while (true) {
            if (availChar.find(color) != string::npos) {
                switch (color) {
                    case 'W':
                        index = 0;
                        break;
                    case 'O':
                        index = 1;
                        break;
                    case 'Y':
                        index = 2;
                        break;
                    case 'G':
                        index = 3;
                        break;
                    case 'B':
                        index = 4;
                        break;
                }
                cout << "Color input accepted!" << endl;
                break;
            } else {
                cout << "Color input invalid, please try again!" << endl;
                cin >> color;
            }
        }
    }
    player1 = Player(playerName, (ECcolor)index); //calling the Player constructor
    Printer.startTurn(&player1);
}

void Game::oneTurn(Player* pp) {
    int gameOptions;
    cout << "\nPlease pick one of the following options: " << endl;
    cout << "1. Roll    2. Stop    3. Resign" << endl;
    cin >> gameOptions; //comment this out whenever you want option 1 or 2 (default setting)
    //inputFile2 >> gameOptions; //comment this out whenever you want option 3
    if (gameOptions == 1) {
     Gameroll();
    }
    else if (gameOptions == 2) {
        Gamestop();
    }
    else {
        cout << "Sorry, couldn't register your input!" << endl;
    }
}

void Game::Gameroll() {
    cout << "\nPlease select one pair of dice: " << endl;
    const int* diceArray = dices->roll();
    cout << "Output A: " << diceArray[0];
    cout << "\nOutput B: " << diceArray[1];
    cout << "\nOutput C: " << diceArray[2];
    cout << "\nOutput D: " << diceArray[3];
    int firstVal;
    int secondVal;
    cout << "\nPlease select any of the dice values and letters (specifically their numbers): " << endl;
    cin >> firstVal;
        while (true) {
            if (firstVal == diceArray[0] || firstVal == diceArray[1] || firstVal == diceArray[2] ||
            firstVal == diceArray[3]) {
            cout << "The first value was accepted!" << endl;
            cout << "Please enter in the second value: " << endl;
            break;
        }
            else {
                cout << "The first value was not accepted, please try again!" << endl;
                cin >> firstVal;
        }
   }
        cin >> secondVal;
        while (true) {
            if (secondVal == diceArray[0] || secondVal == diceArray[1] || secondVal == diceArray[2] ||
                secondVal == diceArray[3]) {
                cout << "The second value was accepted!\n";
                break;
            } else {
                cout << "The second value was not accepted, please try again!\n" << endl;
                cin >> secondVal;
            }
        }
    int arraySum = 0;
    for (int i = 0; i < 4; i++) {
         arraySum +=diceArray[i];
    }
    int totalVal = (arraySum) - (firstVal + secondVal); //this determines which slot "T" would be in
    Printer.print(cout);
    bool Boardval = Printer.move(totalVal);
    if (Boardval == true) {
        Printer.print(cout);
    }
    else {
    Printer.bust();
    }
} //function utilized to run the roll option

void Game::Gamestop() {
    Printer.stop();
    cout << Printer;
} //function utilized to run the stop option

void Game::start() {
    int endOptions;
    oneTurn(&player1);
    cout << "\nDo you want to play again? " << endl;
    cout << "1. Yes  2. No";
    cin >> endOptions;
    if (endOptions == 1) {
        start();
    }
    else {
        cout << "The game has been terminated!" << endl;
        Printer.stop();
    }
}
