//Written by Steve Nwachukwu and Nick Larkin
#include "tools.hpp"
#include "player.hpp"
using upp = unique_ptr<Player>;

class Cell {
private:
    upp wrapper;
    Cell* next;
public:Cell (upp wrapper):wrapper(move (wrapper)) ,next (nullptr){}
    friend class CList;
    ~Cell() = default;
};
//---------------------
class CList {
private:
    int cellCount;
    Cell* head = nullptr;
    Cell* tail;
    Cell* currentCell;
public:
    CList();
    ~CList();
    int count () {return cellCount;};
    bool empty();
    ostream& print(ostream& CListOutput);
    void addCell(Cell* it);
    void init();
    Cell* next();
    void remove();
};
inline ostream& operator << (ostream&  output, CList& c) {return c.print(output);}
