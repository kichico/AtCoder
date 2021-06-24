#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
const ll MOD=1e9+7;
//#######################################################################
vector<vector<ll>> input(ll N, ll width){
    string str;
    vector<vector<ll>> vec(N,vector<ll>(width));
    for(ll i=0;i<N;++i){
        getline(cin,str);
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





int solve(){
    ll N,K;
    cin>>N>>K;
    vector<vector<ll>> travel(N,vector<ll>(N,0));
    for(ll i=0;i<N;++i) for(ll j=0;j<N;++j) cin>>travel[i][j];
    vector<ll> list;
    for(ll i=1;i<N;++i) list.push_back(i);
    ll from,to;
    ll start=0;
    vector<ll> time;
    ll sum=0;
    ll cnt=0;
    do{
        sum=0;
        start=0;
        for(ll i=0;i<list.size();++i){
            from=start;
            to=list[i];
            sum+=travel[from][to];
            start=list[i];
        }
        sum+=travel[list.back()][0];
        if(sum==K) cnt++;
    }while (next_permutation(ALL(list)));
    cout<<cnt<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}