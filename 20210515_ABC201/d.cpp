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

bool compare(pair<ull,pair<ull,ull>> lpr,pair<ull,pair<ull,ull>> spr){
    ull lsum=lpr.first+lpr.second.first+lpr.second.second;
    ull ssum=spr.first+spr.second.first+spr.second.second;
    if(lsum!=ssum) return lsum<ssum;
    else {
        if(lpr.first!=spr.first) return lpr.first<spr.first;
        else if(lpr.second.first!=spr.second.first) return lpr.second.first < spr.second.first;
        else return lpr.second.second<spr.second.second;
    }
}



int solve(){
    ull N,K;
    cin>>N>>K;
    vector<pair<ull,pair<ull,ull>>> cake;
    for(ull i=1;i<=N;++i) for(ull j=1;j<=N;++j)  for(ull k=1;k<=N;++k) {
        auto pr=make_pair(i,make_pair(j,k));
        cake.push_back(pr);
        //cout<<cake.size()<<":"<<pr.first<<" "<<pr.second.first<<" "<<pr.second.second<<endl;
    }
    sort(ALL(cake),compare);
    cout<<cake[K-1].first<<" "<<cake[K-1].second.first<<" "<<cake[K-1].second.second<<endl;
    //rep(i,0,cake.size()) cout<<i<<":"<<cake[i].first<<" "<<cake[i].second.first<<" "<<cake[i].second.second<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
