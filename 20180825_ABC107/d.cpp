#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const ll MOD=1e9+7;
const ll INF=1e17;
const vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
//#######################################################################
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

void twoText(bool identifier, string outTrue, string outFalse) {
    if (identifier) cout << outTrue << endl;
    else cout << outFalse << endl;
}

void twoText(bool identifier){
    if(identifier) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

template<class T,ll>
T vecsum(vector<T>& vec, ll K){
    ll ret = 0;
    rep(i,0,K) ret+=vec[i];
    return ret;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

//#########################################################################

void solve(){
    ll N,K; cin>>N>>K;
    vector<ll> a(N); rep(i,0,N) cin>>a[i];
    sort(ALL(a));
    ll dist = 0;
    ll left = 0, right = K - 1;
    if(N == 1) {
        cout << abs(a[0]-0) << endl;
        return;
    }
    rep(i,0,K-1) dist += abs(a[i+1]-a[i]);
    if(a[right] < 0) dist += abs(a[right] - 0);
    else if(a[left] > 0) dist += abs(a[left] - 0);
    else dist += min(abs(a[left]),abs(a[right]));
    ll ans = dist;
    while(right + 1 < N){
        ll cur = dist;
        cur -= abs(a[left+1] - a[left]);
        cur += abs(a[right+1] - a[right]);
        cur -= min(abs(a[left]),abs(a[right]));;
        cur += min(abs(a[left + 1]),abs(a[right + 1]));
        ans = min(ans,cur);
        dist = cur;
        right++;
        left++;
    }
    cout << ans << endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
