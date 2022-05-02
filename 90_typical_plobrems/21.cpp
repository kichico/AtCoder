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
struct createGraph {
    vector<vector<ll>> graph;
    createGraph(ll N) {
        graph.resize(N);
    }
    void addEdge(ll from, ll to) {
        graph[from].emplace_back(to);
    }
    void addEdge(pair<ll, ll> pr) {
        graph[pr.first].emplace_back(pr.second);
        graph[pr.second].emplace_back(pr.first);
    }
    void inputAndAddEdge(ll M) {
        set<pair<ll, ll>> checker;
        pair<ll, ll> inserter;
        rep(i, 0, M) {
            ll from, to;
            cin >> from >> to;
            from--; to--;
            inserter = make_pair(min(from, to), max(from, to));
            if (checker.count(inserter) == 0) {
                addEdge(inserter);
                checker.insert(inserter);
            }
        }
    }
    void showGrapgh() {
        rep(i, 0, graph.size()) {
            string out = to_string(i) + ":";
            rep(j, 0, graph[i].size()) out += to_string(graph[i][j]) + " ";
            if (out.back() != ':') out.pop_back();
            cout << out << endl;
        }
    }
};
struct UnionFind {
    vector<ll> parents;
    UnionFind(int size) {
        parents.assign(size, -1);
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
        return true;
    }
    ll size(ll x) { return -parents[findRoot(x)]; }
    bool isSameGroup(ll x, ll y) { return findRoot(x) == findRoot(y); }
};
vector<bool> visited;
vector<pair<ll, ll>> rankk;
vector<ll> team;
ll ord;

void dfs(createGraph& g, ll now) {
    if (visited[now]) return;
    visited[now] = true;
    for (auto n : g.graph[now]) {
        if (visited[n]) continue;
        dfs(g, n);
    }
    rankk[now].first = ord++;
}

void dfs2(vector<vector<ll>>& g, ll now, ll cnt) {
    visited[now] = true;
    for (auto n : g[now]) {
        if (visited[n]) continue;
        dfs2(g, n, cnt);
    }
    team[now] = ord;
}

void solve() {
    ll N, M; cin >> N >> M;
    createGraph g(N);
    rep(i, 0, M) {
        ll from, to; cin >> from >> to;
        g.graph[from].emplace_back(to);
    }
    rankk.assign(N, make_pair(0, 0));
    rep(i, 0, N) rankk[i].second = i;
    visited.assign(N, false);
    ord = 0;
    rep(i, 0, N) if (!visited[i]) dfs(g, i);
    vector<vector<ll>> ng(N);
    rep(i, 0, N) rep(j, 0, g.graph[i].size()) {
        ng[g.graph[i][j]].emplace_back(i);
    }
    visited.assign(N, false);
    sort(ALL(rankk));
    team.assign(N, -1);
    ord = 0;
    UnionFind uf(N);
    rep(i, 0, N) {
        ll ID = rankk[i].second;
        if (!visited[ID]) dfs2(g.graph, ID, ord);
        ord++;
    }
    rep(i, 0, N) {
        cout << i << ":" << team[i] << endl;
    }
    ll Q; cin >> Q;
    vector<ll> ans(Q);
    rep(i, 0, Q) {
        ll a, b; cin >> a >> b;
        if (team[a] != team[b]) ans[i] = 1;
        else ans[i] = 0;
    }
    for (auto x : ans) cout << x << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
