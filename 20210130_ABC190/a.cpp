#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll aoki,takahashi,C;
    cin>>takahashi>>aoki>>C;
    if(aoki<takahashi){
      cout<<"Takahashi"<<endl;
      return 0;
    }
    else if(aoki>takahashi){
      cout<<"Aoki"<<endl;
    }
    else {
      if(C==0) cout<<"Aoki"<<endl;
      else cout<<"Takahashi"<<endl;
      return 0;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}