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
struct position {
    ll x;
    ll y;
    position operator+(const position& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    position posin() {
        ll x, y; cin >> x >> y; //x--; y--;
        this->x = x; this->y = y;
        return *this;
    }
};
void solve() {
    ll N; cin >> N;
    vector<position> pos(N); rep(i, 0, N) pos[i].posin();
    set<ld> ans;
    rep(i, 0, N - 1) rep(j, i + 1, N) {
        ll lx = abs(pos[i].x - pos[j].x);
        ll ly = abs(pos[i].y - pos[j].y);
        ld dist = sqrt(lx * lx + ly * ly);
        ans.emplace(dist);
    }
    cout << *ans.rbegin() << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
