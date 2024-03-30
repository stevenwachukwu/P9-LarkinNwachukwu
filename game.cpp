/*Written by Steve Nwachukwu and Nick Larkin*/

#include "game.hpp"

Game::Game(){
    int diceOptions;
    getNewPlayer();
    cout << "Which one of the dices do you want to choose?" << endl;
    cout << "\nOption 1: Regular Dice    Option 2: CantStopDice" << endl;
    cin >> diceOptions;
    if (diceOptions == 1) {
        dices = new Dice(4);
    }
    else if (diceOptions == 2) {
        dices = new CantStopDice();
    }
    else {
        cout << "Sorry I couldn't validate your input!" << endl;
    }
} //constructor for game

Game::~Game() {delete dices;
                delete player1;} //destructor for game

void Game::getNewPlayer() {
    string playerName;
    string color;
    cout << "Enter in the player 1's name:\n" << endl;
    cin >> playerName;
    cout << "Enter in the player 1's color:\n" << endl;
    cin >> color;
    int index;
    for (int k = 0; k < 5; k++ ) {
        if (colorStrings[k] == color) {
            index = k;
            cout << "Color input accepted!" << endl;
        }
    }
    player1 = new Player(playerName, (ECcolor)index); //calling the Player constructor
    cout << "Enter in the player 2's name:\n" << endl;
    cin >> playerName;
    cout << "Enter in the player 2's color:\n" << endl;
    cin >> color;
    for (int k = 0; k < 5; k++ ) {
        if (colorStrings[k] == color) {
            index = k;
            cout << "Color input accepted!" << endl;
        }
    }
//    player2 = Player(playerName, (ECcolor)index); //calling the Player constructor
    Play.startTurn(player1);
}

void Game::unitTest() {
dices->roll();
cout << *dices << endl;
cout << player1 << endl;
//cout << player2 << endl;
Board play;
} //the unit test utilized for game

void Game::oneTurn(Player* pp) {
    int gameOptions;
    cout << "\nPlease pick one of the following options: " << endl;
    cout << "1. Roll    2. Stop    3. Resign" << endl;
    cin >> gameOptions;
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
    Dice* roll();
    cout << "\nPlease select one pair of dice: " << endl;
    dices->roll();
    const int* diceArray = dices->roll();
    cout << "Output A: " << diceArray[0];
    cout << "\nOutput B: " << diceArray[1];
    cout << "\nOutput C: " << diceArray[2];
    cout << "\nOutput D: " << diceArray[3];
    int firstVal;
    int secondVal;
    cout << "\nPlease select any of the dice values and letters: " << endl;
    cin >> firstVal;
    cin >> secondVal;
    int totalVal = (firstVal + secondVal);
    Play.print(cout);
    bool Boardval = Play.move(totalVal);
    if (Boardval == true) {
        Play.print(cout);
    }
    else {
    Play.bust();
    }
} //function utilized to run the roll option

void Game::Gamestop() {
    Play.stop();
    cout << Play;
} //function utilized to run the stop option

void Game::start() {
    int endOptions;
    oneTurn(player1);
    cout << "\nDo you want to play again? " << endl;
    cout << "1. Yes  2. No";
    cin >> endOptions;
    if (endOptions == 1) {
        start();
    }
    else {
        cout << "The game has been terminated!" << endl;
        Play.stop();
    }
}
