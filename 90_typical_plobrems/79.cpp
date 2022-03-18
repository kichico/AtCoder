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
    ll h, w; cin >> h >> w;
    grid<ll> a(h, w), b(h, w); a.input(); b.input();
    auto& af = a.field;
    ll cnt = 0;
    vector<ll> dx{ 0,1,0,1 }, dy{ 0,0,1,1 };
    rep(i, 0, h - 1) rep(j, 0, w - 1) {
        ll diff = b.field[i][j] - af[i][j];
        if (diff != 0) {
            rep(k, 0, 4) {
                ll ny = i + dy[k], nx = j + dx[k];
                af[ny][nx] += diff;
            }
            cnt++;
        }
    }
    rep(i, 0, h) if (af[i][w - 1] != b.field[i][w - 1]) {
        cout << "No" << endl;
        return;
    }
    rep(i, 0, w) if (af[h - 1][i] != b.field[h - 1][i]) {
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    cout << cnt << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
