#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N;
    cin>>N;
    vector<ll> mikan(N);
    set<ll> max;
    ll sum=0;
    for(ll i=0;i<N;++i) {
        cin>>mikan[i];
    }
    for(ll i=0;i<N;++i) {
        sum=0;
        ll cnt=0;
        ll minmikan=1e6;
        for(ll j=0;i+j<N;++j) {
            if(mikan[i+j]<minmikan) minmikan=mikan[i+j];
            cnt++;
            //cout<<"i=>"<<i<<", i+j=>"<<i+j<<endl;
        }
        sum=cnt*minmikan;
        //cout<<"sum=>"<<sum<<endl;
        max.insert(sum);
    }
    for(ll i=0;i<N;++i){
        ll minmikan=1e6;
        sum=0;
        ll cnt=0;
        for(ll j=0;j<=i;++j) {
            if(mikan[j]<minmikan) minmikan=mikan[j];
            cnt++;
            //cout<<"j=>"<<j<<", i=>"<<i<<endl;
        }
        sum=minmikan*cnt;
        //cout<<"sum=>"<<sum<<endl;
        max.insert(sum);
    }
    cout<<*max.rbegin()<<endl;
    return 0;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}