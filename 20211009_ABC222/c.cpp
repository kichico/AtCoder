#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

const ll MOD=1e9+7;
const ll INF=1e17;
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

void twoText(bool identifier, string outTrue, string outFalse) {
    if (identifier) cout << outTrue << endl;
    else cout << outFalse << endl;
}

void twoText(bool identifier){
    if(identifier) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void counter(ll& num,ll& increaser,bool checker){
    if(checker) num+=increaser;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}
//#########################################################################
bool comp(const pair<ll,ll> fr,const pair<ll,ll> se){
    if(fr.first!=se.first) return fr.first>se.first;
    else return fr.second<se.second;
}


void solve(){
    ll N,M;
    cin>>N>>M;
    vector<string> p(2*N); rep(i,0,2*N) cin>>p[i];
    vector<pair<ll,ll>> win(2*N);
    rep(i,0,2*N) { win[i].first=0; win[i].second=i;}
    rep(i,0,M){
        for(ll j=0;j<2*N;j+=2){
            ll fr=win[j].second;
            ll se=win[j+1].second;
            char frc=p[fr][i];
            char sec=p[se][i];
            if(frc==sec) {
                continue;
            }
            else {
                if(frc=='G'){
                    if(sec=='P') win[j+1].first++;
                    else win[j].first++;
                }
                else if(frc=='P') {
                    if(sec=='C') win[j+1].first++;
                    else win[j].first++;
                }
                else {
                    if(sec=='G') win[j+1].first++;
                    else win[j].first++;
                }
            }
        }
        sort(ALL(win),comp);
    }
    rep(i,0,2*N) cout<<win[i].second+1<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
