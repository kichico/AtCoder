#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;

int solve(){
    ll N,K;
    cin>>N>>K;
    vector<ll> num(N);
    vector<ll> a(N);
    vector<vector<ll>> box(K,vector<ll>(0));
    for(ll i=0;i<N;++i){
        cin>>a[i];
        num[a[i]]++;
    }
    sort(a.begin(),a.end());
    //for(auto x:a) cout<<x<<" ";
    //cout<<endl;
    ll cnt=0;
    vector<ll> ref(N);
    for(int i=0;i<N;++i) ref[i]=i;
    for(ll i=0;i<N;++i){
        cnt=0;
        for(ll j=0;j<num[ref[i]];j++) {
            if(cnt<K) {
                box[j].push_back(ref[i]);
                //cout<<"box["<<j<<"]=>";
                //for(ll k=0;k<box[j].size();++k) cout<<box[j][k]<<" ";
                //cout<<endl;
                cnt++;
            }
            else break;
        }
    }
    /*for(ll i=0;i<K;++i) {
        for(ll j=0;j<box[i].size();++j) cout<<box[i][j]<<" ";
        cout<<endl;
    }*/
    ll sum=0;
    for(ll i=0;i<K;++i) sort(box[i].begin(),box[i].end());
    for(ll i=0;i<K;++i){
        ll iter=1;
        ll size=box[i].size();
        //cout<<size<<endl;
        while(true){
            if(box[i].empty()||box[i][0]!=0) break;
            if(size==iter) {
                sum+=box[i][iter-1]+1;
                //cout<<"box["<<i<<"] th sum2=>"<<box[i][iter-1]+1<<endl;
                break;
            }
            else if(box[i][iter-1]!=box[i][iter]-1) {
                sum+=box[i][iter]-1;
                //cout<<"box["<<i<<"] th sum1=>"<<box[i][iter]-1<<endl;
                break;
            }
            else iter++;
        }
    }
    cout<<sum<<endl;
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}