#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main(void){
    long long N;
    cin>>N;
    vector<string> str(N);
    unordered_set<string> SN(N);
    //string str;
    
    for(string&s :str) cin>>s;
    SN=unordered_set<string>(str.begin(),str.end());
    for(auto& s:SN) if(SN.count('!'+s)){
        cout<<s<<endl;
        return 0;
    }
    cout<<"satisfied"<<endl;
    return 0;
}