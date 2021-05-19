#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)
constexpr ll MOD=1e9+7;
constexpr ll INF=1e16;
template<class T>
using grid=vector<vector<T>>;
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

struct position{
    ll x;
    ll y;
};
grid<char> field;
grid<pair<ll,ll>> dist;
ll BFS(grid<char>& field,position start, position goal){
    ll INF=1e10;
    ll height=(ll)field.size();
    ll width=(ll)field[0].size();
    dist=grid<pair<ll,ll>>((ll)field.size(),vector<pair<ll,ll>>((ll)field[0].size(),make_pair(1e10,0)));
    queue<position> que;
    vector<ll> dx{1,0,-1,0};
    vector<ll> dy{0,1,0,-1};
    que.push(start);
    dist[start.y][start.x].first=0;
    position previous=start;
    while(!que.empty()){
        position pos=que.front();que.pop();
        if(pos.x==goal.x&&pos.y==goal.y) break;
        rep(i,4) {
            ll nx=pos.x+dx[i];
            ll ny=pos.y+dy[i];
            if(nx>=0&&nx<width&&ny>=0&&ny<height&&field[ny][nx]!='#'&&dist[ny][nx].first==INF){
                position next;
                next.x=nx,next.y=ny;
                que.push(next);
                pair<ll,ll> vecp,vecc;
                vecp=make_pair(pos.y-previous.y,pos.x-previous.x);
                vecc=make_pair(next.y-pos.y,next.x-pos.x);
                if(((previous.y!=start.y)||(previous.x!=start.x))&&vecc!=vecp) dist[ny][nx].second=dist[pos.y][pos.x].second+1;
                dist[ny][nx].first=dist[pos.y][pos.x].first+1;
            }
        }
        previous=pos;
    }
    return dist[goal.y][goal.x].second;
}


void solve(){
    ll height,width;
    cin>>height>>width;
    field=grid<char>(height,vector<char>(width,'0'));
    position start,goal;
    cin>>start.y>>start.x;
    start.x--;start.y--;
    cin>>goal.y>>goal.x;
    goal.x--;goal.y--;
    rep(i,height) rep(j,width) cin>>field[i][j];
    ll ans=BFS(field,start,goal);
    cout<<ans<<endl;
    rep(i,height) {
        rep(j,width) cout<<dist[i][j].second<<" ";
        cout<<endl;
    }
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
