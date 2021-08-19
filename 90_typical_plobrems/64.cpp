#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

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

//#########################################################################

void solve(){
    ll N,q;
    cin>>N>>q;
    vector<ll> a(N+1),diff(N,0);
    ll sum=0;
    rep(i,0,N) {
        cin>>a[i];
        if(i!=0) {
            diff[i]=a[i]-a[i-1];
            sum+=diff[i];
        }
    }
    vector<ll> R(q),L(q),V(q);
    rep(i,0,q){
        cin>>R[i]>>L[i]>>V[i];
        R[i]--;L[i]--;
    }
    vector<ll> ans(q);
    rep(i,0,q){
        ll left=0;
        ll before=0,after=0;
        if(L[i]!=0) left=L[i]-1; 
        if(L[i]-1>0) diff[L[i]-1]+=V[i];
        if(R[i]<N) diff[R[i]]-=V[i];
        ll after=abs(diff[L[i]-1])+

    }
    rep(i,0,q) cout<<ans[i]<<endl;


}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
