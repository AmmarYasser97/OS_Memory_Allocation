//
// Created by Mohamed Hesham on 5/2/19.
// Tested by Ammar Yasser on 5/3/19.
//

#ifndef UNTITLED_MEMORY_H
#define UNTITLED_MEMORY_H

#include "Block.h"
#include "Process.h"

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

    list<Block>::iterator Find_Iterator_By_Start(int start);

    bool Is_Empty_Boolean(int start, int end);

    void Add_Block(string PName, string SName, int Start, int Size);

    void Remove_Block(list<Block>::iterator i);

    void Compact_Blocks(list<Block>::iterator i);

    void Print_Memory();

    void Deallocate_Process(string process_name);

    void best_fit(Process process);

    void first_fit(Process process);

    void worst_fit(Process process);
};

#endif //UNTITLED_MEMORY_H
