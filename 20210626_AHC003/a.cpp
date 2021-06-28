#include "bits/stdc++.h"
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
template <class T>
using grid=vector<vector<T>>;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)

#ifndef ONLINE_JUDGE
#define local true;
#endif

const ll MOD = 1e9 + 7;
const ll INF = 1e17;
//#######################################################################
vector<vector<ll>> input(ll N, ll width) {
    string str;
    vector<vector<ll>> vec(N, vector<ll>(width));
    for (ll i = 0; i < N; ++i) {
        cin >> str;
        reverse(ALL(str));
        for (ll j = 0; j < width; ++j) {
            vec[i][j] = str.back();
            str.pop_back();
        }
    }
    return vec;
}
void op(vector<ll> vec) {
    ll size = (ll)vec.size();
    for (ll i = 0; i < size - 1; ++i) cout << vec[i] << " ";
    cout << vec.back() << endl;
}

void op(vector<vector<ll>> vec) {
    ll height = (ll)vec.size();
    ll width = (ll)vec[0].size();
    for (ll i = 0; i < height; ++i) {
        for (ll j = 0; j < width - 1; ++j) cout << vec[i][j] << " ";
        cout << vec[i].back() << endl;
    }
}
//########################################################################

struct in{
    ll len;
    string str;
    ll num;
};

bool compare(const in& fr, const in& se){
    if(fr.len!=se.len) return fr.len<se.len;
    else return fr.num>se.num;
}

int solve(){
    ll N,M;
    cin>>N>>M;
    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> pick(0,M-1);
    vector<in> dict;
    set<string> checker;
    in inserter;
    rep(i,0,M){
        string s;
        cin>>s;
        if(checker.count(s)==0){
            inserter.len=s.size();
            inserter.str=s;
            inserter.num=1;
            checker.insert(s);
            dict.push_back(inserter);
        }
        else {
            rep(c,0,dict.size()) if(dict[c].str==s) {dict[c].num++; break;}
        }
    }
    grid<char> res(N,vector<char>(N,'.'));
    sort(ALL(dict),compare);
    //if(local) for(auto a:dict) cout<<a.str<<" "<<a.num<<endl;
    ll iter=0;
    for(ll i=0;i<N;++i) {
        ll cnt=0;
        ll start=0;
        while(true) {
            rep(j,0,dict[iter].len) {
                if(cnt>=N) break;
                res[i][start+j]=dict[iter].str[j];
                cnt++;
            }
            iter++;
            if(iter>=dict.size()) iter-=dict.size();
            start+=dict[iter].len;
            if(cnt>=N-1) break;
        }
    }
    uniform_int_distribution<> rand7(0, 7);
    vector<char> alpha{'A','B','C','D','E','F','G','H'}; 
    rep(i,0,N) {
        rep(j,0,N) {
            if(res[i][j]=='.') res[i][j]=alpha[rand7(mt)];
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
