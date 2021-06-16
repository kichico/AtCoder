#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using L128=ll;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(L128 iter=from;iter<to;++iter)

const L128 MOD=1e9+7;
const L128 INF=1e17;
//#######################################################################
vector<vector<L128>> input(L128 N, L128 width){
    string str;
    vector<vector<L128>> vec(N,vector<L128>(width));
    for(L128 i=0;i<N;++i){
        cin>>str;
        reverse(ALL(str));
        for(L128 j=0;j<width;++j){
            vec[i][j]=str.back();
            str.pop_back();
        }
    }
    return vec;
}
void op(vector<L128> vec){
    L128 size=(L128)vec.size();
    for(L128 i=0;i<size-1;++i) cout<<vec[i]<<" ";
    cout<<vec.back()<<endl;
}

void op(vector<vector<L128>> vec){
    L128 height=(L128)vec.size();
    L128 width=(L128)vec[0].size();
    for(L128 i=0;i<height;++i) {
        for(L128 j=0;j<width-1;++j) cout<<vec[i][j]<<" ";
        cout<<vec[i].back()<<endl;
    }
}
//########################################################################


L128 modpow(L128 x, L128 n){
    L128 ans=1;
    while(n>0) {
        if(n&1) ans=ans*x%MOD;
        x=x*x%MOD;
        n>>=1;
    }
    return ans;
}

L128 com(L128 n, L128 k, vector<L128> fac_n,vector<L128> fac_k){
    if(n==0&&k==0) return 1;
    if(n<k||n<0) return 0;
    L128 value=fac_k[n-k]*fac_k[k]%MOD;
    return value*fac_n[n]%MOD;
}

void solve(){
    ll N;
    cin>>N;
    ll ans=1;
    rep(i,1,12){
        ans*=N-i;
        ans/=i;
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
