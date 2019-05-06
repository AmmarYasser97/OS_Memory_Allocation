//
// Created by Mohamed Hesham on 5/2/19.
// Tested by Ammar Yasser on 5/3/19.
//

#include "Block.h"

using namespace std;

Block::Block(string PName, string SName, int Start, int Size, bool Type)
{
    Process_Name = PName;
    Segment_Name = SName;
    start = Start;
    size = Size;
    type = Type;
}

void Block::setProcessName(string n)
{
    Process_Name = n;
}

void Block::setSegmentName(string n)
{
    Segment_Name = n;
}

void Block::setStart(int n)
{
    start = n;
}

void Block::setSize(int n)
{
    size = n;
}

void Block::setType(bool n)
{
    type = n;
}

string Block::getProcessName()
{
    return Process_Name;
}

string Block::getSegmentName()
{
    return Segment_Name;
}

int Block::getStart()
{
    return start;
}

int Block::getSize()
{
    return size;
}

int Block::getEnd()
{
    return start + size - 1;
}

bool Block::getType()
{
    return type;
}
