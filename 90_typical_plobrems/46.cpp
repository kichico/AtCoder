#include "bits/stdc++.h"
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
    ll N;
    cin >> N;
    vector<ll> a(N), b(N), c(N);
    vector<vector<ll>> cnt(3, vector<ll>(47, 0));
    rep(i, 0, N) {
        cin >> a[i];
        cnt[0][a[i] % 46]++;
    }
    rep(i, 0, N) {
        cin >> b[i];
        cnt[1][b[i] % 46]++;
    }
    rep(i, 0, N) {
        cin >> c[i];
        cnt[2][c[i] % 46]++;
    }
    ll ans = 0;
    rep(i, 0, 47) rep(j, 0, 47) rep(k, 0, 47) {
        if ((i + j + k) % 46 == 0) {
            ll ac = cnt[0][i];
            ll bc = cnt[1][j];
            ll cc = cnt[2][k];
            if (ac != 0 && bc != 0 && cc != 0) ans += ac * bc * cc;
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
