#include <iostream>
#include <vector>

int main(void){
    long long N,Result=1;
    std::cin>>N;
    std::vector<long long> x(N,0);
    for(long long i=2;i<=N;i++) x[i]=i;
    for(long long i=4;i<N;i++) {
        for(long long j=2;j<N;j++) {
            if(x[i]%j*j==0) x[i]/=j; 
        }
    }
    for(long long i=2;i<=N;i++) Result*=x[i];
    ++Result;
    std::cout<<Result<<std::endl;
    return 0;
}