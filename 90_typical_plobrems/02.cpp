#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,start,end) for(ll i=start;i<end;++i)

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

ll N;
int solve(){
    cin>>N;
    ll cnt=0;
    vector<string> str;
    for(ll i=0;i<(1<<20); ++i){
        bitset<21> s(i);
        //for(auto s:kakko) cout<<s<<" ";
        //cout<<endl;
        ll check=0;
        string kakko(N,'(');
        if(s.test(N)) break;
        rep(j,0,N) if(s.test(j)) kakko[j]=')';
        //cout<<kakko<<endl;
        rep(j,0,N) {
            if(kakko[j]=='(') check++;
            else check--;
            if(check<0) break;
            //cout<<"check=>"<<check<<endl;
        }
        if(check==0) {
            cnt++;
            //cout<<"kakko=>"<<kakko<<endl;
            str.emplace_back(kakko);
        }
    }
    if(!str.empty()){
        sort(ALL(str));
        rep(i,0,cnt) cout<<str[i]<<endl;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
