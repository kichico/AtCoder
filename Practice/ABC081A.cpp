#include <string>
#include <iostream>

int main(void){
    std::string s;
    std::cin>>s;
    int cnt=0;
    for(auto i:s) if(i=='1') cnt++;
    std::cout<<cnt<<std::endl;
    return 0;
}