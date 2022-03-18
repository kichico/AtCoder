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
    ll h, w; cin >> h >> w;
    grid<ll> p(h, w); p.input();
    auto& area = p.field;
    ll ans = 0;
    rep(bit, 0, 1 << 8) {
        bitset<8> s{ bit };
        vector<ll> picked;
        rep(i, 0, h) if (s.test(i)) picked.emplace_back(i);
        vector<ll> pass;
        if (picked.empty()) continue;
        map<ll, ll> num;
        rep(c, 0, w) {
            bool flg = true;
            ll init = area[picked[0]][c];
            rep(r, 1, picked.size()) if (area[picked[r]][c] != init) {
                flg = false;
                break;
            }
            if (flg) {
                pass.emplace_back(init);
                num[init]++;
            }
        }
        cout << "pass:";
        op(pass);
        cout << "picked:";
        op(picked);
        for (auto& x : pass) ans = max(x * picked.size(), ans);
    }
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
