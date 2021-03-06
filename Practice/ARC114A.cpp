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
bool isPrime(ll Num){
    ll root=sqrt(Num);
    if(Num==0||Num==1) return false;
    for(ll i=2;i<=root;++i) if(Num%i==0) return false;
    return true;
}
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

void solve(){
    ll N;
    cin>>N;
    vector<ll> x(N);
    vector<ll> con;
    rep(i,0,N) {
        cin>>x[i];
    }
    rep(i,2,51) if(isPrime(i)) con.emplace_back(i); 
    ll ans=INF;
    set<ll> v;
    rep(tmp,0,1<<16){
        bitset<16> s{tmp};
        ll Y=1;
        rep(i,0,con.size()) if(s.test(i)) Y*=con[i];
        //cout<<"Y:"<<Y<<endl;
        bool flg=false;
        rep(i,0,x.size()) if(gcd(x[i],Y)==1) flg=true;
        if(flg) continue;
        if(Y>1) v.emplace(Y);
    }
    if(v.size()!=0) cout<<*v.begin()<<endl;
    else cout<<x[0]<<endl;
}  


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
