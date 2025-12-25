#ifndef PROFILER_H
#define PROFILER_H
#include <vector>
class Profiler{
    public: 
    static long long timeFunc(void (*func)(std::vector<int>&),std::vector<int>& data);
};
#endif