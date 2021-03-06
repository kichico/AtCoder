#include "bits/stdc++.h"
#include <fstream>
#include <sstream>
using namespace std;
using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
 
const ll MOD = 1e9 + 7;
const ll INF = 1e17;
//#######################################################################
void op(vector<ll> vec) {
    ll size = (ll)vec.size();
    for (ll i = 0; i < size - 1; ++i) cout << vec[i] << " ";
    cout << vec.back() << endl;
}
 
void op(vector<vector<ll>> vec) {
    ll height = (ll)vec.size();
    ll width = (ll)vec[0].size();
    for (ll i = 0; i < height; ++i) {
        for (ll j = 0; j < width - 1; ++j) cout << vec[i][j] << " ";
        cout << vec[i].back() << endl;
    }
}
 
void twoText(bool identifier, string outTrue, string outFalse) {
    if (identifier) cout << outTrue << endl;
    else cout << outFalse << endl;
}
 
void twoText(bool identifier) {
    if (identifier) cout << "Yes" << endl;
    else cout << "No" << endl;
}
 
void counter(ll& num, ll& increaser, bool checker) {
    if (checker) num += increaser;
}
 
template <class T>
struct grid {
    vector<vector<T>> field;
    grid(ll height, ll width) { field = vector<vector<T>>(height, vector<T>(width, (T)0)); }
    void input() { rep(i, 0, field.size()) rep(j, 0, field[i].size()) cin >> field[i][j]; }
};
 
//#########################################################################
 
void solve() {
    string s; cin>>s;
    vector<ll> ans(s.size()+2,0);
    ll N=s.size();
    rep(i,0,N){
        if(i==0&&s[i]=='<') ans[0]=0;
        else if(i!=0||i!=N-1){
            if(s[i-1]=='>'&&s[i]=='<') ans[i]=0;
        }
    }
    if(s.back()=='>') ans.back()=0;
    rep(i,0,N){
        if(s[i]=='<') ans[i+1]=max(ans[i+1],ans[i]+1);
    }
    rep(i,0,N) {
        ll now=N-i-1;
        if(s[now]=='>') ans[now]=max(ans[now+1]+1,ans[now]);
    }
    cout<<accumulate(ALL(ans),ll(0))<<endl;
}
 
 
int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}