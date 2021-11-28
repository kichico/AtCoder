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
        member = vector<set<ll>>(size);
        rep(i, 0, size) {
            roots.emplace(i);
            member[i].emplace(i);
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
        for (auto i : member[y]) member[x].emplace(i);
        member[y].clear();
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

struct position{
    ll x; ll y;
};
struct route {
    position shop, house;
    ll ID;
};

void solve() {
    ll N = 1000;
    vector<route> R(N);
    rep(i, 0, N) {
        route r;
        cin >> r.shop.x >> r.shop.y >> r.house.x >> r.house.y;
        r.ID = i;
        R[i] = r;
    }
    set<ll> picked; rep(i, 0, N) picked.emplace(i);
    vector<pair<ll, ll>> dist(N);
    vector<ll> ans;
    vector<position> way;
    position office;
    office.x = 400; office.y = 400;
    way.emplace_back(office);
    vector<route> chosen;
    sort(ALL(R), [](const route& fr, const route& se) {
        return abs(fr.shop.x - 400) + abs(fr.shop.y - 400) + abs(fr.house.x - 400) + abs(fr.house.y - 400) < abs(se.shop.x - 400) + abs(se.shop.y - 400) + abs(se.house.x - 400) + abs(se.house.y - 400);
    });
    rep(i, 0, 50) {
        chosen.emplace_back(R[i]);
        ans.emplace_back(R[i].ID);
    }
    map<ll, bool> visited;
    rep(i, 0, 50) visited[chosen[i].ID] = false;
    position now;
    now.x = 400; now.y = 400;
    rep(i, 0, 50){
        sort(ALL(chosen), [now](const route& fr, const route& se) {
            return abs(fr.shop.x - now.x) + abs(fr.shop.y - now.y) < abs(se.shop.x - now.x) + abs(se.shop.y - now.y);
        });
        rep(j, 0, 50) if (!visited[chosen[j].ID]) {
            way.emplace_back(chosen[j].shop);
            visited[chosen[j].ID] = true;
            now = chosen[j].shop;
            break;
        }
    }
    rep(i, 0, 50) visited[chosen[i].ID] = false;
    rep(i, 0, 50) {
        sort(ALL(chosen), [now](const route& fr, const route& se) {
            return abs(fr.house.x - now.x) + abs(fr.house.y - now.y) < abs(se.house.x - now.x) + abs(se.house.y - now.y);
            });
        rep(j, 0, 50) if (!visited[chosen[j].ID]) {
            way.emplace_back(chosen[j].house);
            visited[chosen[j].ID] = true;
            now = chosen[j].house;
            break;
        }
    }
    way.emplace_back(office);
    cout << ans.size() << " ";
    rep(i, 0, ans.size()) cout << ans[i] + 1 << " ";
    cout << endl << way.size() << " ";
    rep(i, 0, way.size()) cout << way[i].x << " " << way[i].y << " ";
    cout << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
