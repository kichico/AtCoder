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
struct position {
    ll x;
    ll y;
    position operator+(const position& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    position posin() {
        ll x, y; cin >> y >> x; x--; y--;
        this->x = x; this->y = y;
        return *this;
    }
};
void solve() {
    ll h, w;
    cin >> h >> w;
    ll N, M; cin >> N >> M;
    vector<position> light(N), block(M);
    grid<bool> a(h, w);
    auto ok = a.field;
    grid<ll> b(h, w);
    auto bright = b.field;
    rep(i, 0, N) light[i].posin();
    rep(i, 0, M) {
        block[i].posin();
        ok[block[i].y][block[i].x] = true;
    }
    position n;
    rep(i, 0, N) {
        n = light[i];
        if (bright[n.y][n.x] >= 1) continue;
        else {
            ll x = n.x; ll y = n.y;
            while (x != w) {
                if (ok[y][x]) break;
                bright[y][x]++;
                x++;
            }
            x = n.x;
            while (x >= 0) {
                if (ok[y][x]) break;
                bright[y][x]++;
                x--;
            }
        }
    }
    rep(i, 0, N) {
        n = light[i];
        if (bright[n.y][n.x] >= 3) continue;
        else {
            ll x = n.x; ll y = n.y;
            while (y != h) {
                if (ok[y][x]) break;
                bright[y][x]++;
                y++;
            }
            y = n.y;
            while (y >= 0) {
                if (ok[y][x]) break;
                bright[y][x]++;
                y--;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, h) rep(j, 0, w) if (bright[i][j] != 0) ans++;
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
