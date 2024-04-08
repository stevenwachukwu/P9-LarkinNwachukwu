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
    
    FakeDice::FakeDice() : CantStopDice(){
       inputFile.open("FakeDice,txt");
       if (!inputFile.is_open()){
           cerr << "Error: Failed to open FakeDice "  << endl;
           fatal();
       }
    }
FakeDice::~FakeDice() {
    inputFile.close();
}
/////////////
const int* FakeDice:: roll() {
    int* Pair = new int[2];
    for (int i = 0; i < 4; ++i) {
        inputFile >> diceVal[i];
    }

    Pair[0] = diceVal[0] + diceVal[1];
    Pair[1] = diceVal[2] + diceVal[3];

    return Pair;
}
