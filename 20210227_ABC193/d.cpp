#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
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


int solve(){
    ll N;
    cin>>N;
    string takahashi,aoki;
    cin>>takahashi>>aoki;
    vector<ll> num_aoki(9,0),num_takahashi(9,0);
    vector<ll> card(9,N);
    reverse(ALL(takahashi));
    reverse(ALL(aoki));
    for(ll i=0;i<4;++i){
        ll in=takahashi.back()-'0'-1;
        num_takahashi[in]++;
        card[in]--;
        in=aoki.back()-'0'-1;
        num_aoki[in]++;
        card[in]--;
        takahashi.pop_back();
        aoki.pop_back();
    }
    ld win=0.0;
    for(ll i=0;i<9;++i){
        vector<ll> tempt=num_takahashi;
        tempt[i]++;
        for(ll j=0;j<9;++j){
            vector<ll> tempa=num_aoki;
            tempa[j]++;
            ll ascore=0,tscore=0;
            for(ll k=0;k<9;++k) {
                ll ap=(ll)((k+1)*pow(10,tempa[k]));
                string as=to_string(ap);
                if(as.size()>1&&as.size()%2!=0) ap++;
                ascore+=ap;
                cout<<ap<<endl;
                cout<<"ascore=>"<<ascore<<endl;
                ll tp=(ll)((k+1)*pow(10,tempt[k]));
                string ts=to_string(tp);
                if(ts.size()>1&&ts.size()%2!=0) tp++;
                tscore+=tp;
                cout<<tp<<endl;
                cout<<"tscore=>"<<tscore<<endl;
            }
            cout<<"i=>"<<i<<",j=>"<<j<<endl;
            cout<<"ascore=>"<<ascore<<",tscore=>"<<tscore<<endl;
            if(tscore>ascore) win+=((double)card[i]/(9*N-4))*((double)card[j]/(9*N-5));
        }
    }
    cout<<win<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}