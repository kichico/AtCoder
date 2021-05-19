#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)
constexpr ll MOD=1e9+7;
constexpr ll INF=1e16;
template<class T>
using grid=vector<vector<T>>;
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
    string alpha="abcdefghijklmnopqrstuvwxyz";
    map<char,ll> alp;
    rep(i,alpha.size()) alp.emplace(alpha[i],i);
    ll len,k;
    string str;
    cin>>len>>k;
    cin>>str;
    grid<ll> vec(26,vector<ll>(len,str.size()-1));
    rep(i,len){
        ll now=len-1-i;
        //cout<<"now:"<<now<<",i:"<<i<<endl;
        rep(j,26){
            //cout<<"j:"<<j<<endl;
            if(((ll)str[now]-'a')==j) vec[j][now]=now;
            else if(now!=len-1) vec[j][now]=vec[j][now+1];
            else vec[j][now]=len;
        }
    }
    //cout<<"debug"<<endl;
    string ans="";
    ll current_pos=0;
    rep(i,k) rep(j,26){
        ll next_pos=vec[j][current_pos];
        ll maxlen=len-next_pos-1+i;
        //cout<<(char)(j+'a')<<"'s maxlen:"<<maxlen<<endl;
        if(maxlen>=k-1) {
            ans.push_back('a'+j);
            current_pos=next_pos+1;
            //cout<<i<<":"<<ans<<",current_pos:"<<current_pos<<endl;
            break;
        }
    }
    cout<<ans<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
