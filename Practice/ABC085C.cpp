#include <iostream>
using namespace std;
int main(void){
    long long N,yen;
    cin>>N>>yen;
    for(long long i=0;i<=N;++i) {
        for(long long j=0;j<=N-i;++j)  {
            int k=N-i-j;
            int total=10000*i+5000*j+1000*k;
            if(yen==total) {
                cout<<i<<" "<<j<<" "<<k<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1 -1"<<endl;
    return 0;
}