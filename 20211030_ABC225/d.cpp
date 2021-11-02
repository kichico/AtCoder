#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto& variable:container)
#define forc(variable,container) for(auto& variable:container) cout<<variable<<endl;
const ll MOD=1e9+7;
const ll INF=1e17;
const vector<ll> dx{1,0,-1,0},dy{0,1,0,-1};
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

template <class T>
T vecsum(vector<T>& vec){
    return accumulate(ALL(vec),(T)0);
}

template<class T,ll>
T vecsum(vector<T>& vec, ll K){
    ll ret = 0;
    rep(i,0,K) ret+=vec[i];
    return ret;
}
//#########################################################################
struct relation{
    ll front; ll rear;
    void init(){
        this->front = -1;
        this->rear = -1;
    }
};


void solve(){
    ll N,q; cin>>N>>q;
    vector<relation> train(N);
    vector<string> ans;
    rep(i,0,N) train[i].init();
    rep(i,0,q){
        ll num; cin>>num;
        if(num == 1){
            ll x,y; cin>>x>>y;
            x--; y--;
            train[x].rear = y;
            train[y].front = x;
        }
        else if(num == 2){
            ll x,y; cin>>x>>y;
            x--; y--;
            train[x].rear = -1;
            train[y].front = -1;
        }
        else {
            ll x; cin>>x;
            x--;
            deque<ll> out;
            out.push_back(x+1);
            ll now = train[x].front;
            while(now != -1) {
                out.push_front(now + 1);
                now = train[now].front;
            }
            now = train[x].rear;
            while(now != -1){
                out.push_back(now + 1);
                now = train[now].rear;
            }
            string ss;
            ss += to_string((ll)out.size())+" ";
            rep(i,0,out.size()) ss += to_string(out[i]) + " ";
            ss.pop_back();
            ans.emplace_back(ss);
        }
    }
    forc(x,ans);
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
