//Written by Steve Nwachukwu and Nick Larkin
#include "CList.hpp"

CList::CList() {
    cellCount = 0;
    head = nullptr;
    tail = nullptr;
    currentCell = nullptr;
} //constructor for CList

CList::~CList() {
    currentCell = head;
    Cell* temp = currentCell -> next;
    for (int i = 0; i < cellCount; i++) {
        delete currentCell;
        currentCell = temp;
        temp = temp -> next;
    }
}; //destructor for CList

bool CList::empty() {
    if (cellCount == 0) {
        return true;
    }
    else {
        return false;
    }
}

ostream& CList::print(ostream& CListOutput) {
    Cell* temp = head;
    for (int i = 0; i < cellCount; i++) {
        currentCell = temp;
        temp = temp -> next;
        currentCell->wrapper.print(CListOutput);
    }
    return CListOutput;
}

void CList::addCell(Cell *it) {
if (head == nullptr && tail == nullptr) {
    head = it;
    tail = it;
    cellCount++;
    return;
}
tail -> next = it;
tail = it;
it -> next = head;
cellCount++;
}

void CList::init() {
    currentCell = head;
}

Cell* CList::next() {
    if (head == nullptr && tail == nullptr) {
        return nullptr;
    }
    currentCell = currentCell -> next;
     return currentCell;
}

void CList::remove() {
    Cell* cellStorage = head;
    if (head == nullptr && tail == nullptr) {
        return;
    }
    for (int i = 0; i < cellCount; i++) {
        if (cellStorage -> next == currentCell) {
            cellStorage -> next = currentCell -> next;
            //currentCell -> wrapper.print(cout);
            delete currentCell;
            currentCell = cellStorage;
            break;
        }
      cellStorage = cellStorage -> next;
    }
    if (head == nullptr) {
        head = tail -> next;
    }
    if (tail == nullptr) {
        tail = cellStorage;
    }
    cellCount--;
}

upp::upp(string userName,ECcolor Tilecolor) {
    playerName = Player(userName, Tilecolor);
} //the 
