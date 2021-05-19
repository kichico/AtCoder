#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,N) for(ll i=0;i<N;++i)

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
vector<pair<ll,ll>> prime_factorize(ll Num){
    vector<pair<ll,ll>> pr; //pair<primenumber(素数),Exponentiation(べき数)>
    vector<bool> listprime(Num);
    //cout<<"Num"<<Num<<endl;
    //rep(i,Num) listprime[i]=true;
    //cout<<"here"<<endl;
    ll root=sqrt(Num);
    ll res=Num;
    //cout<<"debug"<<endl;
    for(ll i=2;i<=root;++i){
        ll expnum=0;
        //cout<<"res=>"<<res<<endl;
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
    //cout<<"now"<<endl;
    return pr;
}

int solve(){
    ll N;
    cin>>N;
    vector<string> res(N);
    rep(i,N){
        ll num;
        cin>>num;
        //cout<<"num=>"<<num<<endl;
        auto pr=prime_factorize(num);
        ll cnt_even=0;
        ll cnt_odd=1;
        if(num%2==0) cnt_even++;
        else cnt_odd++;
        rep(j,pr.size()){
            //cout<<pr[j].first<<endl;
            if(pr[j].first%2==0) cnt_even++;
            else cnt_odd++;
            //cout<<"cnt_even=>"<<cnt_even<<" cnt_odd=>"<<cnt_odd<<endl;
        }
        if(cnt_even>cnt_odd) res[i]="Even";
        else if(cnt_even==cnt_odd) res[i]="Same";
        else res[i]="Odd";
        //cout<<"result=>"<<res[i]<<endl;
    }
    rep(i,N) cout<<res[i]<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
