#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<char>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)

const ll MOD=1e9+7;
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
//########################################################################

ll DFS(ll x,ll y, grid& field, ll dx, ll dy,ll cnt){
    //cout<<"("<<x<<","<<y<<")"<<endl;
    if(x>=field.size()||x<0||y>=field[0].size()||y<0) return cnt;
    if(field[x][y]=='.') {
        x+=dx; y+=dy;
        cnt++;
        //cout<<"cnt=>"<<cnt<<endl;
        cnt=DFS(x,y,field,dx,dy,cnt);
    }
    //cout<<"break"<<endl;
    //cout<<"cnt=>"<<cnt<<endl;
    return cnt;
}


int solve(){
    ll H,W,x0,y0;
    cin>>H>>W>>x0>>y0;
    x0--;y0--;
    grid field(H,vector<char>(W,'.'));
    rep(i,H) rep(j,W) cin>>field[i][j];
    vector<ll> dx{1,0,-1,0};
    vector<ll> dy{0,1,0,-1};
    ll sum=1;
    rep(i,4){
        ll cnt=0;
        sum+=DFS(x0+dx[i],y0+dy[i],field,dx[i],dy[i],cnt);
        //cout<<"sum=>"<<sum<<endl;
    }
    cout<<sum<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
//#######################################################################
