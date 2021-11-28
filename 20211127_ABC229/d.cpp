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

void solve() {
    string s; cin >> s;
    ll K; cin >> K;
    ll N = s.size();
    char prev = s[0];
    vector<pair<ll, ll>> dot;
    ll cnt = 1;
    pair<ll, ll> pos;
    pos.first = 0; pos.second = 0;
    rep(i, 0, N) {
        if (s[i] != '.') {
            if (pos.second - pos.first >= 1) dot.emplace_back(pos);
            pos.first = i + 1;
            pos.second = i + 1;
        }
        else pos.second = i + 1;
    }
    if (pos.second - pos.first > 0) dot.emplace_back(pos);
    sort(ALL(dot), [](const pair<ll, ll>& fr, const pair<ll, ll>& se) { return fr.second - fr.first > se.second - se.first; });
    ll L = 0;
    while (K != 0) {
        ll left, right; tie(left, right) = dot.back();
        dot.pop_back();
        if (K - (right - left) >= 0) {
            rep(i, left, right) s[i] = 'X';
            K -= (right - left);
        }
        else {
            auto fr = s, se = s;
            rep(i, 0, K) {
                fr[left + i] = 'X';
                se[right - i - 1] = 'X';
            }
            ll length = 0;
            ll pos = 0;
            while (fr[pos] != 'X') pos++;
            rep(i, pos, N) {
                if (fr[i] != 'X') {
                    L = max(L, length);
                    length = 0;
                }
                else length++;
            }
            pos = 0;
            while (se[pos] != 'X') pos++;
            rep(i, pos, N) {
                if (se[i] != 'X') {
                    L = max(L, length);
                    length = 0;
                }
                else length++;
            }
            K = 0;
        }
    }
    cout << L << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
