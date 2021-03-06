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
    if (vec.empty()) {
        cout << endl;
        return;
    }
    for (ll i = 0; i < size - 1; ++i) cout << vec[i] << " ";
    cout << vec.back() << endl;
}

void op(vector<vector<ll>> vec) {
    ll height = (ll)vec.size();
    ll width = (ll)vec[0].size();
    if (vec.empty()) {
        cout << endl;
        return;
    }
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
bool isPrime(ll Num) {
    ll root = sqrt(Num);
    if (Num == 0 || Num == 1) return false;
    for (ll i = 2; i <= root; ++i) if (Num % i == 0) return false;
    return true;
}

vector<ll> enumeratePrime(ll maxx) {
    vector<bool> notp(maxx + 1, false);
    vector<ll> ret;
    rep(i, 2, maxx + 1) {
        if (notp[i]) continue;
        if (isPrime(i)) ret.emplace_back(i);
        ll init = 1;
        while (init * i <= maxx) {
            notp[init * i] = true;
            init++;
        }
    }
    return ret;
}

void solve() {
    ll N, K; cin >> N >> K;
    string s; cin >> s;
    ll maxx = 0;
    ll ans = N;
    map<char, ll> cnt;
    rep(i, 0, N) cnt[s[i]]++;
    pair<char, ll> mp;
    fore(x, cnt) if (maxx < x.second) {
        mp = x;
        maxx = x.second;
    }
    if (cnt.size() == 1) {
        cout << 1 << endl; return;
    }
    else if (N - maxx <= K) {
        cout << 1 << endl; return;
    }
    else if (N != 2 && isPrime(N) && N - maxx > K) {
        cout << N << endl; return;
    }
    s += s;
    ll upper = sqrt(N) + 1;
    auto yakusu = enumeratePrime(upper);
    fore(i, yakusu) {
        unordered_map<string, ll> each;
        rep(j, 0, N - i) each[s.substr(j, i)]++;
        pair<string, ll> pr;
        maxx = 0;
        map<ll, vector<string>> longest;
        fore(x, each) longest[x.second].emplace_back(x.first);
        auto it = longest.rbegin();
        ll m = N;
        auto& v = *it;
        fore(ss, v.second) {
            ll diff = N;
            rep(offset, 0, i) {
                ll _diff = 0;
                for (ll j = 0; j < N - i + 1; j += i) {
                    auto sub = s.substr(j + offset, i);
                    rep(k, 0, i) if (ss[k] != sub[k]) _diff++;
                }
                diff = min(diff, _diff);
            }
            m = min(diff, m);
        }
        if (m <= K) ans = min(i, ans);
    }
    cout << ans << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
