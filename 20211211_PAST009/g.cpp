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
bool bfs(ll start, ll goal, vector<unordered_set<ll>>& g) {
    queue<ll> que;
    que.emplace(start);
    vector<bool> visited(g.size(), false);
    while (!que.empty()) {
        ll n = que.front(); que.pop();
        for (auto& x : g[n]) if (!visited[x]) {
            visited[x] = true;
            if (x == goal) return true;
            que.emplace(x);
        }
    }
    return false;
}


void solve() {
    ll N, Q; cin >> N >> Q;
    vector<unordered_set<ll>> g(N);
    set<pair<ll, ll>> edges;
    vector<string> ans;
    rep(i, 0, Q) {
        ll k, u, v; cin >> k >> u >> v;
        u--; v--;
        auto pr = make_pair(min(u, v), max(u, v));
        if (k == 1) {
            if (edges.find(pr) == edges.end()) {
                edges.emplace(pr);
                g[u].emplace(v); g[v].emplace(u);
            }
            else {
                edges.erase(pr);
                g[u].erase(v); g[v].erase(u);
            }
        }
        else {
            bool flg = bfs(u, v, g);
            if (flg)ans.emplace_back("Yes");
            else ans.emplace_back("No");
        }
    }
    rep(i, 0, ans.size()) cout << ans[i] << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
