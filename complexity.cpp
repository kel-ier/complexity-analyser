#include "complexity.h"
#include <cstdlib>
#include<cmath>
#include<numeric>
#include<algorithm>
#include<iostream>
bool stable(double var) {
    return var < 1e-3;
}
//Generate random values for various tests 
std::vector<int> Complex::genData(int size){
    std::vector<int> v;
    for(int i = 0;i<size;i++)
        v.push_back(rand()%100000);
    return v;
}
//core engine
void Complex::asymptotic(void (*func)(std::vector<int>& )){

    struct test{
    int n;
    double time;
}t[5];
    for(int i =0;i<5;i++){
        std::cout<<"Analysing..."<<std::endl;
        t[i].n =1000*(1<<i);
        int r =5;
        double total = 0.0;
        for(int j =0;j<r;j++){

        std::vector<int> v = genData(t[i].n);
        int cur = Profiler::timeFunc(func,v);
        //Discard 2 attempts to account for noise, cache operations
        if(j<2)
            continue;
        total+=cur;
        }
        
        t[i].time = total/(r-2);
    }
    double mean = 0.0;
    //calculate ratio of changes in time wrt size(n)
    for (int i = 2; i < 5; i++) {
        mean+= t[i].time/t[i-1].time;
}   
    mean/=3;
    std::cout<<"Mean: "<<mean<<std::endl;
    if(mean<2.11)
        std::cout<<"O(N)"<<std::endl;
    else if(mean<3.0)
        std::cout<<"O(nlogn)"<<std::endl;
   else std::cout<<"O(N^2)"<<std::endl;
    return;
    

       
    

}
