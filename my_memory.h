#ifndef MEMORY_H
#define MEMORY_H

#include "my_block.h"
#include "my_Process.h"

using namespace std;

class Memory
{
  private:
    list<Block> memory;
    Block Initial_Block;
    int size;

  public:
    explicit Memory(int Size);
    explicit Memory();
    int getSize();
    void setSize(int Size);

    list<Block>::iterator Find_Iterator(int start, int end);

    list<Block>::iterator Find_Iterator_By_Start(int start);

    bool Is_Empty_Boolean(int start, int end);

    void Add_Block(QString PName, QString SName, int Start, int Size);

    QVector<QString> Flip_Blocks();

    void Remove_Block(list<Block>::iterator i);

    void Compact_Blocks(list<Block>::iterator i);

    void Print_Memory();

    void Deallocate_Process(QString process_name);

    void best_fit(Process process);

    void first_fit(Process process);

    void worst_fit(Process process);
};

#endif // MEMORY_H
