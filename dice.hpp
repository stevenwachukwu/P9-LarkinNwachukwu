/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef dice
#define dice
#include "FakeDice.txt"

#include "tools.hpp"

class Dice {
private:
    int nDice;
    int* diceVal;

public:
    Dice(int n);
    virtual ~Dice();
    ostream& print(ostream&);
    virtual const int* roll();
};

class CantStopDice:public Dice {
private:
    int dicePair [2];
public:
    CantStopDice();
    virtual const int* newRoll();
};

class FakeDice:public CantStopDice {
private:
    ifstream inputFile;

public:
    FakeDice();
    roll();
    virtual ~FakeDice() override;
    virtual const int *roll() override;
};

inline ostream& operator << (ostream& output, Dice& d) {return d.print(output);}

#endif
