#include "bits/stdc++.h"
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll=int64_t;
//using lll=boost::multiprecision::cpp_int;

int solve(){
    ll N;
    cin>>N;
    vector<string> str(N);
    for(ll i=0;i<N;++i) cin>>str[i];
    ll cnt=0;
    for(ll i=0;i<(1<<3);++i){
        bitset<61> s(i),check;
        //cout<<"debug.."<<endl;
        if(s[0]==1) check.set(0,1);
        //cout<<"debug"<<endl;
        for(ll j=1;j<=N;++j){
            if(str[j-1]=="AND") check.set(j,s[j]&check[j-1]);
            else check.set(j,s[j]|check[j-1]);
        }
        if(check[N]==1) cnt++;
        cout<<"check[N]=>"<<check[N]<<endl;
    }
    cout<<cnt<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}