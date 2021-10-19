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
    ll N=100000;
    cin>>N;
    map<ll,ll> cnt; vector<ll> odd(N/2),even(N/2);
    rep(i,0,N){
        if(i%2==0) odd[i/2]=all[i];
        else even[i/2]=all[i];
    }
    rep(i,0,N/2) cnt[odd[i]]++;
    vector<pair<ll,ll>> left,right;
    fore(x,cnt) {
        auto pr=make_pair(x.second,x.first);
        left.emplace_back(pr);
    }
    sort(ALL(left));
    cnt.clear();
    rep(i,0,N/2) cnt[even[i]]++;
    fore(x,cnt) {
        auto pr=make_pair(x.second,x.first);
        right.emplace_back(pr);
    }
    sort(ALL(right));
    if(right.size()==1&&left.size()==1) { 
        if(right.back().second==left.back().second) cout<<N/2<<endl;
        else cout<<0<<endl;
    }
    else if(right.size()==1){
        ll ref=right.back().second;
        ll ans=N/2-right.back().first;
        while(left.back().second==ref) left.pop_back();
        cout<<ans+(N/2-left.back().first)<<endl;
    }
    else if(left.size()==1){
        swap(right,left);
        ll ref=right.back().second;
        ll ans=N/2-right.back().first;
        while(left.back().second==ref) left.pop_back();
        cout<<ans+(N/2-left.back().first)<<endl;
    }
    else{
        if(left.back().second!=right.back().second) cout<<N-left.back().first-right.back().first<<endl;
        else {
            ll leftend=left.size()-1; ll rightend=right.size()-1;
            cout<<N-max(left[leftend].first+right[rightend-1].first,left[leftend-1].first+right[rightend].first)<<endl;
        }
    }
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
