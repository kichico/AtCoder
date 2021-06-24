#include "bits/stdc++.h"
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
    string N;
    cin>>N;
    ll res=0;
    ll three=0;
    vector<ll> check(3,0);
    rep(i,0,N.size()){
        ll num=N[i]-'0';
        three+=num;
        check[num%3]++;
    }
    bool flg=false;
    if(three%3==0) { cout<<0<<endl; return; }
    if(three%3==1) {
        if(check[1]>=1) { cout<<1<<endl; return; } 
        else if(check[2]>=2){ cout<<2<<endl; return; } 
    }
    else if(three%3==2) {
        if(check[2]>=1) { cout<<1<<endl; return; }
        else if(check[1]>=2) { cout<<2<<endl; return; }
    }
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
