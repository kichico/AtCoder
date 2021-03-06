
#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)

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

ll len,cut,N;
vector<ll> A;
bool bs(ll mid){
    ll cnt=0;
    ll last=0;
    for(ll i=0;i<N;++i) {
        //cout<<"now=>"<<A[i]<<", mid=>"<<mid<<endl;
        if(A[i]-last>=mid&&len-A[i]>=mid) {
            //cout<<"cut at "<<A[i]<<endl;
            cnt++;
            last=A[i];
        }
    }
    //cout<<"cnt=>"<<cnt<<endl;
    if(cnt>=cut) return true;
    else return false;
}

int solve(){
    cin>>N>>len;
    cin>>cut;
    A=vector<ll>(N,-1);
    rep(i,N) cin>>A[i];
    ll right=len+1;
    ll left=-1;
    while(right-left>1){
        ll mid=left+(right-left)/2;
        //cout<<"mid=>"<<mid<<endl;
        bool flg=bs(mid);
        if(flg) left=mid;
        else right=mid;
    }
    cout<<left<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}

