#include <iostream>
#include <vector>

int main(void){
    int N,M,T,now;
    std::cin>>N>>M>>T;
    std::vector<int>start(M),end(M);
    bool cafe=false;
    int time=0;
    for(int i=0;i<M;i++){
        std::cin>>start[i]>>end[i];
    }
    int i=0;
    now=N;
    while(true){
        if(start[i]==time) cafe=true;
        if(!cafe) --now;
        if(now<=0) break;
        if(cafe) {
            if(now<N) ++now;
        }
        if(end[i]==time+1) {
            ++i;
            cafe=false;
        }
        time++;
        //std::cout<<time<<" "<<cafe<<" "<<now<<std::endl;
        if(time==T) break;
    }
    if(now<=0) std::cout<<"No"<<std::endl;
    else std::cout<<"Yes"<<std::endl;
    return 0;
}