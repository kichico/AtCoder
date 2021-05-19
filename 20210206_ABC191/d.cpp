#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;

int solve(){
    ld x,y,r;
    ll start,end,top,bottom,X,Y,R;
    cin>>x>>y>>r;
    ll dd=1e4;
    X=round(x*dd);
    Y=round(y*dd);
    R=round(r*dd);
    start=ceil(X-R);
    end=floor(X+R);
    cout<<"start=>"<<start<<",end=>"<<end<<endl;
    ll num=0;
    //if(start==end) cout<<"equal"<<endl;
    for(ll i=start;i<=end;++i){
        ll p=sqrt(pow(R,2)-pow((X-i),2));
        bottom=ceil(Y-p);
        top=floor(Y+p);
        cout<<"now=>"<<i<<",top=>"<<top<<",bottom=>"<<bottom<<endl;
        num+=(ll)(top/dd)-(ll)(bottom/dd)+1;
    }
    cout<<num<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}