#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    int N;
    cin>>N;
    ll par=pow(2,N);
    vector<ll> rate(par,0),temp,ref;
    for(int i=0;i<par;++i) cin>>rate[i];
    ref=rate;
    while(true){
        if(rate.size()==2) break;
        for(ll i=0;i+1<rate.size();i+=2){
            //cout<<rate[i]<<" "<<rate[i+1]<<endl;
            if(rate[i]>rate[i+1]) temp.push_back(rate[i]);
            else temp.push_back(rate[i+1]);
           // cout<<temp.back()<<endl;
        }
        rate=temp;
        temp.clear();
    }
    ll a=rate[0];
    ll b=rate[1];
    //cout<<a<<" "<<b<<endl;
    ll loose=min(a,b);
    ll looser;
    for(int i=0;i<par;++i) if(ref[i]==loose) {looser=i;break;}
    cout<<looser+1<<endl;
    return 0;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}