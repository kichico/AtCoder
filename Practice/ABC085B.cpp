#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
    int N;
    cin>>N;
    vector<int> maru(N);
    for(int i=0;i<N;++i) cin>>maru[i];
    sort(maru.begin(),maru.end());
    vector<int> pile;
    int mem=maru.front();
    int i=0;
    while(true){
        if(i==N) break;
        if(maru[i]!=mem) {
            mem=maru[i];
            pile.push_back(maru[i]);
            //cout<<"piled=>"<<maru[i]<<endl;
        }
        i++;
    }
    pile.push_back(maru.front());
    cout<<pile.size()<<endl;
    //for(auto x:maru) cout<<x<<endl;
    return 0;

}