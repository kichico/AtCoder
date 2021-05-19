#include <iostream>
#include <string>
#include <vector>

int main(void){
    int N;
    int A,B,sum=0,sum_OK=0;
    std::cin>>N>>A>>B;
    std::vector<int> List(N+1);
    for(int i=1;i<=N;i++) {
        List[i]=i;
        sum=0;
        int n=List[i];
        while(n>0){
            sum+=n%10;
            n=int(n/10);
        }
        if(sum>=A&&sum<=B) sum_OK+=List[i];
    }
    std::cout<<sum_OK<<std::endl;
    return 0;
}