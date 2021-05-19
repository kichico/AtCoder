#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(iter,start,N) for(ll iter=start;iter<N;++iter)

const ll MOD=1e9+7;
constexpr ll INF=1e18;
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
ll N;
vector<ll> jyuku;

int solve(){
    cin>>N;
    jyuku=vector<ll>(N);
    rep(i,0,N) cin>>jyuku[i];
    sort(ALL(jyuku));
    ll p=0;
    cin>>p;
    vector<ll> rate(p),res(p);
    rep(i,0,p) {
        cin>>rate[i];
        ll position=lower_bound(ALL(jyuku),rate[i])-jyuku.begin();
        ll dif1=INF,dif2=INF;
        if(position<jyuku.size()) dif1=abs(rate[i]-jyuku[position]);
        if(position>=1) dif2=abs(rate[i]-jyuku[position-1]);
        //cout<<"position,dif1,dif2=>"<<position<<","<<dif1<<","<<dif2<<endl;
        res[i]=min(dif1,dif2);
        //if(position>=jyuku.begin()+1) df2=abs(rate[i]-*jyuku.begin()+position]);
       
    }
    for(auto a:res) cout<<a<<endl;;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}