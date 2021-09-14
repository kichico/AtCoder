#include "bits/stdc++.h"
#include <chrono>
using namespace std;
using ll=int64_t;
using ld=long double;
using ull=unsigned long long;
#define ALL(x) x.begin(),x.end()
#define rep(iter,from,to) for(ll iter=from;iter<to;++iter)
#define fore(variable,container) for(auto variable:container)
#define forc(variable,container) for(auto variable:container) cout<<variable<<endl;

const ll MOD=1e9+7;
const ll INF=1e17;
//#######################################################################
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

void twoText(bool identifier, string outTrue, string outFalse) {
    if (identifier) cout << outTrue << endl;
    else cout << outFalse << endl;
}

void twoText(bool identifier){
    if(identifier) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

void counter(ll& num,ll& increaser,bool checker){
    if(checker) num+=increaser;
}

template <class T>
struct grid{
    vector<vector<T>> field;
    grid(ll height,ll width){field=vector<vector<T>>(height,vector<T>(width,(T)0));}
    void input(){rep(i,0,field.size()) rep(j,0,field[i].size()) cin>>field[i][j];}
};

//#########################################################################

class Random {
	int create_int_rand(std::mt19937 mt, int xmin, int xmax);
	double create_double_rand(std::mt19937 mt, double xmin, double xmax);
public:
	int random(int N);
	int random(int Nmin, int Nmax);
	double random(double D);
	double random(double Dmin, double Dmax);
};


int Random::random(int N) {
	std::random_device rnd;
	std::mt19937 mt(rnd());
	return create_int_rand(mt, 0, N);
}
int N, A[201010], B[201010];

void solve(){
    N=100000;
    //cin>>N;
    Random random;
    rep(i,1,N+1) A[i]=random.random(1);
    ll M=0;
    auto start=chrono::system_clock::now();
    rep(i,1,N+1){
        ll now=N-i-1;
        int other = 0;
		for (int x = i * 2; x <= N; x += i) if (B[x]) other++;
		if (other % 2 != A[i]) B[i] = 1;
    }
    vector<ll> ans;
    rep(i,1,N+1) if(B[i]) ans.emplace_back(i+1);
    auto end=chrono::system_clock::now();
    auto elapsed=end-start;
    auto msec=chrono::duration_cast<chrono::milliseconds>(elapsed).count();
    cout<<"elapsed time(msec):"<<msec<<endl;
    cout<<ans.size()<<endl;
    for(auto x:ans) cout<<x<<" ";
    cout<<endl;
}


int main(void){
    std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
	std::cout << std::fixed << std::setprecision(15);
	solve();
}
