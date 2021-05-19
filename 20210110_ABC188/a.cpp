#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
  ll N;
  cin>>N;
  vector<ll> A(N),B(N);
  for(int i=0;i<N;++i){
      cin>>A[i];
  }
  for(int i=0;i<N;++i){
      cin>>B[i];
  }
  ll sum=0;
  for(int i=0;i<N;++i){
      sum+=A[i]*B[i];
  }
  if(sum==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}