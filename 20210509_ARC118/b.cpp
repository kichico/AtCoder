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





int solve(){
    ull in;
    ll k;
    cin>>in>>k;
    rep(i,0,k){
        /*ll hn=in.size()-3;
        ll tn=hn+1;
        ll on=hn+2;
        if(in.size()<3) in+="200";
        else if((in[hn]-'0')%2==0&&in[tn]=='0'&&in[on]=='0') {
            in.pop_back();
            in.pop_back();
            in.back()=(in.back()-'0')/2;
        }
        else in+="200";
        */
        if(in%200==0) in/=200;
        else {
            string str=to_string(in);
            str+="200";
            in=stoull(str);
        }
        //cout<<i<<":"<<in<<endl;
    }
    cout<<in<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
