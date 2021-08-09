#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

const ll MOD=1e9+7;
const ll INF=1e17;
//#######################################################################
vector<vector<ll>> input(ll N, ll width){
    string str;
    vector<vector<ll>> vec(N,vector<ll>(width));
    for(ll i=0;i<N;++i){
        cin>>str;
        reverse(ALL(str));
        for(ll j=0;j<width;++j){
            vec[i][j]=str.back();
            str.pop_back();
        }
    }
    return vec;
}
void op(vector<ll> vec){
    ll size=(ll)vec.size();
    for(ll i=0;i<size-1;++i) cout<<vec[i]<<" ";
    cout<<vec.back()<<endl;
}

void op(vector<vector<ll>> vec){
    ll height=(ll)vec.size();
    ll width=(ll)vec[0].size();
    for(ll i=0;i<height;++i) {
        for(ll j=0;j<width-1;++j) cout<<vec[i][j]<<" ";
        cout<<vec[i].back()<<endl;
    }
}
//########################################################################





void solve(){
    ll N, K;
    cin >> N >> K;
    vector<ll> score(3);
    rep(i, 0, 3) cin >> score[i];
    string s;
    cin >> s;
    ll ans = 0;
    string dashita;
    rep(i, 0, K) {
        if (s[i] == 'r') {
            ans += score[2];
            dashita.push_back('p');
        }
        else if (s[i] == 's') {
            ans += score[0];
            dashita.push_back('r');
        }
        else {
            ans += score[1];
            dashita.push_back('s');
        }
    }
    rep(i, K, N) {
        if (s[i] == 'r') {
            if (s[i] == s[i - K] && dashita[i - K] == 'p') {
                dashita.push_back(s[i]);
                continue;
            }
            ans += score[2];
            dashita.push_back('p');
        }
        else if (s[i] == 's') {
            if (s[i] == s[i - K] && dashita[i - K] == 'r') {
                dashita.push_back(s[i]);
                continue;
            }
            ans += score[0];
            dashita.push_back('r');
        }
        else {
            if (s[i] == s[i - K] && dashita[i - K] == 's') {
                dashita.push_back(s[i]);
                continue;
            }
            ans += score[1];
            dashita.push_back('s');
        }
    }
    cout << ans << endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
