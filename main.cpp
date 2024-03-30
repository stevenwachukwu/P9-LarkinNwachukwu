/*Written by Steve Nwachukwu and Nick Larkin*/
#include <iostream>
#include <fstream>
#include "dice.hpp"
#include "Player.hpp"
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
    //testGame(gameclass);
    gaming.start();
    //unitCList();
    bye();
    return 0;
}
//-----------------------------------------------
void testGame(Game& games) {
    games.unitTest();
} //the unit test for game

void unitCList() {
    ofstream CListNames ("CList.txt");

upp test1("Jacob", ECcolor::blue);
upp test2 ("Derek", ECcolor::green);
upp test3 ("Olivia", ECcolor::orange);
upp test4 ("Sadie", ECcolor::white);

Cell* person1 = new Cell (test1);
Cell* person2 = new Cell (test2);
Cell* person3 = new Cell (test3);
Cell* person4 = new Cell (test4);

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
obj.print(cout);

obj.remove();
obj.print(cout);

obj.remove();
obj.print(cout);

obj.print(CListNames);

upp test5("Marcus", ECcolor::blue);
upp test6 ("Kelly", ECcolor::green);
upp test7 ("Maria", ECcolor::orange);
upp test8 ("Lucas", ECcolor::white);

Cell* person5 = new Cell (test5);
Cell* person6 = new Cell (test6);
Cell* person7 = new Cell (test7);
Cell* person8 = new Cell (test8);

obj.addCell(person5);
obj.addCell(person6);
obj.addCell(person7);
obj.addCell(person8);

obj.next();
obj.next();
obj.next();
obj.next();

obj.print(CListNames);
} //the unit test for CList
