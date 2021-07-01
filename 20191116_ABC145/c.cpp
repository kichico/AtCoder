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

struct position{
    ll x;
    ll y;
};




void solve(){
    ll N;
    cin>>N;
    vector<ll> town(N);
    rep(i,0,N) town[i]=i;
    vector<position> where(N);
    rep(i,0,N) cin>>where[i].x>>where[i].y;
    vector<ld> res;
    do{
        ld dist=0;
        rep(i,0,N-1){
            position way;
            way.x=where[town[i+1]].x-where[town[i]].x;
            way.y=where[town[i+1]].y-where[town[i]].y;
            dist+=sqrt(pow(way.x,2)+pow(way.y,2));
        }
        res.emplace_back(dist);
    }while(next_permutation(ALL(town)));
    ld ans=0;
    rep(i,0,res.size()) ans+=res[i];
    cout<<ans/res.size()<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}