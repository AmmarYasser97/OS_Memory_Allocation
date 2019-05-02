//
// Created by ammar on 5/2/19.
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
        if ((*i).getStart() <= start)
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
        if ((*i).getStart() > start)
        {
            i--;
            if (!((*i).getType()) && (*i).getEnd() > end)
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

void Memory::Add_Block(string PName, string SName, int Start, int Size)
{

    list<Block>::iterator i;
    i = Find_Iterator(Start, Start + Size);

    if ((*i).getStart() == Start && (*i).getSize() == Size)
    {
        (*i).setProcessName(PName);
        (*i).setSegmentName(SName);
        (*i).setType(true);
    }

    else if ((*i).getStart() == Start)
    {
        Block p1(PName, SName, Start, Size - 1, true);
        Block p2("", "", Start + Size, (*i).getSize() - Size - 1, false);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
    }

    else if ((*i).getEnd() == (Start + Size))
    {
        Block p1("", "", (*i).getStart(), (*i).getSize() - Size - 1, false);
        Block p2(PName, SName, (*i).getEnd() - Size, Size - 1, true);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
    }

    else
    {
        Block p1("", "", (*i).getStart(), Start - (*i).getStart() - 1, false);
        Block p2("PName", "SName", Start, Size - 1, true);
        Block p3("", "", Start + Size, (*i).getEnd() - 1, false);
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
    int size;

    start = (*i).getStart();
    size = (*i).getSize() + (*(++i)).getSize();

    Block p1("", "", start, size, false);
    i = memory.erase(i);
    i = memory.erase(i);
    memory.insert(i, p1);
}

void Memory::Print_Memory()
{
    for (auto it = memory.begin(); it != memory.end(); ++it)
    {
        cout << "size of" << it->getProcessName() << ":" << it->getSegmentName() << " is " << it->getSize()
             << "\t starting from: " << it->getStart() << " till: " << it->getEnd() << "and its type: " << it->getType()
             << endl;
    }
}
