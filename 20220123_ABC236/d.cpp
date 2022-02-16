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

void solve() {
    ll N; cin >> N;
    vector<vector<ll>> a(2 * N - 1);
    rep(i, 0, 2 * N - 1) {
        rep(p, i, 2 * N) {
            ll v; cin >> v; a[i].emplace_back(v);
        }
    }
    vector<ll> hito(2 * N); rep(i, 0, 2 * N) hito[i] = i;
    ll ans = 0;
    do {
        ll current = 0;
        vector<ll> h = hito;
        rep(i, 0, N) {
            ll fr = h.back(); h.pop_back();
            ll se = h.back(); h.pop_back();
            if (fr > se) swap(fr, se);
            current ^= a[fr][se];
        }
        ans = max(ans, current);
    }
    while (next_permutation(ALL(hito)));
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
