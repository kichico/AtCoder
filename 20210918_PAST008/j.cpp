#include "bits/stdc++.h"
using namespace std;
using ll = int64_t;
using ld = long double;
using ull = unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
#define mp(a,b) make_pair(a,b)
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

template<class T>
inline bool isExist(set<T> st, T key) {
    if (st.find(key) == st.end()) return false;
    else return true;
}

template<class T, class U>
inline bool isExist(map<T, U> st, T key) {
    if (st.find(key) == st.end()) return false;
    else return true;
}
//#########################################################################

void solve() {
    ll N; cin >> N;
    vector<ll> a(2 * N); iota(ALL(a), 0);
    ll Q; cin >> Q;
    vector<ll> ref(2 * N); iota(ALL(ref), 1);
    rep(i, 0, Q) {
        ll t, k; cin >> t >> k;
        if (t == 1) cout << ref[k - 1] << endl;
        else {
            rep(j, 0, k) {
                ll pos = a[N - j - 1];
                a[N - j - 1] = a[N + j];
                a[N + j] = pos;
                swap(ref[a[N - j - 1]], ref[a[N + j]]);
            }
        }
    }
    //op(ref);
}


int main(void) {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
