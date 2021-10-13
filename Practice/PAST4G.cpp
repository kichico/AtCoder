#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

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
    ll h,w; cin>>h>>w;
    grid<char> in(h,w);
    in.input();
    auto area=in.field;
    vector<ll> open,closed;
    ll ans=0;
    ll cnt=0;
    rep(i,0,h) rep(j,0,w) if(area[i][j]=='#') cnt++;
    cnt--;
    UnionFind uf(h*w);
    vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
    rep(i,0,h) rep(j,0,w){
        ll node=i*w+j;
        if(area[i][j]=='.') {
            rep(k,0,4){
                ll nx=j+dx[k];
                ll ny=i+dy[k];
                if(nx<0||ny<0||ny>=h||nx>=w) continue;
                if(area[ny][nx]=='.') uf.unite(node,ny*w+nx);
            }
        }
        else closed.emplace_back(node);
    }
    rep(i,0,closed.size()){
        auto tmp=uf;
        rep(k,0,4){
            ll nx=closed[i]%w+dx[k];
            ll ny=closed[i]/w+dy[k];
            if(nx<0||ny<0||ny>=h||nx>=w) continue;
            if(area[ny][nx]=='.') tmp.unite(closed[i],ny*w+nx);
        }
        if(tmp.getGroups()-cnt==1) ans++;
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
