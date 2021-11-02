#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
template <class T>
using grid = vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

const ll MOD = 1e9 + 7;
const ll INF = 1e17;
//#######################################################################
vector<vector<ll>> input(ll N, ll width) {
    string str;
    vector<vector<ll>> vec(N, vector<ll>(width));
    for (ll i = 0; i < N; ++i) {
        cin >> str;
        reverse(ALL(str));
        for (ll j = 0; j < width; ++j) {
            vec[i][j] = str.back();
            str.pop_back();
        }
    }
    return vec;
}
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
//########################################################################
struct UnionFind {
    vector<ll> parents;
    set<ll> roots;
    vector<set<ll>> member;
    UnionFind(int size) {
        parents.assign(size, -1);
        member = vector<set<ll>>(size);
        rep(i, 0, size) {
            roots.emplace(i);
            member[i].emplace(i);
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
        roots.erase(y);
        for (auto i : member[y]) member[x].emplace(i);
        member[y].clear();
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
    ll getGroups() { return roots.size(); }
    vector<ll> getMembers(ll x) {
        vector<ll> v(ALL(member[findRoot(x)]));
        return v;
    }
};




void solve() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> br(M);
    rep(i, 0, M) {
        ll from, to; cin >> from >> to;
        from--; to--;
        br[i] = make_pair(max(from, to), min(from, to));
    }
    sort(ALL(br));
    set<ll> collapse;
    ll last = -1;
    rep(i, 0, br.size()) {
        ll from, to; tie(to, from) = br[i];
        if (collapse.empty()) {
            collapse.emplace(to - 1);
            last = to - 1;
            continue;
        }
        else {
            if (from <= last) continue;
            else {
                collapse.emplace(to - 1);
                last = to - 1;
            }
        }
    }
    cout << collapse.size() << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
