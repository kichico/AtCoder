#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template<class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(i,start,N) for(ll i=start;i<N;++i)

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

void solve(){
    ll N,M;
    cin>>N>>M;
    grid<ll> graph(N);
    rep(i,0,M) {
        ll a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    rep(i,0,N) {
        cout<<i<<":";
        rep(j,0,graph[i].size()) cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    ll maxv=0;
    vector<ll> best(3);
    rep(i,0,N) {
        rep(j,i,N) {
            rep(k,j,N){
                if(i==j||i==k||j==k) continue;
                set<ll> s;
                rep(v,0,graph[i].size()) s.insert(graph[i][v]);
                rep(v,0,graph[j].size()) s.insert(graph[j][v]);
                rep(v,0,graph[k].size()) s.insert(graph[k][v]);
                //cout<<"(i,j,k):"<<i<<" "<<j<<" "<<k<<endl;
                if(maxv<s.size()) {
                    best={i,j,k};
                    maxv=s.size();
                }
            }
        }
    }
    cout<<maxv<<endl;
    sort(ALL(best));
    string out;
    rep(i,0,3) out+=to_string(best[i])+" ";
    out.pop_back();
    cout<<out<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}