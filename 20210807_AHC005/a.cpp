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

struct position{
   ll x;
   ll y;
};
vector<ll> dx{1,0,-1,0};
vector<ll> dy{0,1,0,-1};
vector<char> ds{'R','D','L','U'};
vector<char> opp{'L','U','R','D'};
struct check{
    bool visited;
    bool looked;
    char kabe;
};
ll N;
string ans;

bool dfs(position p,ll direction, bool isIkidomari,vector<vector<check>>& field){
    queue<position> around;
    field[p.y][p.x].looked=true;
    auto tp=p;
    tp=p;
    tp.x+=dx[direction];tp.y+=dy[direction];
    if(tp.x<0||tp.x>=N||tp.y<0||tp.y>=N) return isIkidomari;
    if(field[tp.y][tp.x].kabe=='#') return isIkidomari;
    around.emplace(tp);
    rep(i,0,4){
        if(direction==i) continue;
        tp=p;
        tp.x+=dx[i]; tp.y=dy[i];
        if(tp.x<0||tp.x>=N||tp.y<0||tp.y>=N) continue;
        if(field[tp.y][tp.x].kabe=='#') continue;
        if(!field[tp.y][tp.x].looked) around.emplace(tp);
    }
    if(around.size()!=1) isIkidomari=false; 
    tp=around.front();
    return dfs(tp,direction,isIkidomari,field);
}

bool isAllCellLooked(vector<vector<check>>& field){
    rep(i,0,N) rep(j,0,N) if(!field[i][j].looked) return false;
    return true;
}

string chokushin(position p,string s,ll direction){
    
}

void bfs(position start, vector<vector<check>>& field){
    queue<position> que;
    que.emplace(start);
    while(!que.empty()){
        position now=que.front(); que.pop();
        rep(i,0,4){
            now.x+=dx[i]; now.y+=dy[i];
            if(now.x<0||now.x>=N||now.y<0||now.y>=N) continue;
            if(field[now.y][now.x].kabe=='#') continue;
            if(!field[now.y][now.x].visited) 
        }
        if(isAllCellLooked) return;
    }
}

void solve(){
    position start;
    cin>>N>>start.y>>start.x;
    grid<check> a(N,N);
    auto area=a.field;
    rep(i,0,N){
        string s; cin>>s;
        rep(j,0,N) area[i][j].kabe=s[j];
    }
    
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
