#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
const ll MOD=1e9+7;
const ll INF=1e10;
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

int solve(){
    ll N,maxW;
    cin>>N>>maxW;
    struct Goods{
        ll value;
        ll weight;
    };
    vector<Goods> goods(N);
    for(ll i=0;i<N;++i) cin>>goods[i].weight>>goods[i].value;
    vector<vector<ll>> dp(N+1,vector<ll>(maxW+1,0));
    //for(ll i=0;i<maxW;++i) dp[0][i]=0;
    for(ll i=0;i<N;++i){
        for(ll w=0;w<=maxW;++w){
            if(w-goods[i].weight>=0) dp[i+1][w]=max(dp[i+1][w],dp[i][w-goods[i].weight]+goods[i].value);
            dp[i+1][w]=max(dp[i][w],dp[i+1][w]);
            //cout<<"dp["<<i<<"]["<<w<<"]=>"<<dp[i][w]<<endl;
        }
    }
    cout<<dp[N][maxW]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}