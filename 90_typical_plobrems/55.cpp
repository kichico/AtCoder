#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(i,from,to) for(ll i=from;i<to;++i)

constexpr ll MOD=1e9+7;
constexpr ll INF=1e16;
template<class T>
using grid=vector<vector<T>>;
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


void solve(){
    ll N,P,Q;
    cin>>N>>P>>Q;
    vector<ll> a(N);
    rep(i,0,N) cin>>a[i];
    ll ans=0;
    rep(i,0,N) rep(j,0,i) rep(k,0,j) rep(l,0,k) rep(m,0,l){
        ll cal=a[i]*a[j]%P*a[k]%P*a[l]%P*a[m]%P;
        //cout<<"i,j,k,l,m:"<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
        //cout<<"cal:"<<cal<<endl;
        if(cal==Q) ans++;
    }
    cout<<ans<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
