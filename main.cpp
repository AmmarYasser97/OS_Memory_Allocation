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

    list<Block>::iterator it = m.Find_Iterator_By_Start(0);

    cout << "iterator" << endl;

    m.Remove_Block(it);
    //error here
    cout << "REMOVED " << endl;

    m.Print_Memory();
    /* omar test
    Memory m(500);

    Process p1;
    p1.name = "Chrome";
    p1.num_of_segments = 3;
    p1.segments = vector<Segment>{
        Segment{"Code", 50},
        Segment{"Data", 100},
        Segment{"Variables", 80},
    };

    m.Add_Block("Old Process", "", 0, 50);
    m.Add_Block("Old Process", "", 150, 20);
    m.Add_Block("Old Process", "", 300, 110);

    m.best_fit(p1);

    m.Print_Memory();
    */

    /* //ammar test
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
    */

    return 0;
}