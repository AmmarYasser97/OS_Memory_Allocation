//
// Created by Mohamed Hesham on 5/2/19.
// Tested by Ammar Yasser on 5/3/19.
//

#include "memory.h"

using namespace std;

struct Process
{
    string name;
    int number_of_segments;
    vector<Block> segments;
};

Memory::Memory(int Size) : Initial_Block("", "", 0, Size, false)
{
    size = Size;
    memory.push_back(Initial_Block);
}

list<Block>::iterator Memory::Find_Iterator(int start, int end)
{
    list<Block>::iterator i;
    for (i = memory.begin(); i != memory.end(); i++)
    {
        if ((*i).getStart() <= start && (*i).getEnd() >= end)
        {
            if (!((*i).getType()) && (*i).getEnd() >= end)
            {
                return i;
            }
            else
            {
                return memory.end();
            }
        }
    }
    return memory.end();
}

bool Memory::Is_Empty_Boolean(int start, int end)
{
    list<Block>::iterator i;
    for (i = memory.begin(); i != memory.end(); i++)
    {
        if ((*i).getStart() <= start && (*i).getEnd() >= end)
        {
            if (!((*i).getType()) && (*i).getEnd() >= end)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

list<Block>::iterator Memory::Find_Iterator_By_Start(int start)
{
    list<Block>::iterator i;
    for (i = memory.begin(); i != memory.end(); i++)
    {
        if ((*i).getStart() == start)
        {
            return i;
        }
    }
    return memory.end();
}

void Memory::Add_Block(string PName, string SName, int Start, int Size)
{

    list<Block>::iterator i;
    i = Find_Iterator(Start, Start + Size - 1);

    if ((*i).getStart() == Start && (*i).getSize() == Size)
    {
        (*i).setProcessName(PName);
        (*i).setSegmentName(SName);
        (*i).setType(true);
    }

    else if ((*i).getStart() == Start)
    {
        Block p1(PName, SName, Start, Size, true);
        Block p2("", "", Start + Size, (*i).getSize() - Size, false);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
    }

    else if ((*i).getEnd() == (Start + Size - 1))
    {
        Block p1("", "", (*i).getStart(), (*i).getSize() - Size, false);
        Block p2(PName, SName, (*i).getEnd() - Size, Size, true);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
    }

    else
    {
        Block p1("", "", (*i).getStart(), Start - (*i).getStart(), false);
        Block p2(PName, SName, Start, Size, true);
        Block p3("", "", Start + Size, (*i).getSize() - (Start - (*i).getStart()) - Size, false);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
        memory.insert(i, p3);
    }
}

void Memory::Compact_Blocks(list<Block>::iterator i)
{
    //i represents the iterator of the first block
    int start;
    int size_1; //size of the first block
    int size_2; //size of the second block

    start = (*i).getStart();
    size_1 = (*i).getSize();
    ++i;
    size_2 =  (*i).getSize();

    --i;

    Block p1("", "", start, size_1+size_2, false);
    i = memory.erase(i);
    i = memory.erase(i);
    memory.insert(i, p1);
}

void Memory::Remove_Block(list<Block>::iterator i)
{
    bool Prev_Type,Next_Type;
    int Prev_Start,Current_Start;
    (*i).setProcessName("");
    (*i).setSegmentName("");
    (*i).setType(false);

    Current_Start = (*i).getStart();

    /*Compacting Algorithm if the previous and next is empty compact twice if previous or next compact once*/

    i--;
    Prev_Start = (*i).getStart();
    if(i == memory.begin())
    {
        Prev_Type = true;
    }
    else
    {
        Prev_Type = (*i).getType();
    }

    i++;
    i++;

    if(i == memory.end())
    {
        Next_Type = true;
    }
    else {
        Next_Type = (*i).getType();
    }


    if(!(Prev_Type) && !(Next_Type))
    {

        i = Find_Iterator_By_Start(Prev_Start);
        Compact_Blocks(i);
        i = Find_Iterator_By_Start(Prev_Start);
        Compact_Blocks(i);
    }
    else if(!(Prev_Type))
    {
        i = Find_Iterator_By_Start(Prev_Start);
        Compact_Blocks(i);
    }
    else if(!(Next_Type))
    {
        i = Find_Iterator_By_Start(Current_Start);
        Compact_Blocks(i);
    }



}

void Memory::Print_Memory()
{
    for (auto it = memory.begin(); it != memory.end(); ++it)
    {
        cout << "size of " << it->getProcessName() << ":" << it->getSegmentName() << " is " << it->getSize()
             << "\t starting from: " << it->getStart() << " till: " << it->getEnd() << " and its type: " << it->getType()
             << endl;
    }
}
