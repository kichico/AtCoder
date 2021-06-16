#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
using ll=long long;

int main(){
  ll N;
  cin>>N;
  string str,s;
  cin>>str;
  reverse(str.begin(),str.end());
  ll cnt=0;
  while(!str.empty()){
    s.push_back(str.back());
    str.pop_back();
    if(s.size()>=3){
      string ss;
      ss.push_back(s[s.size()-3]);
      ss.push_back(s[s.size()-2]);
      ss.push_back(s[s.size()-1]);
      //cout<<"ss:"<<ss<<endl;
      if(ss=="ABC") cnt++;
    }
  }
  cout<<cnt<<endl;
  return 0;
}