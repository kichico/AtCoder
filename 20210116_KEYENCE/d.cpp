#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N,prime;
    cin>>N>>prime;
    vector<vector<ll>> service(N,vector<ll>(3,0));//start,end,cost
    vector<ll> start(N,0),end(N,0);
    //vector<ll> cost(N);
    for(ll i=0;i<N;++i) {
        //cout<<"debug"<<endl;
       for(ll j=0;j<3;++j) {
          cin>>service[i][j];
       }
       start[i]=service[i][0];
       end[i]=service[i][0];
    }
    ll first=*min_element(start.begin(),start.end());
    ll final=*max_element(end.begin(),end.end());
    ll date=final-first;
    ll fee=0;
    ll cost=0;
    //cout<<"first=>"<<first<<", end=>"<<final<<endl;
    for(ll i=first;i<=final;++i) {
        for(ll j=0;j<N;++j) if(service[j][0]<=i&&service[j][1]>=i) fee+=service[j].back();
        //cout<<i<<"th fee is=>"<<fee<<endl;
        if(fee<=prime) cost+=fee;
        else cost+=prime;
        fee=0;
    }
    cout<<cost<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}