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
struct createGraph {
    vector<unordered_set<ll>> graph;
    createGraph(ll N) {
        graph.resize(N);
    }
    void addEdge(ll from, ll to) {
        graph[from].emplace(to);
    }
    void addEdge(pair<ll, ll> pr) {
        graph[pr.first].emplace(pr.second);
        graph[pr.second].emplace(pr.first);
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
};

void solve() {
    ll N; cin >> N;
    createGraph g(N);
    g.inputAndAddEdge(N - 1);
    vector<pair<ll, ll>> depth(N);
    ll root = 0;
    depth.assign(N, make_pair(0, 0));
    vector<bool> visited(N, false);
    queue<ll> que; que.emplace(root);
    map<ll, vector<ll>> dict;
    dict[0].emplace_back(0);
    vector<vector<ll>> directed(N);
    while (!que.empty()) {
        ll par = que.front(); que.pop();
        visited[par] = true;
        fore(x, g.graph[par]) {
            if (visited[x]) continue;
            que.emplace(x);
            directed[par].emplace_back(x);
            depth[x] = make_pair(depth[par].first + 1, x);
            dict[depth[x].first].emplace_back(depth[x].second);
        }
    }
    sort(ALL(depth));
    visited.assign(N, false);
    ll cnt = 1;
    vector<set<ll>> tree(N);
    rep(i, 0, N) if (directed[depth[i].second].empty()) {
        tree[depth[i].second].emplace(cnt);
        cnt++;
    }
    auto it = dict.rbegin();
    it++;
    for (; it != dict.rend(); it++) {
        auto v = *it;
        for (auto& par : v.second) {
            for (auto& child : directed[par]) {
                tree[par].emplace(*tree[child].begin());
                tree[par].emplace(*tree[child].rbegin());
            }
        }
    }
    for (auto& t : tree) {
        cout << *t.begin() << " " << *t.rbegin() << endl;
    }
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
