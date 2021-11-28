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
    set<ll> roots;
    vector<set<ll>> member;
    UnionFind(int size) {
        parents.assign(size, -1);
        //member = vector<set<ll>>(size);
        rep(i, 0, size) {
            roots.emplace(i);
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
        roots.erase(y);
        //for (auto i : member[y]) member[x].emplace(i);
        //member[y].clear();
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
    ll N, M; cin >> N >> M;
    UnionFind uf(N);
    vector<vector<ll>> edge(N);
    rep(i, 0, M) {
        ll from, to; cin >> from >> to; from--; to--;
        edge[from].emplace_back(to);
    }
    rep(i, 0, N) if (!edge[i].empty()) sort(ALL(edge[i]));
    vector<ll> ans(N);
    ans[N - 1] = 0;
    ll cnt = 0;
    rep(i, 0, N) {
        ll now = N - i - 1;
        cnt++;
        fore(n, edge[now]) if(!uf.isSameGroup(now,n)) {
            uf.unite(now, n);
            cnt--;
        }
        //ll dist = distance(uf.roots.begin(), uf.roots.lower_bound(now));
        ans[now] = cnt;//uf.roots.size() - dist;
    }
    ans.emplace_back(0);
    ans.erase(ans.begin());
    op(ans);
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
