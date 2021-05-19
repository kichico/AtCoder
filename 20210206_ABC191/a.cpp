#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    long double sp,start,end,hitter;
    cin>>sp>>start>>end>>hitter;
    long double time=hitter/sp;
    if(time>=start&&time<=end) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	  std::ios_base::sync_with_stdio(false);
	  std::cout << std::fixed << std::setprecision(15);
	  solve();
}