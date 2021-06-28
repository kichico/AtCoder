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


struct kukan{
    ll kind;
    ll from;
    ll to;
};


void solve(){
    ll N;
    cin>>N;
    vector<kukan> a(N);
    rep(i,0,N) cin>>a[i].kind>>a[i].from>>a[i].to;
    ll cnt=0;
    rep(i,0,N-1) rep(j,i+1,N){
        auto fr=a[i];
        auto se=a[j];
        if(a[i].from>a[j].from) swap(fr,se);
        else if(a[i].from==a[j].from&&a[i].to>a[j].to) swap(fr,se);
        else if(a[i].to==a[i].to&&a[i].from>a[j].from) swap(fr,se);
        if(fr.to>se.from&&fr.from<se.from) {
            cnt++;
        }
        else if(fr.from==se.from&&fr.to==se.to) cnt++;
        else {
            if(fr.to==se.from){
                if(fr.kind==1||fr.kind==3) if(se.kind==2||se.kind==1) {
                    cnt++;
                }
            }
            else if(fr.from==se.from) {
                if(fr.kind=1||fr.kind==2) if(se.kind==1||se.kind==2) {
                    cnt++;
                }
                else if(fr.to<se.to) cnt++;
            }
            else if(fr.to==se.to) {
                if(fr.kind==1||fr.kind==3) if(se.kind==1||se.kind==3) {
                    cnt++;
                }
                else if(fr.from<se.from) cnt++;
            }
            else if(fr.from<se.from&&fr.to>se.to) {
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
