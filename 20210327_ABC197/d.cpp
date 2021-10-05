#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,from,N) for(ll i=from;i<N;++i)

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


struct position{
   ll x;
   ll y;
};


int solve(){
    ll N;
    cin>>N;
    position zero,half;
    cin>>zero.x>>zero.y;
    cin>>half.x>>half.y;
    ld dist=sqrt(pow(half.x-zero.x,2)+pow(half.y-zero.y,2));
    ld pi=4*atan(1);
    ld onearg=((N-2)/(ld)N)*pi;
    ld len=(dist/(N/2))/cos(onearg);
    position vec;
    vec.x=half.x-zero.x;
    vec.y=half.y-zero.y;
    vector<vector<ld>> rot(2,vector<ld>(2,0));
    rot[0][0]=cos(onearg/2);
    rot[0][1]=-1*sin(onearg/2);
    rot[1][0]=sin(onearg/2);
    rot[1][1]=cos(onearg/2);
    vector<ll> v(2); v[0]=vec.x; v[1]=vec.y;
    vector<ld> afr(2,0);
    rep(i,0,2) rep(j,0,2) afr[i]+=rot[i][j]*v[j];
    ld power=0;
    cout<<afr[0]<<" "<<afr[1]<<endl;
    
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}