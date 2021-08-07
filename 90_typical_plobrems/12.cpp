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
    UnionFind(int size) { parents.assign(size, -1); }
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
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
};

void solve(){
    ll h,w;
    cin>>h>>w;
    ll q;cin>>q;
    UnionFind uf(h*w);
    set<ll> connected;
    grid<bool> p(h,w);
    auto painted=p.field;
    rep(i,0,h) rep(j,0,w) painted[i][j]=false;
    vector<string> res;
    rep(i,0,q){
        ll x;cin>>x;
        if(x==1){
            ll r,c;
            cin>>r>>c;
            r--;c--;
            if(connected.size()>=1) {
                vector<ll> dx{1,0,-1,0};
                vector<ll> dy{0,1,0,-1};
                rep(k,0,4) {
                    ll ny=r+dy[k]; ll nx=c+dx[k];
                    if(ny<0||nx<0||nx>=w||ny>=h) continue;
                    if(painted[ny][nx]) {
                        ll current=r*w+c;
                        ll already=ny*w+nx;
                        uf.unite(current,already);
                    }
                } 
            }
            painted[r][c]=true;
            connected.insert(r*w+c);
        }
        else{
            ll sx,sy,gx,gy;
            cin>>sy>>sx>>gy>>gx;
            sy--;gy--;sx--;gx--;
            ll start=sy*w+sx;
            ll goal=gy*w+gx;
            //twoText(uf.isSameGroup(start,goal));
            if(connected.count(start)==0||connected.count(goal)==0) res.emplace_back("No");
            else if(uf.isSameGroup(start,goal)) res.emplace_back("Yes");
            else res.emplace_back("No");
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
