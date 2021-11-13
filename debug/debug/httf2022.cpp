#include "bits/stdc++.h"
#include <fstream>

using namespace std;
using ld = long double;
using ull = unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(int iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const vector<int> dx{ 1,0,-1,0 }, dy{ 0,1,0,-1 };
//#######################################################################
void op(vector<int> vec) {
    int size = (int)vec.size();
    for (int i = 0; i < size - 1; ++i) cout << vec[i] << " ";
    cout << vec.back() << endl;
}

void op(vector<vector<int>> vec) {
    int height = (int)vec.size();
    int width = (int)vec[0].size();
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width - 1; ++j) cout << vec[i][j] << " ";
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

template<class T, int>
T vecsum(vector<T>& vec, int K) {
    int ret = 0;
    rep(i, 0, K) ret += vec[i];
    return ret;
}

template <class T>
struct grid {
    vector<vector<T>> field;
    grid(int height, int width) { field = vector<vector<T>>(height, vector<T>(width, (T)0)); }
    void input() { rep(i, 0, field.size()) rep(j, 0, field[i].size()) cin >> field[i][j]; }
};

//#########################################################################
struct Worker {
    int ID;
    int jobID;
    int time;
    bool operator<(const Worker& other) { return this->ID < other.ID; }
};




class tsort {
public:
    int V;
    vector<vector<int> > G;
    vector<int> deg, res;
    tsort(int node_size) : V(node_size), G(V), deg(V, 0) {}
    void add_edge(int from, int to) {
        G[from].push_back(to);
        deg[to]++;
    }
    bool solve() {
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < V; i++) {
            if (deg[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int p = que.top(); que.pop();
            res.push_back(p);
            for (int v : G[p]) {
                if (--deg[v] == 0) {
                    que.push(v);
                }
            }
        }
        return (*max_element(deg.begin(), deg.end()) == 0);
    }
};

unordered_set<int> completed;
string filename = "output.dat";
ofstream ofs(filename);
map<ll, ll> person;


void solve() {
    cin >> N >> M >> k >> relation;
    grid<int> t(N, k); t.input();
    
    return;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
    cout << nn << endl;
}

