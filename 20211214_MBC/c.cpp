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
            addEdge(from, to);
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

vector<bool> visited;
ll initial;
vector<ll> loop;
ll K;
vector<ll> ans;

void dfs1(createGraph& g, ll now) {
    if (visited[now]) {
        initial = now;
        return;
    }
    visited[now] = true;
    K--;
    if (K < 0) return;
    ans[now]++;
    dfs1(g, g.graph[now].front());
}
void dfs2(createGraph& g, ll now) {
    if (visited[now]) {
        initial = now;
        return;
    }
    visited[now] = true;
    loop.emplace_back(now);
    dfs2(g, g.graph[now].front());
}

void solve() {
    ll N; cin >> N;
    visited.assign(N, false);
    ans.assign(N, 0);
    cin >> K;
    K++;
    createGraph g(N);
    g.inputAndAddEdge(N);
    dfs1(g, 0);
    visited.assign(N, false);
    dfs2(g, initial);
    if (!loop.empty()) {
        ll L = K / loop.size();
        ll rest = K % loop.size();
        fore(x, loop) ans[x] += L;
        if (rest > 0) fore(x, loop) {
            ans[x]++;
            rest--;
            if (rest <= 0) break;
        }
    }
    forc(x, ans);
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}