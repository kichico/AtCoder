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
    vector<set<ll>> st(M);
    vector<ll> condition(M);
    ll ans=0;
    rep(i,0,M){
        ll k; cin>>k;
        rep(j,0,k) {
            ll v;cin>>v;
            v--;
            st[i].emplace(v);
        }
    }
    rep(i,0,M) cin>>condition[i];
    ll cntall=0;
    for(int tmp=0;tmp<(1<<10);++tmp){
        bitset<10> s(tmp);
        vector<ll> cnt(M,0);
        cntall++;
        rep(i,0,M){
            rep(j,0,N) if(s.test(j)&&st[i].count(j)==1) cnt[i]++;
        }
        vector<bool> checker(M,false);
        rep(i,0,M) if(cnt[i]%2==condition[i]) checker[i]=true;
        bool flg=true;
        rep(i,0,M) if(!checker[i]) flg=false;
        if(flg) ans++;
        if(cntall==pow(2,N)) break;
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
