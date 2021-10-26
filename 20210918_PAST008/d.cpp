#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const ll MOD=1e9+7;
const ll INF=1e17;
const vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

template<class T>
inline bool isExist(set<T> st, T key){
    if(st.find(key) == st.end()) return false;
    else return true;
}

template<class T,class U>
inline bool isExist(map<T,U> st, T key){
    if(st.find(key) == st.end()) return false;
    else return true;
}
//#########################################################################

void solve(){
    ll x,y; cin>>x>>y;
    ll xx = 1,yy = 1;
    rep(i,1,sqrt(x)+1) if(x%i==0) xx++;
    rep(i,1,sqrt(y)+1) if(y%i==0) yy++;
    if(x == 1) xx = 1;
    if(y == 1) yy = 1;
    if(xx==yy) cout<<"Z"<<endl;
    else twoText(xx>yy,"X","Y");    
}


int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
