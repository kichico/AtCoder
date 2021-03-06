#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
#define ALL(x) x.begin(),x.end()
const ll MOD=1e9+7;
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


int solve(){
    ll T;
    cin>>T;
    vector<ll> ans(T);
    for(ll i=0;i<T;++i){
        ll l,r;
        cin>>l>>r;
        ll n=r-2*l+1;
        //cout<<l<<"th n=>"<<n<<endl;
        if(n<0) ans[i]=0;
        else ans[i]=(n*(n+1))/2;
    }
    for(auto x:ans) cout<<x<<endl;
    return 0;
}



int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}