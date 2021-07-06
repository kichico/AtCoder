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

struct house{
    ll x;
    ll y;
    ll ID;
};



void solve(){
    ll N;
    cin>>N;
    vector<house> pos(N);
    set<ll> IDs;
    rep(i,0,N) { cin>>pos[i].x>>pos[i].y;pos[i].ID=i; }
    sort(ALL(pos),[](auto const& fr,auto const& se){return fr.x<se.x;});
    //cout<<"--------x---------"<<endl;
    //for(auto x:pos) cout<<x.x<<" "<<x.y<<" "<<x.ID<<endl;
    rep(i,0,2) {
        IDs.insert(pos[i].ID);
        //cout<<"ID:"<<pos[i].ID<<" "<<pos[N-1-i].ID<<endl;
        IDs.insert(pos[N-1-i].ID);
    }
    sort(ALL(pos),[](auto const& fr,auto const& se){return fr.y<se.y;});
    
    //cout<<"--------y---------"<<endl;
    //for(auto x:pos) cout<<x.x<<" "<<x.y<<endl;
    rep(i,0,2) {
        IDs.insert(pos[i].ID);
        IDs.insert(pos[N-1-i].ID);
    }
    vector<ll> d;
    vector<pair<ll,ll>> kouho;
    rep(i,0,N) if(IDs.count(pos[i].ID)!=0) kouho.emplace_back(pos[i].x,pos[i].y);
    rep(i,0,kouho.size()) rep(j,i+1,kouho.size()) {
        d.emplace_back(max(abs(kouho[i].first-kouho[j].first),abs(kouho[i].second-kouho[j].second)));
    }
    sort(ALL(d));
    //cout<<"-------------------"<<endl;
    //for(auto x:kouho) cout<<x.first<<" "<<x.second<<endl;
    //for(auto x:d) cout<<x<<endl;
    cout<<d[d.size()-2]<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
