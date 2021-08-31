#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

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

//#########################################################################

void solve(){
    ll N,M;
    cin>>N>>M;
    vector<queue<ll>> que(M);
    vector<vector<ll>> pos(N+1);
    rep(i,0,M){
        ll v;cin>>v;
        rep(j,0,v){
            ll boal; cin>>boal;
            que[i].push(boal);
            pos[boal].push_back(i);
        }
    }
    map<ll,ll> cnt;
    rep(i,0,M) cnt[que[i].front()]++;
    ll init=-1;
    ll num=0;
    queue<ll> cand;
    for(auto x:cnt) if(x.second>1) {
        init=x.first;
        cand.push(init);
    }
    if(init==-1) {cout<<"No"<<endl; return;}
    rep(i,0,N){
        init=cand.front(); cand.pop();
        ll a=pos[init][0];
        ll b=pos[init][1];
        cnt.erase(init);
        if(!que[a].empty()) que[a].pop();
        if(!que[b].empty()) que[b].pop();
        ll av,bv;
        if(!que[a].empty()) {
            av=que[a].front();
            cnt[av]++;
            if(cnt[av]==2) cand.push(av);
        }
        if(!que[b].empty()) {
            bv=que[b].front();
            cnt[bv]++;
            if(cnt[bv]==2) cand.push(bv);
        }
        //if(!cand.empty()) cout<<"next:"<<cand.front()<<endl;
        if(cand.empty()&&i!=N-1) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}


int main(void){
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);
    solve();
}
