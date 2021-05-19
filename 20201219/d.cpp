#include <vector>
#include <iostream>
#include <algorithm>

int main(void){
    long long N,total=0;
    std::cin>>N;
    std::vector<long long> A(N),sum(N,0);
    for(long long i=0;i<N;i++) {
        std::cin>>A[i];
    }
    std::sort(A.begin(),A.end());
    for(int i=0;i<N;++i){
        sum[i]=total+A[i];
        total+=A[i];
        std::cout<<"total=>"<<total<<std::endl;
        std::cout<<"sum=>"<<sum[i]<<std::endl;
    }
    long long res=0;
    for(long long i=0;i<N;i++){
        res = total-sum[i]-(N-i)*A[i];
        std::cout<<"Res=>"<<res<<std::endl;
    }
    std::cout<<res<<std::endl;
    return 0;
}