#include "bits/stdc++.h"
#include <chrono>
#include <fstream>
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

void solve() {
    ll N;
    //ifstream ifs("in.txt");
    cin >> N;
    vector<vector<ll>> cnt(N, vector<ll>(10, 0));
    string s; cin >> s;
    cnt[N - 1][s.back() - '0']++;
    rep(i, 1, N) {
        ll now = N - 1 - i;
        rep(j, 0, 10) cnt[now][j] = cnt[now + 1][j];
        cnt[now][s[now] - '0']++;
    }
    ll ans = 0;
    rep(x, 0, 10) rep(y, 0, 10) rep(z, 0, 10) {
        ll pos = -1;
        rep(i, 0, N) if (s[i] == x + '0') {
            pos = i;
            break;
        }
        if (pos == -1) continue;
        ll next = pos;
        rep(i, next + 1, N) if (s[i] == y + '0') {
            pos = i;
            break;
        }
        if (pos == next) continue;
        next = pos;
        rep(i, next + 1, N) if (s[i] == z + '0') {
            pos = i;
            break;
        }
        if (pos == next) continue;
        else ans++;
    }
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
