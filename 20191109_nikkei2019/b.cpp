#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

const ll MOD=998244353;
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
ll modpow(ll x, ll n){
    ll ans=1;
    while(n>0) {
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}
void solve(){
    ll N;
    cin>>N;
    map<ll,ll> edge;
    rep(i,0,N){
        ll v; cin>>v;
        if(i==0&&v!=0) {
            cout<<0<<endl;return;
        }
        edge[v]++;
    }
    auto it=edge.begin();
    auto maxi=*edge.rbegin();
    ll ans=1;
    if(edge[0]!=1) {cout<<0<<endl;return;}
    rep(i,1,maxi.first+1){
        ll prev=edge[i-1];
        ll cur=edge[i];
        ll edges=1;
        //cout<<"prev:"<<prev<<",cur:"<<cur<<endl;
        //cout<<"maxi:"<<maxi.first<<endl;
        if(prev==0||cur==0) {
            cout<<0<<endl;
            return;
        }
        if(prev==1) edges=1;
        else if(cur==1) edges=prev;
        else edges=modpow(prev,cur);
        //cout<<"edges:"<<edges<<endl;
        if(edges==0) {
            cout<<0<<endl;
            return;
        }
        edges%=MOD;
        ans*=edges;
        ans%=MOD;
    }
    cout<<ans%MOD<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
