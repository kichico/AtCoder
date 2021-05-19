#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
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



vector<pair<ll,ll>> prime_factorize(ll Num){
    vector<pair<ll,ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(Num);
    for(ll i=0;i<Num;++i) listprime[i]=true;
    ll root=sqrt(Num);
    ll res=Num;
    for(ll i=2;i<=root;++i){
        ll expnum=0;
        if(listprime[i]) {
            while(res%i==0) {
                res/=i;
                expnum++;
            }
            //for(ll j=i*2;j<=root;j+=i) listprime[j]=false;
        }
        if(expnum!=0) pr.emplace_back(make_pair(i,expnum));
    }
    if(res!=1) pr.emplace_back(make_pair(res,1));
    return pr;
}

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
    //cout<<"fac_n["<<n<<"]=>"<<fac_n[n]<<", fac_K["<<n-k<<"]=>"<<fac_k[n-k]<<endl;
    return value*fac_n[n]%MOD;
}

int solve(){
    ll N,M;
    cin>>N>>M;
    auto vec=prime_factorize(M);
    ll ans=1;
    ll lim=300001;
    vector<ll> fac_n(lim);
    vector<ll> fac_k(lim);
    fac_n[0]=1;
    fac_k[0]=1;
    for(ll i=0;i<lim-1;++i){
        fac_n[i+1]=fac_n[i]*(i+1)%MOD;
        fac_k[i+1]=fac_k[i]*modpow(i+1,MOD-2)%MOD;
    }
    for(ll i=0;i<(ll)vec.size();++i){
        ll exp=vec[i].second;
        ll c=com(exp+N-1,N-1,fac_n,fac_k);
        flg=false;
        ans=(ans*c)%MOD;
    }
    cout<<ans<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}