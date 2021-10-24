#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}
//#########################################################################

void solve(){
    ll h,w;
    cin>>h>>w;
    ll N,M; cin>>N>>M;
    vector<pair<ll,ll>> light(N);
    vector<set<ll>> tate(h),yoko(w);
    grid<bool> a(h,w);
    auto ok = a.field;
    rep(i,0,N){
        ll x,y; cin>>x>>y;
        x--; y--;
        light[i] = make_pair(y,x);
    }
    rep(i,0,M){
        ll x,y; cin>>x>>y;
        x--; y--;
        tate[y].emplace(x);
        yoko[x].emplace(y);
    }
    rep(i,0,N){
        ll x,y; tie(y,x) = light[i];
        auto small = tate[y].lower_bound(x);
        auto large = tate[y].upper_bound(x);
        if(small == tate[y].begin()){
            ll nx = x;
            ll lim = -1;
            if(x == *tate[y].begin()) lim = *tate[y].begin();
            while(nx > lim) {
                ok[y][nx] = true;
                nx--;
            }
            nx = x;
            while(nx < *large){
                ok[y][nx] = true;
                nx++;
            }
        }
        else if(large == tate[y].end()){
            ll nx = x;
            while(nx < w){
                ok[y][nx] = true;
                nx++;
            }
            nx = x;
            while(nx > *small) {
                ok[y][nx] = true;
                nx--;
            }
        }
        else {
            ll nx = x;
            while(nx < *large){
                ok[y][nx] = true;
                nx++;
            }
            nx = x;
            while(nx > *small) {
                ok[y][nx] = true;
                nx--;
            }
        }
        small = yoko[x].lower_bound(y);
        large = yoko[x].upper_bound(y);
        if(small == yoko[y].begin()){
            ll ny = y;
            ll lim = -1;
            if(y == *tate[y].begin()) lim = *tate[y].begin();
            while(ny > lim) {
                ok[ny][x] = true;
                ny--;
            }
            ny = y;
            while(ny < *large){
                ok[ny][x] = true;
                ny++;
            }
        }
        else if(large == yoko[x].end()){
            ll ny = y;
            while(ny < w){
                ok[ny][x] = true;
                ny++;
            }
            ny = y;
            while(ny > *small) {
                ok[ny][x] = true;
                ny--;
            }
        }
        else {
            ll ny = y;
            while(ny < *large){
                ok[ny][x] = true;
                ny++;
            }
            ny = y;
            while(ny > *small) {
                ok[ny][x] = true;
                ny--;
            }
        }
    }
    ll ans = 0;
    rep(i,0,h) rep(j,0,w) if(ok[i][j]) ans++;
    cout << ans << endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
