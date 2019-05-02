//
// Created by ammar on 5/2/19.
//

#include "memory.h"

using namespace std;


//class Process
//{
//private:
//    int number_of_segments;
//    Block[number_of_segments] segments;
//
//public:
//};


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
        if ((*i).getStart() > start)
        {
            i--;
            if (!((*i).getType()) && (*i).getEnd() > end)
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
        Block p1(PName, SName, Start, Size, true);
        Block p2("", "", Start + Size + 1, (*i).getSize() - Size, false);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);

        if (i != memory.end())
        {
            Compact_Blocks(--i);
        }
    }
    else if ((*i).getEnd() == (Start + Size))
    {
        Block p1("", "", Start, (*i).getSize() - Size, false);
        Block p2(PName, SName, (*i).getEnd() - Size + 1, Size, true);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
        i--;
        i--;
        i--;
        if (i != memory.begin())
        {
            Compact_Blocks(i);
        }
    }
    else
    {
        Block p1("", "", (*i).getStart(), Start - (*i).getStart(), false);
        Block p2("PName", "SName", Start, Size, true);
        Block p3("", "", Start + Size + 1, (*i).getEnd(), false);
        i = memory.erase(i);
        memory.insert(i, p1);
        memory.insert(i, p2);
        memory.insert(i, p3);

        list<Block>::iterator it_p3; //In case compaction happens i will be dangling operator

        it_p3 = --i;

        if (i != memory.end())
        {
            Compact_Blocks(--i);
        }

        i--;
        i--;
        i--;
        if (i != memory.begin())
        {
            Compact_Blocks(i);
        }
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