#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
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

struct Edge {
    ll to, cost;
    Edge() {}
    Edge(ll to, ll cost = 0) : to(to), cost(cost) {}
};

typedef pair<ll,ll> P;
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

struct position{
    ll x;
    ll y;
};


int solve(){
    graph g(30 * 30);
    grid<ll> field(30, vector<ll>(30, 10000));
    g.gridgraph(field,g);
    //grid<ll> h(30, vector<ll>(30, 0));
    //grid<ll> v(30, vector<ll>(30, 0));
    //vector<string> res;
    //rep(i, 0, 30) rep(j, 0, 29) cin >> h.at(i).at(j);
    //rep(i, 0, 29) rep(j, 0, 30) cin >> v.at(i).at(j);
    rep(i, 0, 1000) {
        //cout << "--------------------" << i << "-------------------" << endl;
        string str;
        ll dist = 0;
        position start, goal;
        ll a;
        ld e;
        cin >> start.y >> start.x >> goal.y >> goal.x;// >> a >> e;
        position distance;
        //cout<<i<<":"<<endl;
        auto pr = g.dijkstra(start.y * 30 + start.x);
        //cout<<"dijkstra is finished"<<endl;
        vector<ll> path = g.getpath(pr.second, goal.y * 30 + goal.x);
        vector<position> way(path.size());
        rep(p, 0, path.size()) {
            way[p].x = path[p] % 30;
            way[p].y = path[p] / 30;
        }
        rep(p, 1, path.size()) {
            distance.x = way[p].x - way[p - 1].x;
            distance.y = way[p].y - way[p - 1].y;
            if (distance.x > 0) rep(j, 0, distance.x) str.push_back('R');
            else rep(j, 0, abs(distance.x)) str.push_back('L');
            if (distance.y > 0) rep(j, 0, distance.y) str.push_back('D');
            else rep(j, 0, abs(distance.y)) str.push_back('U');
        }
        /*
        else {
            distance.x = goal.x - start.x;
            distance.y = goal.y - start.y;
            //cout<<i<<":"<<distance.x<<","<<distance.y<<endl;
            if (distance.x > 0) rep(j, 0, distance.x) str.push_back('R');
            else rep(j, 0, abs(distance.x)) str.push_back('L');
            if (distance.y > 0) rep(j, 0, distance.y) str.push_back('D');
            else rep(j, 0, abs(distance.y)) str.push_back('U');
        }
        */
        cout << str << endl;
        cout<<flush;
        position here = start;
        /*
        rep(j, 0, str.size()) {
            if (str[j] == 'U') {
                dist += v[here.y - 1][here.x];
                here.y--;
            }
            else if (str[j] == 'D') {
                dist += v[here.y][here.x];
                here.y++;
            }
            else if (str[j] == 'R') {
                dist += h[here.y][here.x];
                here.x++;
            }
            else {
                dist += h[here.y][here.x - 1];
                here.x--;
            }
        }
        res.push_back(str);
        */
        cin >> dist;
        ll ave_dist = round((double)dist / (ll)str.size());
        /*
        rep(x, min(start.x, goal.x), max(start.x, goal.x)) {
            rep(y, min(start.y, goal.y), max(start.y, goal.y)) {
                rep(d, 0, g.G[y * 30 + x].size()) {
                    if (g.G[y * 30 + x][d].to == (y + 1) * 30 + x) g.G[y * 30 + x][d].cost = min(g.G[y * 30 + x][d].cost, ave_dist);
                    if (g.G[y * 30 + x][d].to == (y - 1) * 30 + x) g.G[y * 30 + x][d].cost = min(g.G[y * 30 + x][d].cost, ave_dist);
                    if (g.G[y * 30 + x][d].to == y * 30 + x + 1) g.G[y * 30 + x][d].cost = min(g.G[y * 30 + x][d].cost, ave_dist);
                    if (g.G[y * 30 + x][d].to == y * 30 + x - 1) g.G[y * 30 + x][d].cost = min(g.G[y * 30 + x][d].cost, ave_dist);
                }
            }
        }
        */
        rep(s, 0, str.size()) {
            if (str[s] == 'U') {
                rep(d, 0, g.G[here.y * 30 + here.x].size()) {
                    if (g.G[here.y * 30 + here.x][d].to == (here.y + 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == (here.y - 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x + 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x - 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                }
                here.y--;
            }
            else if (str[s] == 'D') {
                rep(d, 0, g.G[here.y * 30 + here.x].size()) {
                    if (g.G[here.y * 30 + here.x][d].to == (here.y + 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == (here.y - 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x + 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x - 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                }
                here.y++;
            }
            else if (str[s] == 'R') {
                rep(d, 0, g.G[here.y * 30 + here.x].size()) {
                    if (g.G[here.y * 30 + here.x][d].to == (here.y + 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == (here.y - 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x + 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x - 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                }
                here.x++;
            }
            else {
                rep(d, 0, g.G[here.y * 30 + here.x].size()) {
                    if (g.G[here.y * 30 + here.x][d].to == (here.y + 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == (here.y - 1) * 30 + here.x) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x + 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                    if (g.G[here.y * 30 + here.x][d].to == here.y * 30 + here.x - 1) g.G[here.y * 30 + here.x][d].cost = min(g.G[here.y * 30 + here.x][d].cost, ave_dist);
                }
                here.x--;
            }
        }

    }
    //rep(i,0,res.size()) cout<<res[i]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
