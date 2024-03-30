/*Written by Steve Nwachukwu and Nick Larkin*/
#include "board.hpp"
Board::Board() {
towerDetector[0] = 0;
towerDetector[1] = 0;
towerDetector[2] = 0;

for (int i = 2; i < 13; i++) {
    backBone[i] = new Column(i);
}

} //the constructor for board

Board::~Board(){
for (int i =2; i <13; i++) {
    delete backBone[i];
}

}  //this board destructor helps deal with dynamic allocation

ostream& Board::print (ostream& boardOutput) {
   for (int k = 2; k < 13; k++) {
       boardOutput << *backBone[k] << "| " << endl;
   }
   if (currentPlayer != nullptr) {
       boardOutput << *currentPlayer;
   }
   return boardOutput;
}

void Board::startTurn(Player* playerMoving) {
    currentPlayer = playerMoving;
    towerCounter = 0;
    towerDetector[0] = 0;
    towerDetector[1] = 0;
    towerDetector[2] = 0;
}

bool Board::move(int columnVal) {
if (backBone[columnVal]->getState() == 1 || backBone[columnVal]->getState() == 2 ) {
    return false;
     }
else if (towerCounter == 3) {
    return false;
    }
else {
 backBone[columnVal] -> move();
 for (int k = 0; k < towerCounter; k++) {
    if (towerDetector[k] == columnVal) {
        return true;
    }
 }
    towerDetector[towerCounter] = columnVal;
    towerCounter++;
    return true;
  }
}

void Board::stop() {
for (int k = 0; k < towerCounter; k++) {
    int columnNum = towerDetector[k];
    backBone[columnNum]->stop(currentPlayer);
    }
}

void Board::bust() {
for (int k = 0; k < towerCounter; k++) {
    int columnNum = towerDetector[k];
    backBone[columnNum]->bust(); //the function does not do anything yet because there's no instructions for it
    }
}
