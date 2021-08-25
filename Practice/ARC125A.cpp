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
    ll N, M; cin >> N >> M;
    vector<ll> t(M);
    vector<ll> s;
    set<ll> cs, ct;
    rep(i, 0, N) {
        ll v; cin >> v;
        s.push_back(v);
        cs.emplace(v);
    }
    rep(i, 0, M) { cin >> t[i]; ct.emplace(t[i]); }
    if (cs.size() == 1 && *cs.begin() != *ct.begin()) { cout << -1 << endl; return; }
    else if (cs.size() == 1 && ct.size() == 2) { cout << -1 << endl; return; }
    ll cur = 0;
    ll cnt = 0;
    ll ans = 1;
    while (true) {
        ++cnt;
        ll nowa = cur + cnt;
        ll nowb = cur - cnt;
        if (nowb < 0) nowb += N;
        if (nowa >= N) nowa -= N;
        if (s[nowa] != s[0]) break;
        else if (s[nowb] != s[0]) break;
    }
    ll dist = cnt;
    bool flg = false;
    if (t[0] != s[0]) {
        ans += dist;
        flg = true;
    }
    ll now = t[0];
    rep(i, 1, M) {
        if (t[i] != now && !flg) {
            ans += dist + 1;
            flg = true;
        }
        else if (t[i] != now) ans += 2;
        else ans++;
        now = t[i];
    }
    cout << ans << endl;
}
 
 
int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}