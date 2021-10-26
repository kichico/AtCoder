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

template<class T,class U>
struct dict{
    map<T,U> data;
    inline bool isExist(T key){
        if(data.find(key) == data.end()) return false;
        else return true;
    }
    inline void emplace(T key, U value){ data[key] = value; }
};

template<class T>
inline bool isExist(set<T> st, T key){
    if(st.find(key) == st.end()) return false;
    else return true;
}
//#########################################################################

void solve(){
    ll N; cin>>N;
    vector<ll> jpy,btc;
    rep(i,0,N){
        string s,m; cin>>m>>s;
        if(s=="JPY") jpy.emplace_back(stoll(m));
        else{
            ld con = stold(m);
            con*=1e11;
            btc.emplace_back((ll)con);
        }
    }
    cout<<vecsum(jpy)+(ld)vecsum(btc)*1e-11*380000<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
