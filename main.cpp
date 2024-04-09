/*Written by Steve Nwachukwu and Nick Larkin*/
#include <iostream>
#include <fstream>
#include "dice.hpp"
#include "player.hpp"
#include "tools.hpp"
#include "Enum.hpp"
#include "column.hpp"
#include "game.hpp"
#include "board.hpp"
#include "CList.hpp"

//function prototypes for the program
void testGame(Game&);
void unitCList();
//-----------------------------------------------
int main() {
    Game gaming;
    gaming.start();
    //unitCList();
    bye();
    return 0;
}
//-----------------------------------------------

void unitCList() {
    ofstream CListNames ("CList.txt");

    upp test1 = make_unique <Player> (Player("Jacob", ECcolor::blue));
    upp test2 = make_unique <Player> (Player("Derek", ECcolor::green));
    upp test3 = make_unique <Player> (Player("Olivia", ECcolor::orange));
    upp test4 = make_unique <Player> (Player("Sadie", ECcolor::white));

Cell* person1 = new Cell (move (test1));
Cell* person2 = new Cell (move (test2));
Cell* person3 = new Cell (move (test3));
Cell* person4 = new Cell (move (test4));

CList obj;
obj.addCell(person1);
obj.addCell(person2);
obj.addCell(person3);
obj.addCell(person4);
obj.print(CListNames);
obj.init();
obj.next();
obj.remove();
obj.print(cout);

obj.remove();

obj.remove();

obj.remove();

upp test5 = make_unique <Player> (Player("Marcus", ECcolor::blue));
upp test6 = make_unique <Player> (Player("Kelly", ECcolor::green));
upp test7 = make_unique <Player> (Player("Maria", ECcolor::orange));
upp test8 = make_unique <Player> (Player("Lucas", ECcolor::white));

Cell* person5 = new Cell (move (test5));
Cell* person6 = new Cell (move (test6));
Cell* person7 = new Cell (move (test7));
Cell* person8 = new Cell (move (test8));

obj.addCell(person5);
obj.addCell(person6);
obj.addCell(person7);
obj.addCell(person8);

obj.init();
obj.next();
obj.next();
obj.next();
obj.next();
obj.print(CListNames);
} //the unit test for CList
