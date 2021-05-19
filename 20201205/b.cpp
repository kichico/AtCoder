#include <vector>
#include <iostream>
#include <string>
int main(void){
    long long N;
    std::string T;
    std::cin>>N;
    std::cin>>T;
    int front=0,end=N-1;
    while(true){
        if(T[front]=='0') break;
        front++;
    }
    while(true){
        if(T[end]=='0') break;
        end--;
    }
}