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
//#########################################################################

void solve(){
    ll N; cin>>N;
    deque<char> s(N); rep(i,0,N) cin>>s[i];
    while(true){
        ll check = 0;
        bool flg = true;
        ll minv = 0;
        rep(i,0,s.size()) {
            if(s[i]=='(') check++;
            else check--;
            if(check<0) flg = false;
            minv = min(check,minv);
        }
        if(flg && check == 0) break;
        else if(!flg && minv < 0) rep(i,0,abs(minv)) s.push_front('(');
        else rep(i,0,check)  s.push_back(')');
    } 
    string out; rep(i,0,s.size()) out.push_back(s[i]);
    cout<<out<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
