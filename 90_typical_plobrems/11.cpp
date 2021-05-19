#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)
constexpr ll MOD=1e9+7;
constexpr ll INF=1e16;
template<class T>
using grid=vector<vector<T>>;
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

bool compare(pair<ll,pair<ll,ll>> left, pair<ll,pair<ll,ll>> right){
    if(left.first!=right.first) return left.first<right.first;
    else if(left.second.first!=right.second.first) return left.second.first<right.second.first;
    else return left.second.second>right.second.second;
}


void solve(){
    ll N;
    cin>>N;
    vector<pair<ll,pair<ll,ll>>> w(N,make_pair(0,make_pair(0,0)));
    rep(i,N) cin>>w[i].first>>w[i].second.first>>w[i].second.second;
    sort(ALL(w),compare);
    ll sum=0;
    ll now=0;
    for(ll tmp=0;tmp<(1<<20);++tmp){
        bitset<20> s(tmp);
        ll thissum=0;
        ll thisnow=0;
        rep(i,w.size()) if(s.test(i)&&thisnow+w[i].second.first<=w[i].first) {
            thisnow+=w[i].second.first;
            thissum+=w[i].second.second;
        }
        //cout<<"sum:"<<thissum<<endl;
        sum=max(sum,thissum);
    }
    cout<<sum<<endl;
    //cout<<endl;
    //for(auto x:w) cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
