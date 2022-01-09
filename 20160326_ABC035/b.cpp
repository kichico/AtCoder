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
const ll INF = 1e10;
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
struct position {
    ll x;
    ll y;
    ll abso;
    position operator+(const position& other) {
        this->x += other.x;
        this->y += other.y;
        this->abso = abs(this->x) + abs(this->y);
        return *this;
    }
    position posin() {
        ll x, y; cin >> x >> y; x--; y--;
        this->x = x; this->y = y;
        return *this;
    }
};

position compL(const position& fr, const position& se) {
    if (fr.abso < se.abso) return se;
    else return fr;
}

position compS(const position& fr, const position& se) {
    if (fr.abso > se.abso) return se;
    else return fr;
}

void solve() {
    string s; cin >> s;
    ll T; cin >> T;
    ll N = s.size();
    vector<vector<position>> dp(N + 1, vector<position>(4));
    rep(i, 0, 4) {
        dp[0][i].x = 0;
        dp[0][i].y = 0;
        if (T == 1) dp[0][i].abso = 0;
        else dp[0][i].abso = INF;
    }
    map<char, position> dir;
    position u, r, l, d;
    u.x = 0, u.y = 1; r.x = 1, r.y = 0; l.x = -1, l.y = 0; d.x = 0, d.y = -1;
    dir['U'] = u, dir['R'] = r, dir['L'] = l, dir['D'] = d;
    vector<char> dd{ 'U','R','L','D' };
    rep(i, 0, N) {
        if (s[i] == '?') {
            rep(j, 0, 4) dp[i + 1][j] = dp[i][j];
            rep(j, 0, 4) rep(k, 0, 4) {
                position pp;
                pp.x = dp[i][j].x + dir[dd[k]].x;
                pp.y = dp[i][j].y + dir[dd[k]].y;
                pp.abso = abs(pp.x) + abs(pp.y);
                if (T == 1) dp[i + 1][j] = compL(dp[i + 1][j], pp);
                else dp[i + 1][j] = compS(dp[i + 1][j], pp);
            }
        }
        else {
            rep(j, 0, 4) {
                dp[i + 1][j] = dp[i][j] + dir[s[i]];
                dp[i + 1][j].abso = abs(dp[i + 1][j].x) + abs(dp[i + 1][j].y);
            }
        }
    }
    position ans = dp[N][0];
    rep(i, 1, 4) {
        if (T == 1)ans = compL(ans, dp[N][i]);
        else ans = compS(ans, dp[N][i]);
    }
    cout << ans.abso << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
