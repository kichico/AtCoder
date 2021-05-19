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


ll N,M=0;
grid<ll> g;
vector<bool> check(N,false);
ll cnt=0;
vector<ll> dist;

void bfs(ll start){
    rep(i,N) dist.push_back(INF);
    queue<ll> que;
    que.push(start);
    dist[start]=0;
    while(!que.empty()){
        ll position=que.front();
        que.pop();
        for(auto to:g[position]) {
            if(dist[to]==INF) {
                dist[to]=dist[position]+1;
                que.push(to);
            }
        }
    }
}

int solve(){
    cin>>N;
    g=grid<ll>(N);
    rep(i,N-1){
        ll from,to;
        cin>>from>>to;
        from--;to--;
        //cout<<"from,to "<<from<<","<<to<<endl;
        g[from].push_back(to);
        g[to].push_back(from);
    }
    bfs(0);
    auto pr=make_pair(-1,-1);
    //for(auto x:dist) cout<<x<<endl;
    rep(i,N){
        if(pr.first<dist[i]) {
            pr.second=i;
            pr.first=dist[i];
        }
    }
    dist.clear();
    bfs(pr.second);
    //cout<<"max_id "<<pr.second<<endl;
    ll max_distance=-1;
    //for(auto x:dist) cout<<x<<endl;
    rep(i,N) max_distance=max(max_distance,dist[i]);
    cout<<max_distance+1<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
