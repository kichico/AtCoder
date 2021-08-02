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
    ll N,M;
    cin>>N>>M;
    vector<ll> a(N),b(M);
    set<ll> ans;
    rep(i,0,N) cin>>a[i];
    rep(i,0,M) cin>>b[i];
    sort(ALL(a));
    sort(ALL(b));
    ll searched=0;
    ll v=0;
    rep(i,0,N){
        if(searched<M) {
            rep(j,searched,M) {
                bool flg=true;
                if(b[j]>a[i]){
                    if(j==0) {
                        searched=0;
                        v=abs(a[i]-b[j]);
                        ans.insert(v);
                        flg=false;
                        break;
                    }
                    else {
                        v=min(abs(a[i]-b[j-1]),abs(a[i]-b[j]));
                        ans.insert(v);
                        flg=false;
                        if(j!=M-1) searched=j-1;
                        else searched=M;
                        break;
                    }
                }
                if(flg) {searched=M;ans.insert(abs(a[i]-b.back()));}
            }
        }
        else {
            v=abs(a[i]-b.back());
            ans.insert(abs(a[i]-b.back()));
            searched=M;
        }
    }
    cout<<*ans.begin()<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
