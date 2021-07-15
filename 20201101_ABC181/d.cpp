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
    string s;
    cin>>s;
    set<ll> num;
    rep(i,0,s.size()) num.insert(s[i]-'0');
    vector<ll> all{num.begin(),num.end()};
    if(s.size()>=3){
        vector<ll> check(10,0);
        rep(i,0,s.size()) check[s[i]-'0']++;
        for(int i=104;i<=1000;i+=8) {
            bool flg=true;
            vector<ll> cnt(10,0);
            string c=to_string(i);
            rep(k,0,c.size()) cnt[c[k]-'0']++;
            rep(k,0,10) if(check[k]<cnt[k]) flg=false;
            if(flg) {cout<<"Yes"<<endl;return;}
        }
    }
    else if(s.size()==2) {
        rep(i,0,2){
            if(stoi(s)%8==0) {cout<<"Yes"<<endl;return;}
            swap(s[0],s[1]);
        }
    }
    else if(s.size()==1) if((s[0]-'0')%8==0) {cout<<"Yes"<<endl;return;}
    cout<<"No"<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
