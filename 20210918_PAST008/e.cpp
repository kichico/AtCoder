#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
#define mp(a,b) make_pair(a,b)
const ll MOD=1e9+7;
const ll INF=1e17;
const vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

template<class T>
inline bool isExist(set<T> st, T key){
    if(st.find(key) == st.end()) return false;
    else return true;
}

template<class T,class U>
inline bool isExist(map<T,U> st, T key){
    if(st.find(key) == st.end()) return false;
    else return true;
}
//#########################################################################

void solve(){
    ll N,K; cin>>N>>K;
    map<ll,ll> shirt;
    vector<ll> c(N),p(N);
    vector<pair<ll,ll>> sh;
    rep(i,0,N) cin>>c[i];
    rep(i,0,N) cin>>p[i];
    rep(i,0,N) sh.emplace_back(mp(p[i],c[i]));
    sort(ALL(sh));
    set<ll> check;
    ll ans = 0;
    rep(i,0,N){
        if(check.find(sh[i].second) == check.end()){
            ans+=sh[i].first;
            check.emplace(sh[i].second);
            if(check.size()>=K) break;
        }
    }
    if(check.size()<K) cout<<-1<<endl;
    else cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
