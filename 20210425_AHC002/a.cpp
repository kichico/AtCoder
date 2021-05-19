#include "bits/stdc++.h"
#include <fstream>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
typedef vector<vector<ll>> grid;
typedef vector<vector<bool>> gridbool;
#define ALL(x) x.begin(),x.end()
#define rep(i,start,N) for(ll i=start;i<N;++i)

const ll MOD=1e9+7;
//#######################################################################
vector<vector<ll>> input(ll N, ll width){
    string str;
    vector<vector<ll>> vec(N,vector<ll>(width));
    for(ll i=0;i<N;++i){
        cin>>str;
        reverse(ALL(str));
        for(ll j=0;j<width;++j){
            vec[i][j]=str.back();
            str.pop_back();
        }
    }
    return vec;
}
void op(vector<ll> vec){
    ll size=(ll)vec.size();
    for(ll i=0;i<size-1;++i) cout<<vec[i]<<" ";
    cout<<vec.back()<<endl;
}

void op(vector<vector<ll>> vec){
    ll height=(ll)vec.size();
    ll width=(ll)vec[0].size();
    for(ll i=0;i<height;++i) {
        for(ll j=0;j<width-1;++j) cout<<vec[i][j]<<" ";
        cout<<vec[i].back()<<endl;
    }
}
//########################################################################


vector<ll> dx{1,0,-1,0};
vector<ll> dy{0,1,0,-1};
vector<char> way;

pair<ll,ll> cellcheck(ll x, ll y, vector<vector<pair<ll,ll>>> &point,set<ll> &visited){
    ll checker=0;
    ll available=0,max_ava=0;
    ll maxp=-1;
    rep(i,0,4) {
            ll next_x=x+dx[i];
            ll next_y=y+dy[i];
            if(next_x<0||next_y<0||next_x>=50||next_y>=50) {
                checker++;
                continue;
            }
            auto next=point[y+dy[i]][x+dx[i]];
            if(visited.count(next.second)!=0) checker++;
    }
    if(checker==4) return make_pair(0,maxp);
    rep(i,0,4) {
        ll next_x=x+dx[i];
        ll next_y=y+dy[i];
        if(next_x<0||next_y<0||next_x>=50||next_y>=50) continue;
        auto next=point[y+dy[i]][x+dx[i]];
        if(visited.count(next.second)!=0) continue;
        else available++;
        if(maxp<next.first) maxp=next.first;
    }
    return make_pair(available,maxp);
}


//if(!ifs) {cout<<"Oops"<<endl; getchar();}
int solve(){
    ll x0,y0;
    cin>>y0>>x0;
    grid tile(50,vector<ll>(50,-1));
    vector<vector<pair<ll,ll>>> point(50,vector<pair<ll,ll>>(50));
    set<ll> visited;
    //getchar();
    vector<vector<pair<ll,ll>>> tilelist(50*50);
    rep(i,0,50) rep(j,0,50) {
        cin>>tile[i][j];
    }
    rep(i,0,50) rep(j,0,50) {
        cin>>point[i][j].first;
        point[i][j].second=tile[i][j];
    }
    ll nowtile,bestway;
    nowtile=point[y0][x0].second;
    visited.insert(nowtile);
    ll sum=0;
    while(true){
        bestway=-1;
        ll p=-1;
        ll checker=0;
        rep(i,0,4) {
            ll next_x=x0+dx[i];
            ll next_y=y0+dy[i];
            if(next_x<0||next_y<0||next_x>=50||next_y>=50) {
                checker++;
                continue;
            }
            auto next=point[y0+dy[i]][x0+dx[i]];
            if(visited.count(next.second)!=0) checker++;
        }
        if(checker==4) break;
        vector<pair<ll,pair<ll,ll>>> cand;
        rep(i,0,4) {
            ll next_x=x0+dx[i];
            ll next_y=y0+dy[i];
            if(next_x<0||next_y<0||next_x>=50||next_y>=50) continue;
            auto next=point[y0+dy[i]][x0+dx[i]];
            if(visited.count(next.second)!=0) continue;
            cand.emplace_back(make_pair(i,make_pair(next_y,next_x)));
        }
        pair<ll,pair<ll,ll>> maxpr=make_pair(-1,make_pair(0,0));
        rep(i,0,cand.size()){
            auto pr=cellcheck(cand[i].second.second,cand[i].second.first,point,visited);
            if(maxpr.second.first<=pr.first&&maxpr.second.second<=pr.second) maxpr=make_pair(cand[i].first,pr);
        }
        bestway=maxpr.first;
        if(bestway==-1) break;
        sum+=p;
        switch (bestway) {
        case 0:
            way.push_back('R');
            break;
        case 1:
            way.push_back('D');
            break;
        case 2:
            way.push_back('L');
            break;
        case 3:
            way.push_back('U');
            break;
        default:
            break;
        }
        visited.insert(point[y0+dy[bestway]][x0+dx[bestway]].second);
        x0+=dx[bestway];
        y0+=dy[bestway];
        //cout<<"now=>"<<y0<<","<<x0<<endl;
    }
    for(auto x:way) cout<<x;
    cout<<endl;
    return 0;

}

int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}