#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
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


void solve(){
    string str;
    vector<string> in;
    rep(i,0,31) {
        cin>>str;
        in.push_back(str);
    }
    vector<string> out((int)in.size());
    string alpha="abcdefghijklmnopqrstuvwxyz";
    map<char,ll> al;
    rep(i,0,26) al.emplace(alpha[i],i);
    //cout<<"here"<<endl;
    rep(i,0,in.size()){
        rep(j,0,in[i].size()){
            ll value=al[in[i][j]]+13;
            if(value>=26) value-=26;
            out[i].push_back(alpha[value]);
            //cout<<"convert:"<<out[i]<<endl;
        }
    }
    for(auto s:out) cout<<s<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}