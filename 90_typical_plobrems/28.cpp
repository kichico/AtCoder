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
    grid(ll height, ll width) { field = vector<vector<T>>(height, vector<T>(width)); }
    void input() { rep(i, 0, field.size()) rep(j, 0, field[i].size()) cin >> field[i][j]; }
};

//#########################################################################
struct position {
    ll x;
    ll y;
    position operator-() {
        this->x -= 1;
        this->y -= 1;
        return *this;
    }
};

void solve() {
    ll N;
    cin >> N;
    ll h = 1001, w = 1001;
    grid<ll> p(h, w);
    auto& paper = p.field;
    rep(i, 0, N) {
        ll sx, sy, gx, gy; cin >> sx >> sy >> gx >> gy;
        //sx--; sy--; gx--; gy--;
        paper[sy][sx]++; paper[gy][gx]++;
        paper[sy][gx]--; paper[gy][sx]--;
    }
    rep(i, 1, h + 1) rep(j, 1, w + 1) paper[i][j] += paper[i][j - 1];
    rep(j, 1, w + 1) rep(i, 1, h + 1) paper[i][j] += paper[i - 1][j];
    map<ll, ll> ans;
    rep(i, 0, h + 1) rep(j, 0, w + 1) ans[paper[i][j]]++;
    rep(i, 0, N) cout << ans[i] << endl;
    rep(i, 0, h + 1) {
        cout << i << ":";
        op(paper[i]);
    }
}



int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
