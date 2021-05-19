#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
  ll N;
  cin>>N;
  vector<ll> a(N),b(N),c(N);
  set<ll> mx,as;
  for(ll i=0;i<N;++i) {
      cin>>a[i];
  }
  for(ll i=0;i<N;++i) {
      cin>>b[i];
      as.insert(a[i]);
      mx.insert(*as.rbegin()*b[i]);
      c[i]=*mx.rbegin();
  }
  for(ll i=0;i<N;++i) cout<<c[i]<<endl;
  return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}