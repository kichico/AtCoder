#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    long long N;
    cin>>N;
    vector<long long> a(N);
    for(int i=0;i<N;++i) cin>>a[i];
    int sum=a[0];
    int cnt=0;
    for(int i=1;i<N;++i) {
        if(a[0]>0){
            while(true){
                //cout<<i<<"th sum=>"<<sum<<endl;
                sum+=a[i];
                if(i<N-1){
                    if(sum!=0){
                        if(sum*(sum+a[i+1])<=0) break;
                        else{
                            sum-=a[i];
                            if(i%2==0) {
                                a[i]++;
                                cout<<"a[i]=>"<<a[i]<<endl;
                                cnt++;
                            }
                            else{
                                a[i]--;
                                cout<<"a[i]=>"<<a[i]<<endl;
                                cnt++;
                            }
                            cout<<i<<"th sum=>"<<sum<<endl;
                        }
                    }
                    else {
                        sum-=a[i];
                        if(i%2==0) {
                            a[i]++;
                            cout<<"a[i]=>"<<a[i]<<endl;
                            cnt++;
                        }
                        else{
                            a[i]--;
                            cout<<"a[i]=>"<<a[i]<<endl;
                            cnt++;
                        }
                        cout<<i<<"th sum=>"<<sum<<endl;
                    }
                }
                else {
                    if(sum!=0) break;
                    else{
                        sum-=a[i];
                        if(i%2==0) {
                            a[i]++;
                            cnt++;
                        }
                        else{
                            a[i]--;
                            cnt++;
                        }
                    }
                }
            }
       }
       if(a[0]<0){
                        while(true){
                //cout<<i<<"th sum=>"<<sum<<endl;
                sum+=a[i];
                if(i<N-1){
                    if(sum!=0){
                        if(sum*(sum+a[i+1])<=0) break;
                        else{
                            sum-=a[i];
                            if(i%2==0) {
                                a[i]++;
                                cout<<"a[i]=>"<<a[i]<<endl;
                                cnt++;
                            }
                            else{
                                a[i]--;
                                cout<<"a[i]=>"<<a[i]<<endl;
                                cnt++;
                            }
                            cout<<i<<"th sum=>"<<sum<<endl;
                        }
                    }
                    else {
                        sum-=a[i];
                        if(i%2==0) {
                                a[i]++;
                                cout<<"a[i]=>"<<a[i]<<endl;
                                cnt++;
                        }
                        else{
                            a[i]--;
                            cout<<"a[i]=>"<<a[i]<<endl;
                            cnt++;
                        }
                        cout<<i<<"th sum=>"<<sum<<endl;
                    }
                }
                else {
                    if(sum!=0) break;
                    else{
                        sum-=a[i];
                        if(i%2==0) {
                            a[i]--;
                            cnt++;
                        }
                        else{
                            a[i]++;
                            cnt++;
                        }
                    }
                }
            }
       }
    }
    cout<<cnt<<endl;
    return 0;
}