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
    bool operator==(position& other){
        if((this->x==other.x)&&(this->y==other.y)) return true;
        else return false;
    }
};

vector<vector<char>> area;
vector<ll> dx{1,0,-1,0}, dy{0,1,0,-1};
struct state{
    ll x; ll y; ll direction;
};

void bfs(position s, position g, vector<vector<vector<ll>>>& dist){
    deque<state> que;
    state start;
    rep(i,0,4){
        start.x=s.x; start.y=s.y; start.direction=i;
        que.push_back(start);
    }
    if(s==g) return;
    state now,n,next;
    while(!que.empty()){
        now=que.front(); que.pop_front();
        rep(i,0,4) {
            n=now; n.x+=dx[i]; n.y=dy[i];
            if(area[n.y][n.x]=='#'||n.x>=dist[0].size()||n.x<0||n.y>=dist.size()||n.y<0) continue;
            rep(dir,0,4) {
                ll cost=dist[n.y][n.x][n.direction];
                if(dir!=n.direction) cost++;
                if(dist[n.y][n.x][dir]>cost) dist[n.y][n.x][dir]=cost;
                next=n; next.direction=dir;
                if(dir!=n.direction) que.push_back(next);
                else que.push_front(next);
            } 
            //if(n.x==g.x&&n.y==g.y) return;
        }
    }
}


void solve(){
    ll h,w;cin>>h>>w;
    position start,goal;
    grid<char> f(h,w);
    vector<vector<vector<ll>>> dist(h,vector<vector<ll>>(w,vector<ll>(4,INF)));
    cin>>start.y>>start.x; start.x--;start.y--;
    cin>>goal.y>>goal.x; goal.x--;goal.y--;
    f.input();
    area=f.field;
    ll ans=INF;
    bfs(start,goal,dist);
    rep(i,0,4) ans=min(ans,dist[goal.y][goal.x][i]);
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
