#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;
using ll=long long;

int main(void){
    ll N;
    cin>>N;
    vector<vector<ll>> card(N,vector<ll>(2,0)),check(0,vector<ll>(2,0));
    unordered_set<ll> set,aset,bset;
    ll cnt=0;
    for(long long i=0;i<N;++i) {
        cin>>card[i][0]>>card[i][1];
        ll a=card[i][0];
        ll b=card[i][1];
        if(set.find(a)==set.end()&&set.find(b)==set.end()) {
            ll tempa=a;
            ll tempb=b;
            if(aset.find(a)!=aset.end()) tempa=0;
            else aset.insert(a);
            if(bset.find(b)!=bset.end()) tempb=0;
            else bset.insert(b);
            check.push_back(vector<ll>({tempa,tempb}));
        }
        else for(int j=0;j<2;++j) set.insert(card[i][j]);
    }
    for(int i=0;i<check.size();++i){
        if(check[i][0]==0&&check[i][1]==0) {
            check.pop_back();
        }
    }
    for(auto x:set) cout<<"set=>"<<x<<endl;
    for(int i=0;i<check.size();++i){
        //cout<<"debug"<<endl;
        ll a=check[i][0];
        ll b=check[i][1];
        if(a==0) set.insert(b);
        if(b==0) set.insert(a);
        cout<<"a=>"<<a<<" b=>"<<b<<endl;
        if(set.find(a)==set.end()&&set.find(b)==set.end()) {
            cout<<a<<" "<<b<<endl;
            cnt++;
        }
        for(int j=0;j<2;++j) set.insert(check[i][j]);
    }
    cout<<cnt<<endl;
    cout<<set.size()-cnt<<endl;
}