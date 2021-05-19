#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
  ll N,limit;
  cin>>N>>limit;
  vector<ll> Osake(N),alc(N);
  vector<long double> alcd(N);
  long double get=0;
  for(ll i=0;i<N;++i) {
      cin>>Osake[i]>>alc[i];
      alcd[i]=(long double)alc[i]/100.0;
      get+=(long double)Osake[i]*alcd[i];
      if(get>limit) {
          cout<<i+1<<endl;
          return 0;
      }
  }
  cout<<"-1"<<endl;
  
  return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}