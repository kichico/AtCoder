#include "bits/stdc++.h"
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
ll lim=500001;
vector<ll> fac_n(lim);
vector<ll> fac_k(lim);


ll modpow(ll x, ll n){
    ll ans=1;
    while(n>0) {
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}

ll com(ll n, ll k, vector<ll> fac_n,vector<ll> fac_k){
    if(n==0&&k==0) return 1;
    if(n<k||n<0) return 0;
    cout<<n-k<<endl;
    ll value=fac_k[n-k]*fac_k[k]%MOD;
    cout<<"first"<<endl;
    return value*fac_n[n]%MOD;
}

ll modcom(ll N,ll k){
    ll res=1;
    rep(i,0,k) {
        ll v=(N-i)%MOD;
        res*=v;
        res%=MOD;
    }
    rep(i,1,k+1) {
        res/=i;
    }
    return res%MOD;
}


void solve(){
    ll N,a,b;
    cin>>N>>a>>b;
    fac_n[0]=1;
    fac_k[0]=1;
    ll ans=modpow(2,N)-1;
    ans-=modcom(N,a);
    ans-=modcom(N,b);
    cout<<ans%MOD<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
