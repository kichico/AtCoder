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
vector<set<ll>> color;
vector<vector<ll>> tree;
map<pair<ll, ll>, ll> c;
ll K;
void bfs(ll now, vector<bool>& visited) {
    visited[now] = true;
    queue<ll> que;
    que.push(now);
    K = 0;
    while (!que.empty()) {
        ll n = que.front(); que.pop();
        ll colornum = 1;
        for (auto next : tree[n]) {
            if (!visited[next]) {
                que.push(next);
                while (color[n].count(colornum) != 0) colornum++;
                color[next].emplace(colornum);
                color[n].emplace(colornum);
                c[make_pair(n, next)] = colornum;
                visited[next] = true;
                colornum++;
            }
        }
        K = max((ll)color[n].size(), K);
    }
}



void solve() {
    ll N;
    cin >> N;
    tree = vector<vector<ll>>(N);
    color = vector<set<ll>>(N);
    vector<pair<ll, ll>> con(N - 1);
    rep(i, 0, N - 1) {
        ll from, to; cin >> from >> to; from--; to--;
        tree[from].emplace_back(to);
        tree[to].emplace_back(from);
        con[i]=(make_pair(from,to));
    }
    vector<bool> visited(N, false);
    bfs(0, visited);
    cout << K << endl;
    rep(i, 0, N - 1) cout << c[con[i]] << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
