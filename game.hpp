/*Written by Steve Nwachukwu and Nick Larkin*/

#ifndef game
#define game

#include "tools.hpp"
#include "dice.hpp"
#include "column.hpp"
#include "player.hpp"
#include "board.hpp"

class Game {
private:
    Dice* dices;
    Player* player1;
    Board Play;
    void Gameroll();
    void Gamestop();


public:
    Game(); //the constructor for game
    ~Game(); //the destructor for game
    void getNewPlayer();
    void unitTest();
    void oneTurn(Player* pp);
    void start();
};
#endif
