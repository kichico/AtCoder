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
struct createGraph{
    vector<vector<ll>> graph;
    createGraph(ll N) {
        graph.resize(N);
    }
    void addEdge(ll from, ll to){
        graph[from].emplace_back(to);
    }
    void addEdge(pair<ll,ll> pr){
        graph[pr.first].emplace_back(pr.second);
        graph[pr.second].emplace_back(pr.first);
    }
    void inputAndAddEdge(ll M){
        set<pair<ll,ll>> checker;
        pair<ll,ll> inserter;
        rep(i,0,M){
            ll from,to;
            cin>>from>>to;
            from--;to--;
            inserter=make_pair(min(from,to),max(from,to));
            if(checker.count(inserter)==0) {
                addEdge(inserter);
                checker.insert(inserter);
            }
        }
    }
    void showGrapgh(){
        rep(i,0,graph.size()){
            string out=to_string(i)+":";
            rep(j,0,graph[i].size()) out+=to_string(graph[i][j])+" ";
            if(out.back()!=':') out.pop_back();
            cout<<out<<endl;
        }
    }
};
vector<bool> visited;
void dfs(ll x, vector<ll> &score, vector<ll> &cnt,createGraph& g) {
    queue<ll> que;
    if(visited[x]) return;
    visited[x]=true;
    cnt[x]+=score[x];
    rep(i,0,g.graph[x].size()) que.push(g.graph[x][i]);
    while(!que.empty()){
        ll next=que.front(); que.pop();
        if(visited[next]) continue;
        score[next]+=score[x];
        dfs(next,score,cnt,g);
    }
    return;
}




void solve(){
    ll N,q;
    cin>>N>>q;
    createGraph g(N);
    vector<ll> score(N,0);
    vector<ll> cnt(N,0);
    visited.assign(N,false);
    rep(i,0,N-1){
        ll from,to; cin>>from>>to; from--;to--;
        g.addEdge(from,to);
        g.addEdge(to,from);
    }
    rep(i,0,q){
        ll x,v; cin>>x>>v;x--;
        score[x]+=v;
    }
    dfs(0,score,cnt,g);
    for(auto x:cnt) cout<<x<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
