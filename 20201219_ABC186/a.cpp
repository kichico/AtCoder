#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
    int N,W;
    cin>>N>>W;
    int sum=1;
    while(N>=W*sum) sum++;
    cout<<sum-1<<endl;
    return 0;
}