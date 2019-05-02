//
// Created by ammar on 5/2/19.
//

#ifndef UNTITLED_BLOCK_H
#define UNTITLED_BLOCK_H

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
    Block(string PName, string SName, int Start, int Size, bool Type);

    void setProcessName(string n);

    void setSegmentName(string n);

    void setStart(int n);

    void setSize(int n);

    void setType(bool n);

    string getProcessName();

    string getSegmentName();

    int getStart();

    int getSize();

    int getEnd();

    bool getType();
};


#endif //UNTITLED_BLOCK_H
