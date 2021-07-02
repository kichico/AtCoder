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





void solve(){
    ll N;
    cin>>N;
    ll p,q;
    cin.ignore();
    string s,g;
    getline(cin,s);
    //reverse(ALL(s));
    rep(i,0,s.size()) if(s[i]!=' ') g.push_back(s[i]);
    p=stoll(g);
    //cout<<p<<endl;
    g="";
    string t;
    getline(cin,t);
    //reverse(ALL(s));
    //cout<<t<<endl;
    rep(i,0,t.size()) if(t[i]!=' ') g.push_back(t[i]);
    q=stoll(g);
    //cout<<"here"<<endl;
    vector<ll> ref(N);
    rep(i,0,N) ref[i]=i+1;
    vector<ll> dic;
    do {
        string in;
        //for(auto x:ref) cout<<x<<endl;
        rep(i,0,ref.size()) in.push_back((ref[i]+'0'));
        dic.push_back(stoll(in)); 
    } while (next_permutation(ALL(ref)));
    sort(ALL(dic));
    ll qv,pv;
    rep(i,0,dic.size()){
        if(dic[i]==p) pv=i+1;
        if(dic[i]==q) qv=i+1;
    }
    cout<<abs(qv-pv)<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
