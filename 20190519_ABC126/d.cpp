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
struct Edge{
    ll to,cost;
    Edge() {}
    Edge(ll to, ll cost=0): to(to), cost(cost) {}
};

typedef pair<ll,ll> P;
struct graph{
    const ll INF=numeric_limits<ll>::max();
    vector<vector<Edge>> G;
    ll n;
    graph(ll N) {
       n=N;
       G.resize(n);
    }
    void add_edge(ll from, ll destination, ll cost) {
       G[from].emplace_back(destination,cost); 
    }
    pair<vector<ll>,vector<ll>> dijkstra(ll start) {
       vector<ll> dist(n,INF);
       vector<ll> path(n,-1);
       priority_queue<P,vector<P>,greater<P>> que;
       dist[start]=0;
       que.emplace(0,start);
       while(!que.empty()){
           P p=que.top();
           que.pop();
           ll v=p.second;
           ll min_dist=p.first;
           if(dist[v]<min_dist) continue;
           for(Edge& edge:G[v]){
               if(dist[edge.to]>dist[v]+edge.cost){
                   dist[edge.to]=dist[v]+edge.cost;
                   que.emplace(dist[v]+edge.cost,edge.to);
                   path[edge.to]=v;
                }
            }
        }
        pair<vector<ll>,vector<ll>> retpair;
        retpair=make_pair(dist,path);
        return retpair;
       }
    vector<ll> getpath(const vector<ll> &rec, ll goal){
       vector<ll> path;
       for(ll i=goal; i!=-1; i=rec[i]) path.push_back(i);
       reverse(ALL(path));
       return path;
    }
    void gridgraph(const vector<vector<ll>> &field, graph& gr) {
       ll height=(ll)field.size();
       ll width=(ll)field[0].size();
       for(ll i=0;i<height;++i){
           for(ll j=0;j<width;++j){
               if(i-1>=0) gr.add_edge(i*width+j,(i-1)*width+j,field[i-1][j]);
               if(i+1<height) gr.add_edge(i*width+j,(i+1)*width+j,field[i+1][j]);
               if(j-1>=0) gr.add_edge(i*width+j,i*width+j-1,field[i][j-1]);
               if(j+1<width) gr.add_edge(i*width+j,i*width+j+1,field[i][j+1]);
            }
        }
    }
};
vector<ll> node;
vector<bool> visited;
void dfs(ll now,vector<vector<Edge>>& g){
    queue<pair<ll,ll>> que;
    visited[now]=true;
    rep(i,0,g[now].size()) if(!visited[g[now][i].to]) {
        if(g[now][i].cost%2==0) que.emplace(g[now][i].to,node[now]);
        else que.emplace(g[now][i].to,1-node[now]);
    }
    if(que.size()==0) return;
    while(!que.empty()){
        auto next=que.front(); que.pop();
        node[next.first]=next.second;
        dfs(next.first,g);
    }
}


void solve(){
    ll N;
    graph g(N);
    cin>>N;
    node.assign(N,0);
    visited.assign(N,false);
    rep(i,0,N-1){
        ll from,to,cost;
        cin>>from>>to>>cost;
        from--;to--;
        g.add_edge(from,to,cost);
        g.add_edge(to,from,cost);
    }
    dfs(0,g.G);
    forc(x,node);
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
