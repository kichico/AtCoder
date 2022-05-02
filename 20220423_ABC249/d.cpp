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

ll modpow(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ans;
}

ll com(ll n, ll k, vector<ll> fac_n, vector<ll> fac_k) {
    if (n == 0 && k == 0) return 1;
    if (n < k || n < 0) return 0;
    ll value = fac_k[n - k] * fac_k[k] % MOD;
    return value * fac_n[n] % MOD;
}





void solve() {
    ll N; cin >> N;
    vector<ll> a(N); unordered_map<ll, ll> cnt;
    vector<bool> included(3e5, false);
    ll lim = 300001;
    vector<ll> fac_n(lim);
    vector<ll> fac_k(lim);
    fac_n[0] = 1;
    fac_k[0] = 1;
    for (ll i = 0; i < lim - 1; ++i) {
        fac_n[i + 1] = fac_n[i] * (i + 1) % MOD;
        fac_k[i + 1] = fac_k[i] * modpow(i + 1, MOD - 2) % MOD;
    }
    rep(i, 0, N) {
        cin >> a[i];
        cnt[a[i]]++;
        included[a[i]] = true;
    }
    ll ans = 0;
    fore(x, cnt) {
        ll v = x.first;
        rep(j, 1, sqrt(v) + 1) {
            if (v % j != 0) continue;
            ll div = v / j;
            cout << "num:" << v << " div:" << div << " another:" << j << endl;
            if (included[div] && included[j]) {
                if (div == j) {
                    if (cnt[div] == 1) continue;
                    ll left = cnt[div];
                    if (div == v) left--;
                    if (left - 1 <= 0) continue;
                    ans += left * (left - 1);
                    cout << "div's:" << left << " another's:" << left - 1 << endl;
                    cout << "ans:" << ans << endl;
                }
                else {
                    ll left = cnt[div];
                    ll right = cnt[j];
                    if (div == v) left--;
                    if (j == v) right--;
                    ans += (left * right) * x.second;
                    cout << "div's:" << left << " another's:" << right << endl;
                    cout << "ans:" << ans << endl;
                }
            }
        }
    }
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
