#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}
//#########################################################################
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
void solve(){
    ll N;
    cin>>N;
    vector<ll> a(N); rep(i,0,N) cin>>a[i];
    vector<ll> left(N),right(N);
    rep(i,0,N){
        ll rp=N-i-1;
        if(i==0) {left[i]=a[i]; right[rp]=a[rp]; }
        else{
            left[i]=gcd(left[i-1],a[i]);
            right[rp]=gcd(right[rp+1],a[rp]);
        }
    }
    ll ans=0;
    rep(i,0,N){
        ll v;
        if(i==0) v=right[i+1];
        else if(i==N-1) v=left[i-1];
        else v=gcd(right[i+1],left[i-1]);
        ans=max(ans,v);
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
