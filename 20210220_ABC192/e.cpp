#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)
const ll INF=numeric_limits<ll>::max();
const ll MOD=1e9+7;
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

struct Edge{
    ll to,cost,K;
    Edge() {}
    Edge(ll to, ll cost,ll K=0): to(to), cost(cost), K(K) {}
};

typedef pair<ll,ll> P;
struct graph{
    vector<vector<Edge>> G;
    ll n;
    graph(ll N) {
        n=N;
        G.resize(n);
    }
    void add_edge(ll from, ll destination, ll cost, ll K) {
        G[from].emplace_back(destination,cost,K); 
    }
    pair<vector<ll>,vector<ll>> dijkstra(ll start) {
        vector<ll> dist(n,INF);
        vector<ll> path(n,-1);
        priority_queue<pair<P,ll>,vector<pair<P,ll>>,greater<pair<P,ll>>> que;
        dist[start]=0;
        que.emplace(0,0,start);
        while(!que.empty()){
            auto p=que.top();
            que.pop();
            ll v=p.second;
            ll min_time=p.first.first;
            ll now=p.first.second;
            if(dist[v]<min_time) continue;
            for(Edge& edge:G[v]){
                if(dist[edge.to]>dist[v]+edge.cost){
                    dist[edge.to]=dist[v]+edge.cost+(ll)ceil(((ld)now/(ld)edge.K))*edge.K;
                    now=edge.cost+(ll)ceil(((ld)now/(ld)edge.K))*edge.K;
                    auto pr=make_pair(dist[edge.to],now);
                    que.emplace(pr,edge.to);
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
    /*
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
    */
};




int solve(){
    ll city,rail,start,goal;
    cin>>city>>rail>>start>>goal;
    start--;goal--;
    graph g(city);
    rep(i,rail) {
        ll from,to,cost,K;
        cin>>from>>to>>cost>>K;
        from--;to--;
        g.add_edge(from,to,cost,K);
        g.add_edge(to,from,cost,K);
    }
    auto a1=g.dijkstra(start);
    if(a1.first[goal]==INF) cout<<"-1"<<endl;
    else cout<<a1.first[goal]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}