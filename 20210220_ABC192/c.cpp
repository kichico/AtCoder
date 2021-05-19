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


ll g1(ll N){
    if(N=='0') return 0;
    string nstr=to_string(N);
    vector<ll> vec;
    reverse(ALL(nstr));
    for(ll i=0;i<nstr.size();++i){
        vec.push_back(nstr[i]-'0');
    }
    sort(ALL(vec));
    if(vec.front()==0) vec.erase(vec.begin());
    if(vec.size()==0) return 0;
    string changed;
    for(auto x:vec) changed+=to_string(x);
    ll ret=stoi(changed);
    return ret;
}

ll g2(ll N){
    if(N=='0') return 0;
    string nstr=to_string(N);
    vector<ll> vec;
    reverse(ALL(nstr));
    for(ll i=0;i<nstr.size();++i){
        vec.push_back(nstr[i]-'0');
    }
    sort(vec.rbegin(),vec.rend());
    if(vec.front()==0) vec.erase(vec.begin());
    if(vec.size()==0) return 0;
    string changed;
    for(auto x:vec) changed+=to_string(x);
    ll ret=stoi(changed);
    return ret;
}
int solve(){
    ll N,K;
    cin>>N>>K;
    for(ll i=0;i<K;++i) {
        ll gf=g1(N);
        ll ge=g2(N);
        ll f=ge-gf;
        N=f;
        //cout<<"gf=>"<<gf<<",ge=>"<<ge<<",f=>"<<f<<endl;
    }
    cout<<N<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}