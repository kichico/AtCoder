#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N;
    cin>>N;
    set<ll> yakusu{};
    for(ll i=1;i*i<=N;++i){
        if(N%i==0) {
            yakusu.insert(i);
            if(i*i!=N) yakusu.insert(N/i);
        }
    }
    ll sum=0;
    yakusu.erase(*yakusu.rbegin());
    for(auto x:yakusu) {
        sum+=x;
        //cout<<"x=>"<<x<<endl;
        if(sum>N) {
            cout<<"Abundant"<<endl;
            return 0;
        }
    }
    if(sum==N) cout<<"Perfect"<<endl;
    else cout<<"Deficient"<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}