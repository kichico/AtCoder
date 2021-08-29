#include "bits/stdc++.h"
#include <fstream>
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
    string filename="output1.txt"; ofstream ofs(filename);
    string input="input01.txt"; ifstream ifs(input);
    ll N,M,K;
    cin>>N>>M>>K;
    vector<pair<ll,ll>> monster(N);
    map<ll,ll> cnt;
    rep(i,0,N){
        cin>>monster[i].first; monster[i].second=i;
        cnt[monster[i].first]++;
    }
    vector<pair<ll,ll>> ans;
    sort(ALL(monster));
    while(M>0){
        rep(p,0,N/2){
            ll q=N-p-1;
            ans.push_back(make_pair(monster[p].second,monster[q].second));
            monster[p].first=(monster[p].first+monster[q].second)%K;
            M--;
            if(M<=0) break;
        }
        sort(ALL(monster));
        if(M<=0) break;
    }
    for(auto a:ans) cout<<a.first<<" "<<a.second<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
