#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N,X;
    cin>>N>>X;
    vector<ll> get;
    for(ll i=0;i<N;++i){
        ll in;
        cin>>in;
        if(in!=X) get.push_back(in);
    }
    if(get.empty()) cout<<endl;
    else {
        for(ll i=0;i<get.size()-1;++i) cout<<get[i]<<" ";
        cout<<get.back()<<endl;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}