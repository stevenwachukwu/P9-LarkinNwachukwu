/*Written by Steve Nwachukwu and Nick Larkin*/
#include "dice.hpp"

Dice::Dice(int n){
    nDice = n;
    diceVal = new int [nDice];
    srand(time(NULL));

} //constructor for the dice

Dice::~Dice() {
    delete [] diceVal;
} //destructor for the dice

const int* Dice::
roll () {
    for (int j = 0; j < nDice; j++) {
        diceVal [j] = rand()%6+1;
    }
    return diceVal;
} //the dice value array

ostream& Dice::print(ostream& diceOutput) {
    for (int j = 0; j < nDice; j++) {
        diceOutput << diceVal [j] << " ";
    }
    return diceOutput;

} //print function for the program

CantStopDice::CantStopDice():Dice(4) {}

const int* CantStopDice::newRoll() {
    int combinedPair;
    Dice::roll();
    cout << "Please select the most important name and dice pair for this game:\n";
    const int* diceArray = Dice::roll();
    cout << "Output A: " << diceArray[0];
    cout << "\nOutput B: " << diceArray[1];
    cout << "\nOutput C: " << diceArray[2];
    cout << "\nOutput D: " << diceArray[3];
    cin >> combinedPair;
    while(true) {
        if (combinedPair == 1 || combinedPair == 2) {
            cout << "Selected input works!" << endl;
            break;
        } else {
            cout << "Please try again!" << endl;
            cin >> combinedPair;
        }
    }
    if (combinedPair == 1) {
        dicePair[0] = diceArray[0] + diceArray[1];
        dicePair[1] = diceArray[2] + diceArray [3];
    }
    else if (combinedPair == 2) {
        dicePair[0] = diceArray[2] + diceArray [3];
        dicePair[1] = diceArray[0] + diceArray[1];
    }
    else {
        cout << "Sorry but your input was not validated!" << endl;
    }
    ///////////////////////////////////////////

    ///////////
    
   FakeDice::FakeDice() : CantStopDice(),inputfile(FakeDice.txt){}
   FakeDice::~FakeDice(){
       inputfile.close;
    }

    void FakeDice::roll() { // The roll used for fake dice
        if (!FakeDice.txt.is_open()) {
            cerr << "Error: Input file is not open" << endl;
            fatal(); // Terminate the program if file is not open
        } else {
            for (int i = 0; i < 4; ++i) {
                inputFile >> diceValues[i]; // the 4 dice sample rolls
            }
            Pair[0] = dicepair[0] + diceArray[1];
            Pair[1] = dicepair[2] + diceArray[3];
        }

        FakeDice.txt >> string;
        if (code == "STOP") {
            // End the turn and go to the next player
        } else if (code == "ROLL") {
            // Continue the turn
        } else {
            if (FakeDice.txt.eof) {
                fatal();
                // if the game doesn't finish in the given time fatal is called
            }
        }
    }
}
/////////////
    return pairValues;
}
