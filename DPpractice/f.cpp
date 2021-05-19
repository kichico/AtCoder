#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
const ll MOD=1e9+7;
const ll INF=1LL<<60;
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
    string s,t;
    cin>>s;
    cin>>t;
    ll slen=(ll)s.size();
    ll tlen=(ll)t.size();
    vector<vector<ll>> dp((ll)s.size()+1,vector<ll>((ll)t.size()+1,0));
    for(ll i=0;i<slen;++i) for(ll j=0;j<tlen;++j){
        if(s[i]==t[j]) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1);
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i+1][j]);
        dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j+1]);
    }
    string str="";
    while(slen>0&&tlen>0){
        if(dp[slen][tlen]==dp[slen-1][tlen]) --slen;
        else if(dp[slen][tlen]==dp[slen][tlen-1]) --tlen;
        else {
            str=s[slen-1]+str;
            --slen;
            --tlen;
        }
    }
    cout<<str<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}