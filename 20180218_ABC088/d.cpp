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
struct Edge {
    ll to, cost;
    Edge() {}
    Edge(ll to, ll cost = 0) : to(to), cost(cost) {}
};

typedef pair<ll, ll> P;
struct graph {
    const ll INF = numeric_limits<ll>::max();
    vector<vector<Edge>> G;
    ll n;
    graph(ll N) {
        n = N;
        G.resize(n);
    }
    void add_edge(ll from, ll destination, ll cost) {
        G[from].emplace_back(destination, cost);
    }
    pair<vector<ll>, vector<ll>> dijkstra(ll start) {
        vector<ll> dist(n, INF);
        vector<ll> path(n, -1);
        priority_queue<P, vector<P>, greater<P>> que;
        dist[start] = 0;
        que.emplace(0, start);
        while (!que.empty()) {
            P p = que.top();
            que.pop();
            ll v = p.second;
            ll min_dist = p.first;
            if (dist[v] < min_dist) continue;
            for (Edge& edge : G[v]) {
                if (dist[edge.to] > dist[v] + edge.cost) {
                    dist[edge.to] = dist[v] + edge.cost;
                    que.emplace(dist[v] + edge.cost, edge.to);
                    path[edge.to] = v;
                }
            }
        }
        pair<vector<ll>, vector<ll>> retpair;
        retpair = make_pair(dist, path);
        return retpair;
    }
    vector<ll> getpath(const vector<ll>& rec, ll goal) {
        vector<ll> path;
        for (ll i = goal; i != -1; i = rec[i]) path.push_back(i);
        reverse(ALL(path));
        return path;
    }
    void gridgraph(const vector<vector<ll>>& field, graph& gr) {
        ll height = (ll)field.size();
        ll width = (ll)field[0].size();
        for (ll i = 0; i < height; ++i) {
            for (ll j = 0; j < width; ++j) {
                if (i - 1 >= 0) gr.add_edge(i * width + j, (i - 1) * width + j, field[i - 1][j]);
                if (i + 1 < height) gr.add_edge(i * width + j, (i + 1) * width + j, field[i + 1][j]);
                if (j - 1 >= 0) gr.add_edge(i * width + j, i * width + j - 1, field[i][j - 1]);
                if (j + 1 < width) gr.add_edge(i * width + j, i * width + j + 1, field[i][j + 1]);
            }
        }
    }
};
struct position {
    ll x;
    ll y;
};


void solve() {
    ll w, h;
    cin >> h >> w;
    grid<char> f(h, w);
    grid<ll> d(h, w);
    auto dist = d.field;
    rep(i, 0, h) rep(j, 0, w) dist[i][j] = INF;
    grid<bool> check(h, w);
    f.input();
    auto area = f.field;
    ll kabe = 0;
    vector<ll> dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
    graph g(w * h);
    queue<position> que;
    position ini;
    ini.x = 0; ini.y = 0;
    que.push(ini);
    dist[0][0] = 0;
    check.field[0][0] = true;
    while(!que.empty()) {
        position n = que.front(); que.pop();
        if (n.x == w - 1 && n.y == h - 1) break;
        rep(k, 0, 4) {
            ll nx = n.x + dx[k];
            ll ny = n.y + dy[k];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (area[ny][nx] == '.' && !check.field[ny][nx]) {
                dist[ny][nx] = dist[n.y][n.x] + 1;
                check.field[ny][nx] = true;
                position next;
                next.x = nx; next.y = ny;
                que.push(next);
            }
        }
    }
    if (dist[h - 1][w - 1] == INF) {
        cout << -1 << endl;
        return;
    }
    ll ans = h * w - dist[h - 1][w - 1] - 1;
    rep(i, 0, h) rep(j, 0, w) if (area[i][j] == '#') ans--;
    cout << ans << endl;
}   


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
