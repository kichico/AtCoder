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
    if (vec.empty()) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < size - 1; ++i) cout << vec[i] << " ";
    cout << vec.back() << endl;
}

void op(vector<vector<ll>> vec) {
    ll height = (ll)vec.size();
    ll width = (ll)vec[0].size();
    if (vec.empty()) {
        cout << endl;
        return;
    }
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
    vector<string> ss(N); rep(i, 0, N) cin >> ss[i];
    map<ll, set<ll>> ord;
    rep(i, 0, ss.front().size()) {
        vector<ll> cnt(10, 1);
        rep(j, 0, N) {
            ll num = ss[j][i] - '0';
            auto v = ord[num];
            if (v.find(i) != v.end()) {
                ll t = i + 10 * cnt[num];
                ord[num].emplace(t);
                cnt[num]++;
            }
            else ord[num].emplace(i);
        }
    }
    ll ans = INF;
    rep(i, 0, ss.front().size()) {
        auto st = ord[i];
        ans = min(ans, *st.rbegin());
        //cout << i << ":";
        //fore(x, st) cout << x << " ";
        //cout << endl;
    }
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
