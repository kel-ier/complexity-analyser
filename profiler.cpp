#include "profiler.h"
#include <chrono>
using namespace std;
long long Profiler::timeFunc(void(*func)(vector<int>&),vector<int>& data){
    auto start = chrono::steady_clock::now();
    func(data);
    auto end = chrono::steady_clock::now();
    return (chrono::duration_cast<chrono::microseconds>(end - start).count());

}