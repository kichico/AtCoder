#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
    int N;
    cin>>N; cin.ignore();
    vector<int> card(N);
    for(int i=0;i<N;++i) cin>>card[i];
    sort(card.begin(),card.end());
    vector<int> a,b;
    //for(int i=0;i<N;++i) cout<<card[i]<<" ";
    while(card.size()>0){
        a.push_back(card.back());
        card.pop_back();
        if(card.size()==0) break;
        b.push_back(card.back());
        card.pop_back();
    }
    int sum_a=0,sum_b=0;
    for(auto x:a) sum_a+=x;
    for(auto x:b) sum_b+=x;
    cout<<sum_a-sum_b<<endl;
    return 0;
}