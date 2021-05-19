#include <iostream>
#include <vector>


int main(void){
    int H,W;
    std::cin>>H>>W;
    std::vector<std::vector<int> > A(H,std::vector<int>(W));
    int min=1000;
    int ans=0;
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            std::cin>>A[i][j];
            if(min>A[i][j]) min=A[i][j];
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++){
        int m=A[i][j]-min;
        ans+=m;
        }
    }
    std::cout<<ans<<std::endl;
    return 0;
}