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

ll rec(ll v, vector<ll> &dp,const vector<vector<ll>> &G){
    if(dp[v]!=-1) return dp[v];
    ll res=0;
    for(auto x:G[v]) res=max(res,rec(x,dp,G)+1);
    //cout<<"dp["<<v<<"]=>"<<res<<endl;
    return dp[v]=res;
}


int solve(){
    ll Node,listlen;
    cin>>Node>>listlen;
    vector<vector<ll>> G(Node,vector<ll>());
    vector<ll> dp(Node,-1);
    for(ll i=0;i<listlen;++i){
        ll from,to;
        cin>>from>>to;
        from--;
        to--;
        G[from].push_back(to);
    }
    for(auto x:G) sort(ALL(x));
    /*for(ll i=0;i<G.size();++i){
        cout<<i+1<<":";
        for(ll j=0;j<G[i].size();++j) {
            cout<<G[i][j]+1<<" ";
        }
        cout<<endl;
    }*/
    ll ans=0;
    for(ll n=0;n<Node;++n) ans=max(ans,rec(n,dp,G));
    cout<<ans<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}