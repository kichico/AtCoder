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
void op(deque<ll> vec) {
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
void err() {
    cout << "ERROR" << endl;
}

void solve() {
    ll N; cin >> N;
    string s; cin >> s;
    deque<ll> deq;
    rep(i, 0, N) {
        auto c = s[i];
        if (c == 'A') {
            if (deq.size() < 1) err();
            else {
                cout << deq[0] << endl;
                deq.pop_front();
            }
        }
        if (c == 'B') {
            if (deq.size() < 2) err();
            else {
                cout << deq[1] << endl;
                vector<ll> res;
                rep(i, 0, 1) { res.emplace_back(deq.front()); deq.pop_front(); }
                deq.pop_front();
                while (!res.empty()) { deq.push_front(res.back()); res.pop_back(); }
            }
        }
        if (c == 'C') {
            ll n = 3;
            if (deq.size() < n) err();
            else {
                cout << deq[n - 1] << endl;
                vector<ll> res;
                rep(i, 0, n - 1) { res.emplace_back(deq.front()); deq.pop_front(); }
                deq.pop_front();
                while (!res.empty()) { deq.push_front(res.back()); res.pop_back(); }
            }
        }
        if (c == 'D') {
            if (deq.size() < 1) err();
            else {
                cout << deq.back() << endl;
                deq.pop_back();
            }
        }
        if (c == 'E') {
            ll n = 2;
            if (deq.size() < n) err();
            else {
                cout << deq[deq.size() - n] << endl;
                vector<ll> res;
                rep(i, 0, n - 1) { res.emplace_back(deq.back()); deq.pop_back(); }
                deq.pop_back();
                while (!res.empty()) { deq.push_back(res.back()); res.pop_back(); }
            }
        }
        if (c == 'F') {
            ll n = 3;
            if (deq.size() < n) err();
            else {
                cout << deq[deq.size() - n] << endl;
                vector<ll> res;
                rep(i, 0, n - 1) { res.emplace_back(deq.back()); deq.pop_back(); }
                deq.pop_back();
                while (!res.empty()) { deq.push_back(res.back()); res.pop_back(); }
            }
        }
        if (c == 'L') deq.push_front(i + 1);
        if (c == 'R') deq.push_back(i + 1);
        // if (!deq.empty()) { cout << "deq:"; op(deq); }
    }
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
