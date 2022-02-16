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
vector<ll> h;

using P = pair<ll, ll>;
struct Edge {
    ll from;
    ll to;
    ll cost;
};
using Edges = vector<Edge>;
const ll INF = 1LL << 60;
bool bellman_ford(const Edges& Es, ll V, ll s, vector<ll>& dis) {
    dis.resize(V, INF);
    dis[s] = 0;
    ll cnt = 0;
    while (cnt < V) {
        bool end = true;
        for (auto e : Es) {
            if (dis[e.from] != INF && dis[e.from] + e.cost < dis[e.to]) {
                cout << "from:" << e.from << " to:" << e.to << " cost:" << e.cost << endl;
                dis[e.to] = dis[e.from] + e.cost;
                end = false;
            }
        }
        if (end) break;
        cnt++;
    }
    return (cnt == V);
}
void solve() {
    ll N, M; cin >> N >> M;
    h.assign(N, 0); rep(i, 0, N) cin >> h[i];
    vector<Edge> graph(N);
    rep(i, 0, M) {
        ll from, to; cin >> from >> to;
        from--; to--;
        ll costu = 0;
        ll costv = 0;
        if (h[from] > h[to]) {
            costu = h[to] - h[from];
            costv = 2 * (h[from] - h[to]);
        }
        else if (h[from] < h[to]) {
            costv = h[from] - h[to];
            costu = 2 * (h[to] - h[from]);
        }
        Edge u, v;
        u.from = from; u.to = to; u.cost = costu;
        graph[from] = u;
        v.from = to; v.to = from; v.cost = costv;
        graph[to] = v;
    }
    vector<ll> dist(N, INF);
    bellman_ford(graph, N, 0, dist);
    rep(i, 0, N) {
        cout << i + 1 << ":" << dist[i] << endl;
    }
    sort(ALL(dist));
    while (dist.back() == INF) dist.pop_back();
    sort(ALL(dist), greater<ll>());
    cout << abs(dist.back()) << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
