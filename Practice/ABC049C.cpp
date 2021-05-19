#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void) {
    string str,strc;
    string reference[4]={"dream","dreamer","erase","eraser"};
    cin>>str;
    reverse(str.begin(),str.end());
    for(int i=0;i<4;++i) reverse(reference[i].begin(),reference[i].end());
    bool can=true;
    for(int i=0;i<str.size();){
        bool candivide=false;
        for(auto x:reference) {
            if(str.substr(i,x.size())==x){
                candivide=true;
                i+=x.size();
            }
        }
        if(!candivide){
            can=false;
            break;
        }
    }
    if(can) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}