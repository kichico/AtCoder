#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

const ll MOD=1e9+7;
const ll INF=1e17;
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

void counter(ll& num,ll& increaser,bool checker){
    if(checker) num+=increaser;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}
//#########################################################################

void solve(){
    ll N;
    cin>>N;
    map<ll,ll> edge;
    rep(i,0,N){
        ll v; cin>>v;
        edge[v]++;
    }
    map<ll,ll> checker;
    vector<pair<ll,ll>> kouho;
    fore(x,edge){
        if(x.second>=2) kouho.emplace_back(make_pair(x.first,x.second));
    }
    sort(ALL(kouho));
    ll cnt=0;
    if(kouho.size()==0) {
        cout<<0<<endl;
        return;
    }
    else if(kouho.size()==1&&kouho.back().second<4){
        cout<<0<<endl;
        return;
    }
    if(kouho.back().second>=4){
        cout<<kouho.back().second*kouho.back().second<<endl;
        return;
    }
    set<ll> cand;
    rep(i,0,kouho.size()) if(kouho[i].second>=2) cand.emplace(kouho[i].first);
    if(cand.size()<=1) {cout<<0<<endl; return;}
    auto it=cand.rbegin();
    ll fr=*it;
    it--;
    cout<<fr*(*it)<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
