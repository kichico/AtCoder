#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N,M,K;
    cin>>N>>M;
    vector<pair<ll,ll>> condition(M);
    for(int i=0;i<M;++i) cin>>condition[i].first>>condition[i].second;
    cin>>K;
    vector<pair<ll,ll>> human(K);
    for(int i=0;i<K;++i) cin>>human[i].first>>human[i].second;
    set<ll> clear;
    for (int tmp = 0; tmp < (1 << 16); ++tmp) {
        //cout<<"debug"<<endl;
        bitset<16> check(tmp);
        vector<bool> sara(N,false);
        ll sum=0;
        for(ll i=0;i<K;++i){
            if(check.test(i)) sara[human[i].second]=true;
            else sara[human[i].first]=true;
            //cout<<"debug3"<<endl;
        }
        //cout<<"debug2"<<endl;
        for(int i=0;i<M;++i) if(sara[condition[i].first]==true&&sara[condition[i].second]==true) sum++;
        clear.insert(sum);
    }
    cout<<*clear.rbegin()<<endl;
    return 0;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}