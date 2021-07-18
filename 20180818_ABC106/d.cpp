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
    ll N,way,q;
    cin>>N>>way>>q;
    vector<vector<ll>> cnt(510,vector<ll>(510,0));
    rep(i,0,way){
        ll L,R;cin>>L>>R;
        cnt[L][R]++;
    }
    rep(L,1,N+1) rep(R,2,N+1) {
        cnt[L][R]+=cnt[L][R-1];
        cout<<"cnt["<<L<<"]["<<R<<"]:"<<cnt[L][R]<<endl;
    }
    vector<ll> res;
    rep(i,0,q){
        ll ans=0;
        ll from,to; cin>>from>>to;
        cout<<i<<"th---------"<<endl;
        rep(L,from,to+1) {
            ans+=cnt[L][to];
            cout<<ans<<endl;
        }
        res.emplace_back(ans);
    }
    for(auto x:res) cout<<x<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
