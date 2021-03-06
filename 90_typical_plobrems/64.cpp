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
    rep(i, 0, K) ret += abns(vec[i]);
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
    ll N, q;
    cin >> N >> q;
    vector<ll> a(N + 1), diff(N, 0);
    ll sum = 0;
    rep(i, 0, N) {
        cin >> a[i];
    }
    rep(i, 0, N - 1) diff[i] = a[i + 1] - a[i];
    fore(x, diff) sum += abs(x);
    vector<ll> R(q), L(q), V(q);
    rep(i, 0, q) {
        cin >> L[i] >> R[i] >> V[i];
        R[i]--; L[i]--;
    }
    vector<ll> ans(q, sum);
    rep(i, 0, q) {
        ans[i] = sum;
        ll prev = 0;
        ll cur = 0;
        if (L[i] != 0) {
            prev += abs(diff[L[i] - 1]);
            diff[L[i] - 1] += V[i];
            cur += abs(diff[L[i] - 1]);
        }
        if (R[i] != N - 1) {
            prev += abs(diff[R[i]]);
            diff[R[i]] -= V[i];
            cur += abs(diff[R[i]]);
        }
        ans[i] += (cur - prev);
        sum += (cur - prev);
    }
    rep(i, 0, q) cout << ans[i] << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
