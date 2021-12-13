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
struct UnionFind {
    vector<ll> parents;
    vector<ll> roots;
    //vector<set<ll>> member;
    UnionFind(int size) {
        parents.assign(size, -1);
        //member = vector<set<ll>>(size);
        rep(i, 0, size) {
            roots.emplace_back(i);
            //member[i].emplace(i);
        }
    }
    ll findRoot(ll x) {
        if (parents[x] < 0) return x;
        return parents[x] = findRoot(parents[x]);
    }
    bool unite(ll x, ll y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (parents[x] > parents[y]) swap(x, y);
        parents[x] += parents[y];
        parents[y] = x;
        iter_swap(lower_bound(ALL(roots), y), roots.end() - 1);
        roots.pop_back();
        sort(ALL(roots));
        //for (auto&& i : member[y]) member[x].emplace(i);
        //member[y].clear();
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
    ll getGroups() { return roots.size(); }
    /*vector<ll> getMembers(ll x) {
        vector<ll> v(ALL(member[findRoot(x)]));
        return v;
    }*/
};
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

ld calEuclid(pair<ll, ll>& x, pair<ll, ll>& y) {
    return round(sqrt((ld)(pow(x.first, 2) - pow(y.first, 2)) + (pow(x.second, 2) - pow(y.second, 2));
}


void solve() {
    ll N = 400, M = 1995;
    vector<unordered_set<ll>> g(N);
    vector<position> pos(N);
    vector<pair<ll, ll>> edge(M);
    vector<unordered_set<ll>> connected(N);
    rep(i, 0, N) pos[i].posin();
    rep(i, 0, M) {
        ll x, y; cin >> x >> y; x--; y--;
        g[x].emplace(y); g[y].emplace(x);
        auto pr = make_pair(x, y);
        edge[i] = pr;
    }
    rep(i, 0, M) {
        ll len; cin >> len;
        ld euclid =
    }
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
