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
    ll N=1,M=200000,lim=408057510;
    cin>>N>>M>>lim;
    vector<ll> a(N),b(M);
    vector<ll> atot(N),btot(M);
    rep(i,0,N){
        cin>>a[i];
        if(i==0) atot[i]=a[i];
        else atot[i]=a[i]+atot[i-1];
    }
    rep(i,0,M){
        cin>>b[i];
        if(i==0) btot[i]=b[i];
        else btot[i]=b[i]+btot[i-1];
    }
    ll ok=M-1;
    vector<tuple<ll,ll,ll>> tp;
    while(0<=ok&&lim<btot[ok]) ok--; 
    tp.emplace_back(ok+1,0,ok+1);
    rep(i,0,N){
        while(0<=ok&&lim<atot[i]+btot[ok]) ok--;
        if(ok<0&&atot[i]<=lim) {
            auto t=make_tuple(i+1,i+1,0);
            tp.emplace_back(t);
        } 
        else if(ok>=0&&atot[i]+btot[ok]<=lim) tp.emplace_back(ok+1+i+1,i+1,ok+1);
        cout<<btot[ok]<<endl;
    }
    sort(ALL(tp));
    //cout<<get<0>(tp[tp.size()-2])<<" "<<get<1>(tp[tp.size()-2])<<" "<<get<2>(tp[tp.size()-2])<<endl;
    cout<<get<0>(tp.back())<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
