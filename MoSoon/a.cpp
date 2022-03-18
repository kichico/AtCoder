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
vector<pair<ll, ll>> prime_factorize(ll Num) {
    ll lim = sqrt(Num) + 1;
    vector<pair<ll, ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(lim);
    for (ll i = 0; i < lim; ++i) listprime[i] = true;
    ll root = sqrt(Num);
    ll res = Num;
    for (ll i = 2; i <= root; ++i) {
        ll expnum = 0;
        if (listprime[i]) {
            while (res % i == 0) {
                res /= i;
                expnum++;
            }
            for (ll j = i * 2; j <= root; j += i) listprime[j] = false;
        }
        if (expnum != 0) pr.emplace_back(make_pair(i, expnum));
    }
    if (res != 1) pr.emplace_back(make_pair(res, 1));
    return pr;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    ll av = a - b;
    cout << max(0, a - b - c) << endl;

}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
