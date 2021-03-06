#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

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

template <class T>
T vecsum(vector<T>& vec) {
    return accumulate(ALL(vec), (T)0);
}
//#########################################################################

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N); rep(i, 0, N) cin >> a[i];
    ll sum = vecsum(a);
    vector<ll> ch = a;
    ll ans = 0;
    vector<vector<ll>> dp(N + 1, vector<ll>(2, sum));
    dp[0][1] -= (a[0] + a[1]);
    dp[0][1] += (a[0] * -1) + (a[1] * -1);
    rep(i, 1, N - 1) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        ll minus = a[i] + a[i + 1];
        ll plus = a[i] * -1 + a[i + 1] * -1;
        dp[i][1] = max(dp[i - 1][0] - minus + plus, dp[i - 1][1] - (a[i] * -1) - a[i + 1] + a[i] + (a[i + 1]) * -1);
        //cout << i << ":" << dp[i][0] << " " << dp[i][1] << endl;
        //cout << i + 1 << ":" << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    }
    cout << max(dp[N - 2][0], dp[N - 2][1]) << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
