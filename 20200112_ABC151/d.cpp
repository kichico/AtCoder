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
template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}
//########################################################################

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



void solve(){
    ll h,w;
    cin>>h>>w;
    grid<char> f(h,w);
    f.input();
    auto area=f.field;
    graph g(h*w);
    vector<ll> dx{1,0,-1,0}, dy{0,1,0,-1};
    rep(i,0,h) rep(j,0,w){
        ll node=i*w+j;
        rep(k,0,4){
            ll ny=i+dy[k],nx=j+dx[k];
            if(nx<0||ny<0||nx>=w||ny>=h) continue;
            ll next=ny*w+nx;
            g.add_edge(node,next,1);
            g.add_edge(next,node,1);
        }
    }
    ll maxi=0;
    rep(i,0,h) rep(j,0,w){
        ll node=i*w+j;
        if(area[i][j]=='#') continue;
        auto pr=g.dijkstra(node);
        sort(ALL(pr.first));
        maxi=max(maxi,pr.first.back());
    }
    cout<<maxi<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
