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

struct UnionFind {
    vector<ll> parents;
    UnionFind(int size) { parents.assign(size, -1); }
    ll findRoot(ll x) {
        if (parents[x] < 0) return x;
        return parents[x] = findRoot(parents[x]);
    }
    bool unite(ll x, ll y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        //cout<<"debug"<<endl;
        if (parents[x] > parents[y]) swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        //cout<<"debug1"<<endl;
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
};

void solve(){
    ll N;
    cin>>N;
    vector<ll> kaibun(N);
    rep(i,0,N) cin>>kaibun[i];
    ll res=0;
    //if(N==1) {cout<<0<<endl; return;}
    ll lim=2e5+1;
    UnionFind uf(lim);
    rep(i,0,(N/2)){
        //cout<<"i:"<<i<<","<<"N-1-i:"<<N-1-i<<endl;
        uf.unite(kaibun[i],kaibun[N-1-i]);
    }
    //rep(i,0,N) cout<<kaibun[i]<<":"<<uf.parents[i]<<endl;
    rep(i,0,lim){
        if(uf.parents[i]<-1) res+=uf.size(i)-1;
    }
    cout<<res<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
