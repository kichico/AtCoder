#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;



int main(){
    string X="AABACAC",Y="CBCAAC";
    vector<vector<int>> Mat(4,vector<int>(4,0));
    vector<vector<int>> dp(X.size()+1,vector<int>(Y.size()+1,0));
    for(int i=0;i<4;++i) for(int j=0;j<4;++j) {
        int v; cin>>v;
        Mat[i][j]=v;
    }
    for(int i=0;i<=X.size();++i) dp[i][0]=0;
    for(int j=0;j<=Y.size();++j) dp[0][j]=0;
    int U=0,L=0,D=0;
    vector<vector<char>> path(X.size()+1,vector<char>(Y.size()+1,'-'));
    for(int i=1;i<=X.size();++i) for(int j=1;j<=Y.size();++j) {
        U=dp[i-1][j]+Mat[X[i-1]-'A'][3];
        L=dp[i][j-1]+Mat[3][Y[j-1]-'A'];
        D=dp[i-1][j-1]+Mat[X[i-1]-'A'][Y[j-1]-'A'];
        vector<int> comp{L,U,D,0};
        dp[i][j]=comp[0];
        for(int k=1;k<comp.size();++k) dp[i][j]=max(dp[i][j],comp[k]);
    }
    cout<<"-----------------"<<endl;
    cout<<"    ";
    for(int i=0;i<Y.size();++i) cout<<Y[i]<<" ";
    cout<<endl;
    for(int i=0;i<=X.size();++i) {
        if(i>0) {
            cout<<X[i-1]<<":";
            for(int j=0;j<=Y.size();++j) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        else {
            cout<<"  ";
            for(int j=0;j<=Y.size();++j) cout<<dp[i][j]<<" ";
            cout<<endl;
        }
    }
}