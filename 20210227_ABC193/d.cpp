﻿#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

const ll MOD=1e9+7;
const ll INF=1e17;
//#######################################################################
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

void twoText(bool identifier, string outTrue, string outFalse) {
    if (identifier) cout << outTrue << endl;
    else cout << outFalse << endl;
}

void twoText(bool identifier){
    if(identifier) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void counter(ll& num,ll& increaser,bool checker){
    if(checker) num+=increaser;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

//#########################################################################

void solve(){
    ll K;
    cin>>K;
    string t,a;
    cin>>t>>a;
    map<ll,ll> takahashi,aoki;
    rep(i,0,4){
        takahashi[t[i]-'0']++;
        aoki[a[i]-'0']++;
    }
    ll tw=0,aw=0,all=0;
    rep(x,1,10){
        takahashi[x]++;
        aoki[x]++;
        ll ts=0,as=0;
        rep(i,1,10) ts+=i*pow(10,takahashi[i]);
        rep(i,1,10) as+=i*pow(10,aoki[i]);
        takahashi[x]--;
        aoki[x]--;
        if(ts>as) tw+=K-(takahashi[x]+aoki[x]);
        else aw+=K-(takahashi[x]+aoki[x]);
        all+=K-(takahashi[x]+aoki[x]);
        cout<<"mai:"<<K-(takahashi[x]+aoki[x])<<endl;
        cout<<"ts:"<<ts<<" as:"<<as<<endl;
        cout<<"tw:"<<tw<<" all:"<<all<<endl;
    }
    cout<<(ld)tw/all<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
