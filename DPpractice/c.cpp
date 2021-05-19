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
    ll N,K;
    cin>>N;
    vector<vector<ll>> happiness(N,vector<ll>(3,0));
    for(ll i=0;i<N;++i) for(ll j=0;j<3;++j) cin>>happiness[i][j];
    //op(happiness);
    vector<vector<ll>> dp(N+1,vector<ll>(3,-1));
    for(ll i=0;i<3;++i) dp[0][i]=happiness[0][i];
    for(ll i=1;i<N;++i){
        for(ll j=0;j<3;++j){
            for(ll k=0;k<3;++k){
               if(j==k) continue;
               dp[i][k]=max(dp[i-1][j]+happiness[i][k],dp[i][k]);
               //cout<<"dp["<<i<<"]["<<k<<"]=>"<<dp[i][k]<<endl;
            }
        }
    }
    sort(ALL(dp[N-1]));
    cout<<dp[N-1][2]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}