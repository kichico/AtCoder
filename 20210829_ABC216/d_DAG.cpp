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

struct nodeInformation{
    ll income;
    vector<ll> to;
};

struct Directedgraph{
    vector<nodeInformation> graph;
    Directedgraph(ll n){ graph=vector<nodeInformation>(n);}
    void addEdge(ll from, ll to){
        graph[from].to.emplace_back(to);
        graph[to].income++;
    }
};

bool compare(const nodeInformation& fr, const nodeInformation& se){
    return fr.income<se.income;
}

void solve(){
    ll N,M; cin>>N>>M;
    vector<vector<ll>> t;
    vector<vector<ll>> pos(N+1);
    set<ll> checker;
    Directedgraph g(N);
    map<ll,ll> boalnumtopos;
    ll now=0;
    rep(i,0,M){
        ll k; cin>>k;
        rep(j,0,k) {
            ll v; cin>>v;
            t[i].emplace_back(v);
            pos[v].emplace_back(now+j);
            boalnumtopos[now+j]=v;
        }
        now+=(ll)t[i].size();
    }
    now=0;
    rep(i,0,M) {
        rep(j,0,t[i].size()-1){
            ll v=t[i][j];
            ll from=pos[v][0]; ll to=pos[v][1];
            if(checker.find(t[i][j])!=checker.end()) g.addEdge(from,to);
            checker.emplace(v);
            v=boalnumtopos[now+j+1];
            
        }
        now+=(ll)t[i].size();
    }
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
