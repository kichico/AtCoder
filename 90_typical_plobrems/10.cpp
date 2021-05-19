#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)
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
    ll N;
    cin>>N;
    vector<ll> first(N,0),second(N,0);
    ll sumf=0,sums=0;
    rep(i,N) {
        pair<ll,ll> pr;
        cin>>pr.first>>pr.second;
        if(pr.first==1) sumf+=pr.second;
        else sums+=pr.second;
        first[i]=sumf;
        second[i]=sums;
    }
    ll q;
    cin>>q;
    vector<pair<ll,ll>> res(q);
    rep(i,q){
        ll from,to;
        cin>>from>>to;
        from--;to--;
        if(from>=1) res[i]=make_pair((first[to]-first[from-1]),(second[to]-second[from-1]));
        else res[i]=make_pair(first[to],second[to]);
    }
    for(auto x:res) cout<<x.first<<" "<<x.second<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
