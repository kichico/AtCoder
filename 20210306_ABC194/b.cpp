#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
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
    ll N;
    cin>>N;
    vector<ll> a(N),b(N);
    pair<ll,ll> amin,bmin,a_bmin,b_amin;
    ll summin=1e9;
    amin=bmin=a_bmin=b_amin=make_pair(1e9,-1);
    for(ll i=0;i<N;++i) {
        cin>>a[i]>>b[i];
        if(a[i]+b[i]<summin) summin=a[i]+b[i];
    }
    for(ll i=0;i<N;++i) {
        if(a[i]<amin.first) {
            amin.first=a[i];
            amin.second=i;
        }
        if(b[i]<bmin.first) {
            bmin.first=b[i];
            bmin.second=i;
        }
    }
    if(bmin.second==amin.second){
        vector<ll> tempa,tempb;
        tempa=a,tempb=b;
        tempa.erase(tempa.begin()+amin.second);
        tempb.erase(tempb.begin()+bmin.second);
        for(ll i=0;i<N-1;++i) {
            if(tempb[i]<a_bmin.first) {a_bmin.first=tempb[i];a_bmin.second=i;}
        }
        for(ll i=0;i<N-1;++i) {
            if(tempa[i]<b_amin.first) {b_amin.first=tempa[i];b_amin.second=i;}
        }
        ll time=min(max(amin.first,a_bmin.first),max(bmin.first,b_amin.first));
        cout<<min(time,summin)<<endl;
    }
    else {
        ll time=max(amin.first,bmin.first);
        cout<<min(time,summin)<<endl;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}