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





int solve(){
    ll N;
    cin>>N;
    vector<ll> dish(N);
    ll range1=0,range2=0;
    vector<ll> one,two;
    rep(i,0,N) cin>>dish[i];
    sort(ALL(dish));
    while(!dish.empty()){
        if(range1<=range2) {range1+=dish.back();one.push_back(dish.back());}
        else {range2+=dish.back();two.push_back(dish.back());}
        dish.pop_back();
        if(dish.empty()) break;
        else {
            if(range1<=range2) {range1+=dish.back();one.push_back(dish.back());}
            else {range2+=dish.back();two.push_back(dish.back());}
            dish.pop_back();
        }
    }
    cout<<"1 sum:"<<range1<<">";
    op(one);
    cout<<"2 sum:"<<range2<<">";
    op(two);
    cout<<max(range1,range2)<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
