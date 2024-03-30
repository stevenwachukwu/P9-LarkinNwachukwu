/*Written by Steve Nwachukwu and Nick Larkin*/
#ifndef player_hpp
#define player_hpp
#include "Enum.hpp"
#include "tools.hpp"

class Player {
private:
    string playerName;
    ECcolor colorVal;
    int score = 0;
    int scoreboard [3] = {1,2,3};


public:
    Player() = default;
    //constructors and destructor for player
    Player(string playerName, ECcolor color);
    ~Player() = default;
    ECcolor color();
    ostream& print(ostream& playerOutput);
    int getScore();
    bool wonColumn(int colNum);
};
inline ostream& operator << (ostream&  output, Player& p) {return p.print(output);}
#endif
