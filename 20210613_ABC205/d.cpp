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
ll N,q;



void solve(){
    cin>>N>>q;
    vector<ll> remain(N);
    vector<ll> a(N);
    rep(i,0,N) cin>>a[i];
    remain[0]=max((ll)0,a[0]-1);
    vector<ll> res(q);
    rep(i,1,N) remain[i]=a[i]-a[i-1]-1+remain[i-1];
    rep(i,0,q){
        ll x;
        cin>>x;
        ll left=0,right=N+1;
        while(right-left>1){
            ll mid=left+(right-left)/2;
            if(mid>=N) break;
            //cout<<"mid:"<<mid<<endl;
            //cout<<"remain["<<mid<<"]:"<<remain[mid]<<endl;
            if(remain[mid]<x) left=mid;
            else right=mid;
        }
        //cout<<"left:"<<left<<" right:"<<right<<endl;
        if(left+1==N&&remain[left]<x) res[i]=x+N;
        else if(remain[left]<x) res[i]=x+right;
        else res[i]=x+left;
    }
    for(auto x:res) cout<<x<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
