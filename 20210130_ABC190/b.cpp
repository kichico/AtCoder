#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N,S,D;
    multimap<ll,ll> damage;
    cin>>N>>S>>D;
    ll dam,time;
    for(ll i=0;i<N;++i){
        cin>>time>>dam;
        if(dam>D&&time<S){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}