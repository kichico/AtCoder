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



void solve() {
    ll N, q;
    cin >> N >> q;
    createGraph g(N);
    rep(i,0,N-1){
        ll from,to;
        cin>>from>>to;
        auto pr=make_pair(from-1,to-1);
        g.addEdge(pr);
    }
    vector<ll> dist(N,-1);
    queue<ll> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        ll now=que.front();que.pop();
        for(auto x:g.graph[now]) if(dist[x]==-1) {
            dist[x]=dist[now]+1;
            que.push(x);
        }
    }
    rep(i,0,q){
        ll a,b;
        cin>>a>>b;a--;b--;
        if(dist[a]%2!=dist[b]%2) cout<<"Road"<<endl;
        else cout<<"Town"<<endl;
    }
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
