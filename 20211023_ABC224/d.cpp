#include "bits/stdc++.h"
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

void counter(ll& num,ll& increaser,bool checker){
    if(checker) num+=increaser;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
    bool isIntheField(ll x,ll y,ll it){
        ll nx = x + dx[it], ny = y + dy[it];
        if(nx < 0 || ny < 0 || nx >= field[0].size() || ny >= field.size()) return false;
        else return true;
    }
    bool isIntheField(ll x, ll y, ll it, T check){
        ll nx = x + dx[it], ny = y + dy[it];
        if(nx < 0 || ny < 0 || nx >= field[0].size() || ny >= field.size()) return false;
        else if(field[ny][nx] == check) return false;
        else return true;
    }
};

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

struct position{
    ll x;
    ll y;
    position operator+(const position& other){
        this->x+=other.x;
        this->y+=other.y;
        return *this;
    }
    position posin(){
        ll x,y; cin>>x>>y; x--; y--;
        this->x = x; this->y = y;
        return *this;
    }
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


void solve(){
    ll M;
    cin>>M;
    createGraph g(9);
    vector<position> pos(M);
    rep(i,0,M) pos[i].posin();
    rep(i,0,M) g.addEdge(make_pair(pos[i].x,pos[i].y));
    string s = "999999999";
    rep(i,0,8) { ll v; cin>>v; v--; s[v] = i + '1'; }
    queue<string> que;
    que.emplace(s);
    map<string,ll> dict;
    dict[s] = 0;
    while(!que.empty()){
        auto t = que.front(); que.pop();
        ll start;
        rep(i,0,t.size()) if(t[i] == '9') start = i;
        fore(x,g.graph[start]){
            auto next = t;
            swap(next[x],next[start]);
            if(dict.find(next) != dict.end()) continue;
            dict[next] = dict[t] + 1;
            que.emplace(next);
        }
    }
    if(dict.find("123456789") == dict.end()) cout<<-1<<endl;
    else cout<<dict["123456789"]<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
