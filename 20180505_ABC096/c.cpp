#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

const ll MOD=1e9+7;
const ll INF=1e17;
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
grid<char> field;

vector<ll> dx{1,0,-1,0};
vector<ll> dy{0,-1,0,1};
bool check(ll x, ll y){
    rep(i,0,4) {
        ll nx=x+dx[i];
        ll ny=y+dy[i];
        if(nx>=width||nx<0||ny>=height||ny<0) continue;
        else if(field[ny][nx]=='#') return true;
    }
    return false;
}


void solve(){
    cin>>height>>width;
    field=grid<char>(height,vector<char>(width));
    rep(i,0,height) rep(j,0,width) cin>>field[i][j];
    rep(i,0,height) rep(j,0,width) {
        if(field[i][j]=='#'){
            if(!check(j,i)) {cout<<"No"<<endl;return;}
        } 
    }
    cout<<"Yes"<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
