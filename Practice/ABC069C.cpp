#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
#define MOD 1e9+7
#define ALL(x) x.begin(),x.end()

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



vector<pair<ll,ll>> prime_factorize(ll Num){
    vector<pair<ll,ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(Num);
    for(ll i=0;i<Num;++i) listprime[i]=true;
    ll root=sqrt(Num);
    ll res=Num;
    for(ll i=2;i<=root;++i){
        ll expnum=0;
        if(listprime[i]) {
            while(res%i==0) {
                res/=i;
                expnum++;
            }
            for(ll j=i*2;j<=root;j+=i) listprime[j]=false;
        }
        if(expnum!=0) pr.emplace_back(make_pair(i,expnum));
    }
    if(res!=1) pr.emplace_back(make_pair(res,1));
    return pr;
}


int solve(){
    ll N;
    cin>>N;
    vector<ll> ae(N);
    vector<ll> a(N);
    ll x=0,y=0,z=0;
    for(ll i=0;i<N;++i) {
        ll in;
        cin>>in;
        ll cnt=0;
        while(in%2==0) {
            in/=2;
            cnt++;
        }
        ae[i]=cnt;
        if(cnt%2==0) x++;
        else if(cnt%2!=0&&cnt!=0) y++;
        else z++;
    }
    cout<<"x,y,z=>"<<x<<" "<<y<<" "<<z<<endl;
    if(y!=0) {
        if(x>=z) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    else {
        if(x+1>=z) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}