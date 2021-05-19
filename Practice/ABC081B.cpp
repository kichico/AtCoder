#include <vector>
#include <iostream>

int main(void){
    int N,cnt=0,cnt_record;
    cnt_record=100000;
    std::cin>>N;
    std::vector<int> A(N);
    for(int x=0;x<N;x++) std::cin>>A[x];
    bool flg=true;
    for(int x=0;x<N;x++) {
        cnt=0;
        while(true) {
            if(A[x]%2!=0) break;
            else {
             A[x]/=2;
             cnt++;
            }
        }
        if (cnt_record>cnt) cnt_record=cnt;
        std::cout<<A[x]<<" "<<cnt<<std::endl;
      }
    std::cout<<cnt_record<<std::endl;
    return 0;
}