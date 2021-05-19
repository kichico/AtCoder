#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,start,N) for(ll i=start;i<N;++i)

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


void solve(){
    string s;
    deque<char> t;
    cin>>s;
    reverse(ALL(s));
    ll len=s.size();
    ll cnt=2;
    rep(i,0,len){
        if(s.back()!='R') {
            if(cnt%2==0) t.push_back(s.back());
            else t.push_front(s.back());
        }
        else cnt++;
        s.pop_back();
        //cout<<t<<endl;
        if(cnt%2==0&&t.size()>=2&&t[t.size()-1]==t[t.size()-2]) {t.pop_back();t.pop_back();}
        else if(cnt%2==1&&t.size()>=2&&t[0]==t[1]) {t.pop_front();t.pop_front();}
    }
    string pr;
    rep(i,0,t.size()) pr.push_back(t[i]);
    if(cnt%2==1) reverse(ALL(pr));
    cout<<pr<<endl;
}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}