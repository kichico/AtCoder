﻿#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

const ll MOD=1e9+7;
const ll INF=1e17;
//#######################################################################
vector<vector<ll>> input(ll N, ll width){
    string str;
    vector<vector<ll>> vec(N,vector<ll>(width));
    for(ll i=0;i<N;++i){
        cin>>str;
        reverse(ALL(str));
        for(ll j=0;j<width;++j){
            vec[i][j]=str.back();
            str.pop_back();
        }
    }
    return vec;
}
void op(vector<ll> vec){
    ll size=(ll)vec.size();
    for(ll i=0;i<size-1;++i) cout<<vec[i]<<" ";
    cout<<vec.back()<<endl;
}

void op(vector<vector<ll>> vec){
    ll height=(ll)vec.size();
    ll width=(ll)vec[0].size();
    for(ll i=0;i<height;++i) {
        for(ll j=0;j<width-1;++j) cout<<vec[i][j]<<" ";
        cout<<vec[i].back()<<endl;
    }
}
//########################################################################





void solve(){
    ll N,M,lim;
    cin>>N>>M>>lim;
    vector<ll> a(N),b(M),atot(N),btot(M);
    rep(i,0,N){
        cin>>a[i];
        if(i==0) atot[i]=a[i];
        else atot[i]=a[i]+atot[i-1];
    }
    rep(i,0,M){
        cin>>b[i];
        if(i==0) btot[i]=b[i];
        else btot[i]=b[i]+btot[i-1];
    }
    ll ok=M-1;
    ll ans=0;
    if(btot[ok]<=lim) ans=ok;
    rep(i,0,N){
        while(0<=ok&&lim<atot[i]+btot[ok]) ok--;
        if(ok<0&&atot[i]<=lim) ans=max(ans,i+1); 
        else if(ok>=0&&atot[i]+btot[ok]<=lim) ans=max(ans,i+1+ok+1);
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
