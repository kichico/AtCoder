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
    ll tax,N;
    cin>>tax>>N;
    vector<ll> value;
    ll previous_v=1;
    rep(i,1,1e8){
        ll kakaku=floor(((ld)100+(ld)tax)/100*i);
        if(kakaku>previous_v+1) {
            //cout<<"kakaku:"<<kakaku<<",previous:"<<previous_v<<endl;
            rep(j,previous_v+1,kakaku) value.emplace_back(j);
        }
        previous_v=kakaku;
        //cout<<i<<":"<<kakaku<<endl;
        if(value.size()>=100) break;
    }
    //cout<<value[N-1]<<endl;
    ll diff=value[1]-value[0];
    ll sum=value[0];
    rep(i,1,N) {
        sum+=diff;
        if(i%tax==0) sum++;
        //cout<<sum<<endl;
    }
    cout<<sum<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
