﻿#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const ll MOD=1e9+7;
const ll INF=1e17;
const vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

template<class T,ll>
T vecsum(vector<T>& vec, ll K){
    ll ret = 0;
    rep(i,0,K) ret+=vec[i];
    return ret;
}
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

void solve(){
    ll N,M; cin>>N>>M;
    createGraph g(N);
    g.inputAndAddEdge(M);
    queue<pair<ll,ll>> que;
    que.emplace(make_pair(0,0));
    vector<bool> visited(N);
    while(!que.empty()){
        auto n = que.front(); que.pop();
        visited[n.first] = true;
        if(g.graph[n.first].empty()) continue;
        for(auto x:g.graph[n.first]){
            if(!visited[x]) que.emplace(make_pair(x,n.second + 1));
            if(n.first == N-1){
                if(n.second == 2) { cout<<"POSSIBLE"<<endl; return; }
                else cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
