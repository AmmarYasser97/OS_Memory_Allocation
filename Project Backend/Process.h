#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <vector>
#include "Block.h"


struct Segment
{
    string name;
    int size;
};

struct Process
{
    string name;
    int num_of_segments;
    vector<Segment> segments;
};

#endif