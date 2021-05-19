#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
//typedef vector<vector<char>> grid;
//typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)

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

template<typename T>
using grid=vector<vector<T>>;

struct position {
    ll x;
    ll y;
};
grid<char> field;

ll BFS(grid<ll>& field,position start, position goal){
    ll INF=1e10;
    ll height=(ll)field.size();
    ll width=(ll)field[0].size();
    vector<vector<ll>> dist((ll)field.size(),vector<ll>((ll)field[0].size(),1e10));
    queue<position> que;
    vector<ll> dx{1,0,-1,0};
    vector<ll> dy{0,1,0,-1};
    que.push(start);
    dist[start.y][start.x]=0;
    while(!que.empty()){
        position pos=que.front();que.pop();
        if(pos.x==goal.x&&pos.y==goal.y) break;
        rep(i,4) {
            ll nx=pos.x+dx[i];
            ll ny=pos.y+dy[i];
            if(nx>=0&&nx<width&&ny>=0&&ny<height&&field[ny][nx]!='#'&&dist[ny][nx]==INF){
                position next;
                next.x=nx,next.y=ny;
                que.push(next);
                dist[ny][nx]=dist[pos.y][pos.x]+1;
            }
        }
    }
    return dist[goal.y][goal.x];
}





int solve(){
    position start,goal;
    ll height,width;
    cin>>height>>width;
    //grid field(height,vector<char>(width));
    cin>>start.y>>start.x;
    cin>>goal.y>>goal.x;
    start.x--;start.y--;goal.x--;goal.y--;
    rep(i,height) rep(j,width) cin>>field[i][j];
    cout<<BFS(field,start,goal)<<endl;;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}