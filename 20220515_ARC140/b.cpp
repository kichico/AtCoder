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

void solve() {
    ll N; cin >> N;
    string s; cin >> s;
    vector<ll> odd, even;
    rep(i, 0, N - 2) {
        auto ss = s.substr(i, 3);
        if (ss != "ARC") continue;
        if (i == 0 || i == N - 3) { even.emplace_back(i); continue; }
        if (s[i - 1] == 'A' && s[i + 3] == 'C') { odd.emplace_back(i); }
        else even.emplace_back(i);
    }
    set<pair<ll, ll>> group;
    rep(i, 0, odd.size()) {
        ll left = odd[i] - 1;
        ll right = odd[i] + 3;
        ll cnt = 1;
        while (left >= 0 && right < N && s[left] == 'A' && s[right] == 'C') {
            left--;
            right++;
            cnt++;
        }
        group.emplace(cnt, odd[i]);
    }
    ll rest = even.size();
    ll ans = 0;
    if (group.empty()) { cout << even.size() << endl; return; }
    if (even.empty()) {
        while (!group.empty()) {
            auto pr = *group.rbegin();
            ans++;
            group.erase(pr);
            pr.first -= 1;
            if (pr.first != 0) group.emplace(pr);
            if (group.empty()) break;
            ans++;
            auto it = group.begin();
            group.erase(it);
        }
    }
    rep(i, 0, rest) {
        auto pr = *group.rbegin();
        ans++;
        group.erase(pr);
        pr.first -= 1;
        if (pr.first != 0) group.emplace(pr);
        if (group.empty()) break;
    }
    while (!group.empty()) {
        auto pr = *group.rbegin();
        ans++;
        group.erase(pr);
        pr.first -= 1;
        if (pr.first != 0) group.emplace(pr);
        if (group.empty()) break;
        ans++;
        auto it = group.begin();
        group.erase(it);
    }
    cout << ans + rest << endl;
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
