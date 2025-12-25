#include "complexity.h"
#include <cstdlib>
#include<cmath>
#include<numeric>
#include<algorithm>
#include<iostream>
bool stable(double var) {
    return var < 1e-3;
}
std::vector<int> Complex::genData(int size){
    std::vector<int> v;
    for(int i = 0;i<size;i++)
        v.push_back(rand()%100000);
    return v;
}
double Complex::variance(std::vector<double>& v){
    if(v.empty())
        return 1e18;
    double mean = std::accumulate(v.begin(),v.end(),0.0)/v.size();
    double var =0.0;
    for(double i:v)
        var+= (i-mean)*(i-mean);
        var/=v.size();
    return var/(mean*mean);
}
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
        if(j<2)
            continue;
        total+=cur;
        }
        
        t[i].time = total/(r-2);
    }
    double mean = 0.0;
    for (int i = 2; i < 5; i++) {
        mean+= t[i].time/t[i-1].time;
    //std::cout << t[i].time / t[i-1].time << "\n";
}   
    mean/=3;
    std::vector<double> n;
    std::vector<double> nlogn;
    std::vector<double> n2;   
    for(int i =0;i<5;i++)
        n.push_back(t[i].time/t[i].n);
    for(int i =0;i<5;i++)
        nlogn.push_back(t[i].time/((t[i].n)*std::log2(t[i].n)));
    for(int i =0;i<5;i++)
        n2.push_back(t[i].time/(t[i].n*t[i].n));
    
    double nv = variance(n);
    double nlognv = variance(nlogn);
    double n2v = variance(n2);
    std::cout<<"Mean: "<<mean<<std::endl;
    if(mean<2.11)
        std::cout<<"O(N)"<<std::endl;
    else if(mean<3.0)
        std::cout<<"O(nlogn)"<<std::endl;
    else std::cout<<"O(N^2)"<<std::endl;
    /*const double thresh = 0.1;
    double m = std::min(nv,nlognv);
    m = std::min(m,n2v);
    if(n2v<thresh)
        std::cout<<"O(N^2)"<<std::endl;
    else if( thresh > nlognv)
        std::cout<<"O(nlogn)"<<std::endl;
    else
        std::cout<<"O(N)"<<std::endl;

    */
    return;
    

       
    

}
