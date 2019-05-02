//
// Created by ammar on 5/2/19.
//

#ifndef UNTITLED_MEMORY_H
#define UNTITLED_MEMORY_H

#include "Block.h"

using namespace std;

class Memory
{
private:
    list<Block> memory;
    Block Initial_Block;
    int size;

public:
    explicit Memory(int Size);

    list<Block>::iterator Find_Iterator(int start, int end);

    bool Is_Empty_Boolean(int start, int end);

    void Add_Block(string PName, string SName, int Start, int Size);

    void Compact_Blocks(list<Block>::iterator i);

    void Print_Memory();

};

#endif //UNTITLED_MEMORY_H
