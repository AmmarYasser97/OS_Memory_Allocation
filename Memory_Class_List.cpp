#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

class Block
{
  private:
    string Process_Name;
    string Segment_Name;
    int start;
    int size;
    bool type;

  public:
    Block(string PName, string SName, int Start, int Size, bool Type)
    {
        Process_Name = PName;
        Segment_Name = SName;
        start = Start;
        size = Size;
        type = Type;
    }
    void setProcessName(string n)
    {
        Process_Name = n;
        return;
    }

    void setSegmentName(string n)
    {
        Segment_Name = n;
        return;
    }

    void setStart(int n)
    {
        start = n;
        return;
    }
    void setSize(int n)
    {
        size = n;
        return;
    }
    void setType(bool n)
    {
        type = n;
        return;
    }

    string getProcessName()
    {
        return Process_Name;
    }

    string getSegmentName()
    {
        return Segment_Name;
    }

    int getStart()
    {

        return start;
    }
    int getSize()
    {

        return size;
    }
    int getEnd()
    {

        return start + size;
    }
    bool getType()
    {

        return type;
    }
};

class Process
{
  private:
    int number_of_segments;
    Block[number_of_segments] segments;

  public:
};

class Memory
{
  private:
    list<Block> memory;
    Block Initial_Block("", "", 0, Size, false);
    int size;

  public:
    Memory(int Size)
    {
        size = Size;
        memory.pushback(Initial_Block);
    }

    list<Block>::iterator Find_Iterator(int start, int end)
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

    bool Is_Empty_Boolean(int start, int end)
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

    void Add_Block(string PName, string SName, int Start, int Size)
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
                Compact_Blocks(i - 1);
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
            Block p1();
            Block p2();
            Block p3();
            i = memory.erase(i);
            memory.insert(i, p1);
            memory.insert(i, p2);
            memory.insert(i, p3);

            list<Block>::iterator it_p3; //In case compaction happens i will be dangling operator

            it_p3 = i - 1;

            if (i != memory.end())
            {
                Compact_Blocks(i - 1);
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

    void Compact_Blocks(list<Block>::iterator i)
    {
        //i represents the iterator of the first block
        int start;
        int size;

        start = (i *).getStart();
        size = (i *).getSize() + ((i + 1) *).getSize();

        Block p1("", "", start, size, false);
        i = memory.erase(i);
        i = memory.erase(i);
        memory.insert(i, p1);
    }
};

int main()
{
    return 0;
}
