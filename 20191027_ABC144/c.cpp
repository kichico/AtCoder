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

vector<pair<ll,ll>> prime_factorize(ll Num){
    vector<pair<ll,ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(Num);
    for(ll i=0;i<Num;++i) listprime[i]=true;
    ll root=sqrt(Num);
    ll res=Num;
    for(ll i=2;i<=root;++i){
        ll expnum=0;
        if(listprime[i]) {
            while(res%i==0) {
                res/=i;
                expnum++;
            }
            for(ll j=i*2;j<=root;j+=i) listprime[j]=false;
        }
        if(expnum!=0) pr.emplace_back(make_pair(i,expnum));
    }
    if(res!=1) pr.emplace_back(make_pair(res,1));
    sort(ALL(pr));
    return pr;
}





void solve(){
    ll N;
    cin>>N;
    //vector<ll> prime;
    ll ans=INF;
    rep(i,1,sqrt(N)+1){
        if(N%i!=0) continue;
        ll v=N/i;
        ans=min(ans,(i-1+v-1));
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
