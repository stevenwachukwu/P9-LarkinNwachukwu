//Written by Steve Nwachukwu and Nick Larkin
#include "CList.hpp"

CList::CList() : cellCount(0), head(nullptr), tail(nullptr), currentCell(nullptr) {} //constructor for CList

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
return cellCount == 0;
}

ostream& CList::print(ostream& CO) {
    currentCell = head;
    if (cellCount == 0) {
        return CO;
    }
    for (int i = 0; i < cellCount; i++) {
        currentCell->wrapper->print(CO);
        currentCell = currentCell -> next;
    }
    return CO;
} //CO is the shortened identifier of the output

void CList::addCell(Cell *it) {
if (head == nullptr && tail == nullptr) {
    head = it;
    tail = it;
    currentCell = head;
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
    if (currentCell == nullptr) {
        return;
    }
    if (head == tail) {
        delete currentCell;
        head = tail = currentCell = nullptr;
        cellCount = 0;
        return;
    }
    Cell* prevCell = head;
    while (prevCell->next != currentCell) {
        prevCell = prevCell->next;
    }
    prevCell->next = currentCell->next;
    if (currentCell == head) {
        head = head->next; // the head updates whenever the removed cell was the head
    }
    if (currentCell == tail) {
        tail = prevCell; // the tail updates whenever the removed cell was the tail
    }
    delete currentCell;
    currentCell = prevCell;
    cellCount--;
}
