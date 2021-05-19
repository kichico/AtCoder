#include <string>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    long long cnt=0;
    long long N;
    cin>>N;
    vector<double> x(N),y(N);
    for(int i=0;i<N;++i) cin>>x[i]>>y[i];
    for(int i=0;i<N;++i) {
        //cout<<"debug"<<endl;
        for(int j=i+1;j<N;++j){
            double a=(y[j]-y[i])/(x[j]-x[i]);
            cout<<j<<" a=>"<<a<<endl;
            if(a>=-1&&a<=1) cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}