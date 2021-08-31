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

void solve() {
    string X, Y; cin >> X >> Y;
    vector<vector<ll>> score(5, vector<ll>(5, 0));
    rep(i, 0, 5) rep(j, 0, 5) {
        if (i < 4 && j < 4) {
            if (i == j) score[i][j] = 1;
            else score[i][j] = -3;
        }
        else score[i][j] = -5;
    }
    vector<vector<pair<int, int>>> dp(X.size() + 1, vector<pair<int, int>>(Y.size() + 1));
    for (int i = 0; i <= X.size(); ++i) {
        dp[i][0].first = i * (-3);
        if (i > 0) dp[i][0].second = (i - 1) * Y.size();
    }
    for (int j = 0; j <= Y.size(); ++j) {
        dp[0][j].first = j * (-3);
        if (j > 0) dp[0][j].second = j - 1;
    }
    string Xn, Yn;
    rep(i, 0, X.size()) {
        if (X[i] == 'A') Xn.push_back(0 + '0');
        else if (X[i] == 'T') Xn.push_back(1 + '0');
        else if (X[i] == 'G') Xn.push_back(2 + '0');
        else Xn.push_back(3 + '0');
    }
    rep(i, 0, Y.size()) {
        if (Y[i] == 'A') Yn.push_back(0 + '0');
        else if (Y[i] == 'T') Yn.push_back(1 + '0');
        else if (Y[i] == 'G') Yn.push_back(2 + '0');
        else Yn.push_back(3 + '0');
    }
    //string sx, sy;
    rep(i, 1, X.size() + 1) rep(j, 1, Y.size() + 1) {
        ll fr = Xn[i - 1] - '0'; ll se = Yn[j - 1] - '0';
        ll U = dp[i - 1][j].first + score[fr][4];
        ll L = dp[i][j - 1].first + score[4][se];
        ll LU = dp[i - 1][j - 1].first + score[fr][se];
        dp[i][j].first = max(U, max(L, LU));
        if (dp[i][j].first == U) dp[i][j].second = (i - 1) * Y.size() + j;
        else if (dp[i][j].first == L) dp[i][j].second = i * Y.size() + (j - 1);
        else dp[i][j].second = (i - 1) * Y.size() + (j - 1);
    }
    for (int i = X.size(); i >= 0; --i) {
        for (int j = Y.size(); j >= 0; --j) {

        }
    }
    /*
    cout << "-----------------" << endl;
    cout << "    ";
    for (int i = 0; i < Y.size(); ++i) cout << Y[i] << " ";
    cout << endl;
    for (int i = 0; i <= X.size(); ++i) {
        if (i > 0) {
            cout << X[i - 1] << ":";
            for (int j = 0; j <= Y.size(); ++j) cout << dp[i][j] << " ";
            cout << endl;
        }
        else {
            cout << "  ";
            for (int j = 0; j <= Y.size(); ++j) cout << dp[i][j] << " ";
            cout << endl;
        }
    }
    */
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
