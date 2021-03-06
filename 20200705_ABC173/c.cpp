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
    ll h,w,k;
    cin>>h>>w>>k;
    grid<char> field(h,vector<char>(w,'.'));
    rep(i,0,h) {
        string s;
        cin>>s;
        rep(j,0,w) field[i][j]=s[j];
    }
    set<string> checker;
    ll ans=0;
    for(int tmph=0;tmph<(1<<7);++tmph){
        bitset<6> hori(tmph);
        for(int tmpw=0;tmpw<(1<<7);++tmpw) {
            auto nowfield=field;
            bitset<6> ver(tmpw);
            //cout<<"hori:"<<hori<<endl;
            //cout<<"ver:"<<ver<<endl;
            for(int i=0;i<h;++i) if(ver.test(i)) rep(k,0,w) nowfield[i][k]='R';
            for(int i=0;i<w;++i) if(hori.test(i)) rep(k,0,h) nowfield[k][i]='R';
            ll cnt=0;
            string str;
            rep(i,0,h) rep(j,0,w) str+=nowfield[i][j];
            if(checker.count(str)==0) {
                rep(i,0,str.size()) if(str[i]=='#') cnt++;
                checker.insert(str);
            }
            if(cnt==k) ans++;
        }
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
