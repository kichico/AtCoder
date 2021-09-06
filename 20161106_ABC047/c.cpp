#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

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

//#########################################################################
struct UnionFind {
    vector<ll> parents;
    set<ll> roots;
    vector<set<ll>> member;
    UnionFind(int size) { 
        parents.assign(size, -1);
        member=vector<set<ll>>(size);
        rep(i,0,size) {
            roots.emplace(i);
            member[i].emplace(i);
        }
    }
    ll findRoot(ll x) {
        if (parents[x] < 0) return x;
        return parents[x] = findRoot(parents[x]);
    }
    bool unite(ll x, ll y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        roots.erase(y);
        for(auto i:member[y]) member[x].emplace(i);
        member[y].clear();
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
    ll getGroups() { return roots.size(); }
    vector<ll> getMembers(ll x) { 
        vector<ll> v(ALL(member[findRoot(x)]));
        return v; 
    }
};


void solve(){
    string s;
    cin>>s;
    ll N=s.size();
    UnionFind uf(N);
    char initc=s[0];
    ll now=0;
    rep(i,1,s.size()){
        if(initc==s[i]) uf.unite(now,i);
        else {
            initc=s[i];
            now=i;
        }
    }
    cout<<uf.getGroups()-1<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
