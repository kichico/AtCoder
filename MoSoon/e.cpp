#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const ll MOD = 1e9 + 7;
const ll INF = 1e17;
const vector<ll> dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
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

template <class T>
T vecsum(vector<T>& vec) {
    return accumulate(ALL(vec), (T)0);
}

template<class T, ll>
T vecsum(vector<T>& vec, ll K) {
    ll ret = 0;
    rep(i, 0, K) ret += vec[i];
    return ret;
}

template <class T>
struct grid {
    vector<vector<T>> field;
    grid(ll height, ll width) { field = vector<vector<T>>(height, vector<T>(width, (T)0)); }
    void input() { rep(i, 0, field.size()) rep(j, 0, field[i].size()) cin >> field[i][j]; }
};

//#########################################################################
ll a, b, c;
struct p {
    ld ap, bp, cp;
};
ld ex(ll n) {
    ll sum = a + b + c;
    return ((ld)n / sum) * (100 - n);
}

p exp(ll i, ll j, ll k) {
    ll sum = i + j + k;
    p pp;
    pp.ap = (ld)i / sum;
    pp.bp = (ld)j / sum;
    pp.cp = (ld)k / sum;
    return pp;
}
void solve() {
    cin >> a >> b >> c;
    vector<vector<vector<p>>> dp(100, vector<vector<p>>(100, vector<p>(100)));
    rep(i, 0, 100) rep(j, 0, 100) rep(k, 0, 100) {
        dp[i][j][k] = exp(i, j, k);
    }
    ld aa = 0, bb = 0, cc = 0;
    rep(i, 1, 100) {
        if (a != 0 && a <= i) aa += dp[i][b][c].ap;
        if (b != 0 && b <= i) bb += dp[a][i][c].bp;
        if (c != 0 && c <= i) cc += dp[a][b][i].cp;
    }
    cout << aa << " " << bb << " " << cc << endl;
    //cout << ex(a) << " " << ex(b) << " " << ex(c) << endl;
    //cout << ex(a) + ex(b) + ex(c) << endl;
    cout << aa + bb + cc << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
