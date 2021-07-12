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

ll maxcost = 0;
vector<string> ans; 

struct Edge{
    ll to,cost;
    Edge() {}
    Edge(ll to, ll cost = 0) : to(to), cost(cost) {}
};

struct WF{
    grid<Edge> graph;
    WF(ll n) { graph.resize((size_t)n); }
    void addEdge(ll from, ll to, ll cost) {
        graph[from].emplace_back(to, cost);
    }
    //cout << "N:" << graph.size() << endl;
    grid<ll> WarshallFloyd() {
        ll N = graph.size();
        grid<ll> dist(N, vector<ll>(N, INF));
        rep(i, 0, N) {
            dist[i][i] = 0;
            rep(j, 0, graph[i].size()) {
                dist[i][graph[i][j].to] = graph[i][j].cost;
            }
        }
        rep(k, 0, N) {
            rep(i, 0, N) rep(j, 0, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        return dist;
    }
};



void solve() {
    ll N, q;
    cin >> N >> q;
    WF wf(N);
    rep(i, 0, N-1) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        wf.addEdge(a, b, 1);
        wf.addEdge(b,a,1);
    }
    auto res=wf.WarshallFloyd();
    rep(i,0,q){
        ll from,to;
        cin>>from>>to;
        from--;to--;
        ll dist=res[from][to];
        if(dist%2==0) ans.push_back("Town");
        else ans.push_back("Road");
    }
    for(auto a:ans) cout<<a<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
