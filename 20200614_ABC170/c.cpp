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
    ll X,N;
    cin>>X>>N;
    vector<ll> a(N);
    set<ll> v;
    rep(i,0,N) cin>>a[i];
    if(a.size()!=0){
        rep(i,-100,110) v.emplace(i);
        rep(i,0,a.size()) v.erase(a[i]);
        vector<ll> all{ALL(v)};
        vector<pair<ll,ll>> res;
        rep(i,0,v.size()){
            auto vpr=make_pair(abs(X-all[i]),all[i]);
            res.push_back(vpr);
        }
        sort(ALL(res));
        if(!res.empty()) cout<<res[0].second<<endl;
        else cout<<X<<endl;
        //for(auto x:res) cout<<x.first<<" "<<x.second<<endl;
    }
    else cout<<X<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
