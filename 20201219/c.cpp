#include <vector>
#include <iostream>
#include <string>

std::string to_oct(long long num){
    std::string s;
    while(num>0) {
        s=std::to_string(num%8)+s;
        num/=8;
    }
    return s;
}
int main(void) {
    long long N;
    std::cin>>N;
    long long ans=0;
    for(int i=1;i<=N;i++){
        std::string num_s=std::to_string(i);
        int numlength=num_s.size();
        bool flg_detected=false;
        for(int j=0;j<numlength;++j) if(num_s[j]=='7') {
            ++ans;
            //std::cout<<i<<"at x10"<<std::endl;
            flg_detected=true;
            break;
        }
        if(!flg_detected) {
        num_s=to_oct(i);
        numlength=num_s.size();
            for(int j=0;j<numlength;++j) if(num_s[j]=='7') {
                ++ans;
                //std::cout<<i<<"at x8"<<std::endl;
                break;
            }
        }
    }
    std::cout<<N-ans<<std::endl;
}