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
ll height,width;
grid<bool> painted;
struct position{
    ll x;
    ll y;
};

bool bfs(position start,position goal){
    if(painted[start.y][start.x]==false||painted[goal.y][goal.x]==false) return false;
    if(start.x==goal.x&&start.y==goal.y) return true;
    queue<position> que;
    vector<ll> dx{1,0,-1,0};
    vector<ll> dy{0,1,0,-1};
    grid<ll> dist(height,vector<ll>(width,INF));
    dist[start.y][start.x]=0;
    que.push(start);
    while(!que.empty()){
        position pos=que.front();que.pop();
        if(pos.x==goal.x&&pos.y==goal.y) return true;
        rep(i,4) {
            ll nx=pos.x+dx[i];
            ll ny=pos.y+dy[i];
            if(nx>=0&&nx<width&&ny>=0&&ny<height&&painted[ny][nx]!=false&&dist[ny][nx]==INF){
                position next;
                next.x=nx,next.y=ny;
                que.push(next);
                dist[ny][nx]=dist[pos.y][pos.x]+1;
            }
        }
    }
    if(dist[goal.y][goal.x]!=INF) return true;
    else return false;
}
void solve(){
    cin>>height>>width;
    painted=grid<bool>(height,vector<bool>(width,false));
    ll q;
    cin>>q;
    cin.ignore();
    vector<string> res;
    rep(i,q){
        string str;
        getline(cin,str);
        //cout<<"in:"<<str<<endl;
        if(str[0]=='1') {
            ll row=str[2]-'0'-1;
            ll column=str[4]-'0'-1;
            painted[row][column]=true;
        }
        else{
            position start,goal;
            start.y=str[2]-'0'-1;
            start.x=str[4]-'0'-1;
            goal.y=str[6]-'0'-1;
            goal.x=str[8]-'0'-1;
            if(bfs(start,goal)) res.emplace_back("Yes");
            else res.emplace_back("No");
        }
    }
    for(auto x:res) cout<<x<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
