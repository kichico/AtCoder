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
        ll x, y; cin >> x >> y; x--; y--;
        this->x = x; this->y = y;
        return *this;
    }
};

void solve() {
    ll h, w;
    cin >> h >> w;
    grid<ll> a(h, w);
    a.input();
    auto area = a.field;
    vector<pair<position, position>> ans;
    rep(i, 0, h) rep(j, 0, w - 1) {
        if (area[i][j] % 2 != 0) {
            area[i][j + 1]++;
            area[i][j]--;
            position from, to;
            from.x = j + 1; from.y = i + 1;
            to.x = j + 2; to.y = i + 1;
            ans.emplace_back(make_pair(from, to));
        }
    }
    rep(i, 0, h - 1) {
        if (area[i][w - 1] % 2 != 0) {
            area[i + 1][w - 1]++;
            area[i][w - 1]--;
            position from, to;
            from.x = to.x = w; from.y = i + 1;
            to.y = i + 2;
            ans.emplace_back(make_pair(from, to));
        }
    }
    cout << ans.size() << endl;
    rep(i, 0, ans.size()) cout << ans[i].first.y << " " << ans[i].first.x << " " << ans[i].second.y << " " << ans[i].second.x << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
