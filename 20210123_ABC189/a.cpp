#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
  string str;
  cin>>str;
  if(str[0]==str[1]&&str[1]==str[2]) cout<<"Won"<<endl;
  else cout<<"Lost"<<endl;
  return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}