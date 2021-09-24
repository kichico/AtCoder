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
    ll value=fac_k[n-k]*fac_k[k]%MOD;
    return value*fac_n[n]%MOD;
}



void solve(){
    ll X,Y;
    cin>>X>>Y;
    ll a=0; ll b=INF;
    ll lim=3000001;
    vector<ll> fac_n(lim);
    vector<ll> fac_k(lim);
    fac_n[0]=1;
    fac_k[0]=1;
    for(ll i=0;i<lim-1;++i){
        fac_n[i+1]=fac_n[i]*(i+1)%MOD;
        fac_k[i+1]=fac_k[i]*modpow(i+1,MOD-2)%MOD;
    }
    rep(i,0,X+1){
        a=i;
        ll xb=(X-a);
        if(xb%2!=0) continue;
        else xb/=2;
        ll yb=Y-2*a;
        if(xb==yb) {
            b=xb;
            break;
        }
    }
    if(b==INF){
        cout<<0<<endl;
        return;
    }
   // cout<<"a,b "<<a<<" "<<b<<endl;
    cout<<com(a+b,a,fac_n,fac_k)<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
