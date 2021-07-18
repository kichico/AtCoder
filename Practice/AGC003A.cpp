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

struct hougaku{
    ll N=0;
    ll S=0;
    ll W=0;
    ll E=0;
};



void solve(){
    string s;
    cin>>s;
    hougaku in;
    rep(i,0,s.size()){
        if(s[i]=='S') in.S++;
        else if(s[i]=='W') in.W++;
        else if(s[i]=='E') in.E++;
        else in.N++;
    }
    pair<ll,ll> check=make_pair(min(in.S,in.N),max(in.S,in.N));
    bool flgv=false,flgh=false;
    if((check.first==0&&check.second==0)||(check.first!=0&&check.second!=0)) flgv=true;
    check=make_pair(min(in.E,in.W),max(in.E,in.W));
    if((check.first==0&&check.second==0)||(check.first!=0&&check.second!=0)) flgh=true;
    if(flgv&&flgh) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
