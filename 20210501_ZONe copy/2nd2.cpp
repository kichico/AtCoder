#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template<class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(i,start,N) for(ll i=start;i<N;++i)

const ll MOD=1e9+7;
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

bool isPrime(ll Num){
    ll root=sqrt(Num);
    if(Num==0||Num==1) return false;
    for(ll i=2;i<=root;++i) if(Num%i==0) return false;
    return true;
}

void solve(){
    ll Num=0;
    ll cnt=0;
    rep(i,0,20) rep(j,0,20) {
        cin>>Num;
        if(isPrime(Num)) cnt++;
    }
    cout<<cnt<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}