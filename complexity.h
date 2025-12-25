#ifndef COMPLEXITY_H
#define COMPLEXITY_H
#include "profiler.h"
class Complex{
    public:

    static std::vector<int> genData(int size);
    static void asymptotic(void (*func)(std::vector<int>&));
    static double variance(std::vector<double>&);

};



#endif