    #include "bits/stdc++.h"
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

    void solve(){
        ll N;
        cin>>N;
        vector<pair<ll,ll>> pos(N); 
        map<pair<ll,ll>,ll> check;
        map<pair<ll,ll>,ll> ID;
        multimap<ll,ll> xp,yp;
        rep(i,0,N) {
            cin>>pos[i].first>>pos[i].second;
            check[pos[i]]++;
            ID[pos[i]]=i;
            xp.emplace(pos[i].first,i);
            yp.emplace(pos[i].second,i);
        }
        ll ans=0;
        set<set<ll>> cnt;
        rep(i,0,N-1) rep(j,i+1,N){
            if(pos[i].first!=pos[j].first&&pos[j].second!=pos[i].second){
                ll x1,x2,y1,y2;
                tie(x1,y1)=pos[i];
                tie(x2,y2)=pos[j];
                auto pr1=make_pair(x1,y2);
                auto pr2=make_pair(x2,y1);
                if(check[pr1]==0||check[pr2]==0) continue;
                ll ID3=ID[pr1];
                ll ID4=ID[pr2];
                set<ll> ins{i,j,ID3,ID4};
                if(ins.size()!=4) continue;
                if(cnt.find(ins)==cnt.end()) {
                    ans++;  
                    cnt.emplace(ins);
                }
            }
            else if(pos[i].first==pos[j].first){
                ll x3,y3;
                auto left=yp.lower_bound(min(pos[i].second,pos[j].second));
                if(left==yp.end()) continue;
                auto right=yp.upper_bound(min(pos[i].second,pos[j].second));
                while(true){
                    if(left==right) break;
                    auto now=*left;
                    ll ID3=now.second;
                    tie(x3,y3)=pos[ID3];
                    auto pr=make_pair(x3,max(pos[i].second,pos[j].second));
                    if(check.find(pr)==check.end()) continue;
                    ll ID4=ID[pr];
                    set<ll> ins{i,j,ID3,ID4};
                    if(ins.size()!=4) continue;
                    if(cnt.find(ins)==cnt.end()) {
                        ans++;  
                        cnt.emplace(ins);
                        break;
                    }
                    left++;
                }
            }
            else if(pos[i].second==pos[j].second){
                ll x3,y3;
                auto left=xp.lower_bound(min(pos[i].first,pos[j].first));
                if(left==yp.end()) continue;
                auto right=yp.upper_bound(min(pos[i].first,pos[j].first));
                while(true){
                    if(left==right) break;
                    auto now=*left;
                    ll ID3=now.second;
                    tie(x3,y3)=pos[ID3];
                    auto pr=make_pair(y3,max(pos[i].first,pos[j].first));
                    if(check.find(pr)==check.end()) continue;
                    ll ID4=ID[pr];
                    set<ll> ins{i,j,ID3,ID4};
                    if(ins.size()!=4) continue;
                    if(cnt.find(ins)==cnt.end()) {
                        ans++;  
                        cnt.emplace(ins);
                        break;
                    }
                    left++;
                }
            }

        }
        cout<<ans<<endl;
    }


    int main(void){
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(15);
        solve();
    }
