#include <iostream>
#include <math.h>

int main(void) {
    int N,W;
    std::cin>>N>>W;
    int result;
    result=floor(N/W);
    std::cout<<result<<std::endl;
    return 0;
}