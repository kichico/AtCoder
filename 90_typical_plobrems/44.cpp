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
    ll N,q;
    cin>>N>>q;
    vector<ll> a;
    vector<ll> res;
    ll shift=0;
    rep(i,N) {
        ll in;
        cin>>in;
        a.push_back(in);
    }
    rep(i,q) {
        vector<ll> query(3);
        rep(j,3) cin>>query[j];
        if(query[0]==1){
            ll d=shift;
            if(d>=a.size()) d-=a.size();
            if(query[1]-1-d<0) query[1]+=a.size();
            if(query[2]-1-d<0) query[2]+=a.size();
            iter_swap(a.begin()+query[1]-1-d,a.begin()+query[2]-1-d);
        }
        else if(query[0]==2){
            shift++;
        }
        else{
            ll d=shift;
            if(d>=a.size()) d-=a.size();
            if(query[1]-1-d<0) query[1]+=a.size();
            res.push_back(a[query[1]-1-d]);
        }
    }
    for(auto x:res) cout<<x<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
