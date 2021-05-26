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

struct position{
    ll x;
    ll y;
};


int solve(){
    graph g(30*30);
    grid<ll> field(30,vector<ll>(30,100000));
    g.gridgraph(field,g);
    rep(i,0,1000){
        string str;
        position start,goal;
        ll a,e;
        cin>>start.y>>start.x>>goal.y>>goal.x;
        position distance;
        if(i%100==0){
            auto pr=g.dijkstra(start.y*30+start.x);
            vector<ll> path=g.getpath(pr.second,goal.y*30+goal.x);
            vector<position> way(path.size());
            rep(p,0,path.size()) {
                way[p].x=path[p%30];
                way[p].y=path[p/30];
            }
            rep(p,0,path.size()){
                distance.x=way[p].x-way[p-1].x;
                distance.y=way[p].y-way[p-1].y;
                if(distance.x>0) rep(j,0,distance.x) str.push_back('R');
                else rep(j,0,abs(distance.x)) str.push_back('L');
                if(distance.y>0) rep(j,0,distance.y) str.push_back('D');
                else rep(j,0,abs(distance.y)) str.push_back('U');
            }
        }
        else{
            distance.x=goal.x-start.x;
            distance.y=goal.y-start.y;
        //cout<<i<<":"<<distance.x<<","<<distance.y<<endl;
        
            if(distance.x>0) rep(j,0,distance.x) str.push_back('R');
            else rep(j,0,abs(distance.x)) str.push_back('L');
            if(distance.y>0) rep(j,0,distance.y) str.push_back('D');
            else rep(j,0,abs(distance.y)) str.push_back('U');
        }
        cout<<str<<endl;
        cout<<flush;
        //res.push_back(str);
        ll dist;
        cin>>dist;
        ll ave_dist=round((double)dist/(ll)str.size());
        rep(i,min(start.x,goal.x),max(start.x,goal.x)){
            rep(j,min(start.y,goal.y),max(start.y,goal.y)){
                g.G[j][i].cost=min(g.G[j][i].cost,ave_dist);
            }
        }
    }
    //rep(i,0,res.size()) cout<<res[i]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
