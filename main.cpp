#include "memory.h"

using namespace std;

int main()
{
    Memory m(500);

    m.Add_Block("P1", "code", 200, 100);
    m.Add_Block("P1", "data", 300, 30);
    m.Add_Block("P2", "data", 0, 50);
    m.Add_Block("P2", "code", 380, 22);
    m.Add_Block("P3", "code", 450, 10);

    m.Print_Memory();

    cout << "----------------------------------------" << endl;
    auto ptr = m.Find_Iterator_By_Start(200);
    m.Remove_Block(ptr);
    m.Print_Memory();

    cout << "----------------------------------------" << endl;

    ptr = m.Find_Iterator_By_Start(380);
    m.Remove_Block(ptr);
    m.Print_Memory();

    cout << "----------------------------------------" << endl;

    ptr = m.Find_Iterator_By_Start(0);
    m.Remove_Block(ptr);
    m.Print_Memory();

    cout << "----------------------------------------" << endl;


    return 0;
}