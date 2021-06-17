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





void solve(){
    ll N,M;
    cin>>N>>M;
    vector<ll> a(M+1);
    ll minv=INF;
    if(M==0) {
        cout<<1<<endl;
        return;
    }
    rep(i,0,M) {
        cin>>a[i];
    }
    a[M]=N+1;
    sort(ALL(a));
    if(a[0]!=1) minv=a[0]-1;
    rep(i,0,M) {
        if(a[i+1]-a[i]-1==0) continue;
        minv=min(minv,a[i+1]-a[i]-1);
    }
    ll ans=0;
    ll now=1;
    //cout<<"minv:"<<minv<<endl;
    if(minv==INF) {
        cout<<0<<endl;
        return;
    }
    rep(i,0,M+1){
        ll to=a[i];
        if(to!=1) {
            ans+=ceil((ld)(to-now-1)/minv);
            /*
            cout<<"now->to:"<<now<<"->"<<to<<endl;
            cout<<"len:"<<to-now-1<<endl;
            cout<<"ans:"<<ans<<",minv:"<<minv<<endl;
            cout<<"a["<<i<<"]:"<<a[i]<<endl;
            */
            now=to;
            
        }
        else{
            now=to;
            continue;
        }
    }
    //cout<<N-now-1<<endl;
    //if(N!=a.back()) ans+=ceil((ld)(N-now)/minv);
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
